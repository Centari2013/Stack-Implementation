
// Description: A template Stack class designed to be used with
// any simple C++ type to include floating point, double floating point,
// character, and Boolean.


#include <iostream>
using namespace std;

const int DEFAULTSIZE=100;
template <class T>
        class Stack {
        public:
            Stack();                     // Default Constructor, stack is size 100.
            explicit Stack(int size);    // Constructor, creates stack of size "size"
            Stack(const Stack & Obj);    // Copy constructor
            ~Stack();                    //Destructor
            bool Full();                 // Return true if the stack is full
            bool Empty();                // Return true if the stack is empty
            int Size();                  // Return the size of the stack
            int Number();                // Return the number of elements stored
            T Top();                     // Returns the top element, does not pop it
            bool Push (T item);    // Put an item on the stack
            bool Pop();                  // Pop an item off and display to std out
            Stack& operator= (const Stack<T> &s);
            friend ostream &operator << (ostream & os, Stack<T> &s){
                if(s.Empty()){
                    os << "ERROR: STACK EMPTY. NO ELEMENTS TO REMOVE." << endl;
                }else{
                    os << s.Top();
                    s._stack[s._top - 1] = 0;
                    s._top --;
                    s._number --;
                }
                return os;
            };


        private:
            T * _stack;     // The "stack"
            int _size;      // The number of elements the stack can hold
            int _top;       // Points to the first empty node
            int _number;    // The number of elements in the stack.
        };

template<class T>
Stack<T>::Stack() {
    _size = DEFAULTSIZE;
    _stack = new T[_size];
    _top = 0;
    _number = 0;
}

template<class T>
Stack<T>::Stack(const int size) {
    if(size < 0){
        _size = DEFAULTSIZE;
    }else{
        _size = size;
    }
    _stack = new T[_size];
    _top = 0;
    _number = 0;
}

template<class T>
Stack<T>::Stack(const Stack &Obj) {
    _size = Obj._size;
    _stack = new T[_size];
    _top = Obj._top;
    _number = Obj._number;

    for (int i = 0; i < _size; i++){ //copies each element of Obj to new stack
        _stack[i] = Obj._stack[i];
    }
}

template<class T>
bool Stack<T>::Full() {
    return (_number == _size); //returns true if size of stack equals number of elements in stack, meaning stack is full
}

template<class T>
bool Stack<T>::Empty() {
    return (_number == 0); //returns true if number of elements in stack is 0, meaning stack is empty
}

template<class T>
int Stack<T>::Size() {
    return _size;
}

template<class T>
int Stack<T>::Number() {
    return _number;
}

template<class T>
T Stack<T>::Top() {
    return _stack[_top - 1];
}

template<class T>
bool Stack<T>::Push(const T item) {
    if(Full()){
        cout << "ERROR: STACK OVERFLOW." << endl;
        return false;
    }else{
        _stack[_top] = item;
        _top ++;
        _number ++;
        return true;
    }
}

template<class T>
bool Stack<T>::Pop() {
    if(Empty()){
        cout << "ERROR: STACK EMPTY. NO ELEMENTS TO REMOVE.\n";
        return false;
    }else{
        cout << _stack[_top - 1] << endl;
        _stack[_top - 1] = 0;
        _top --;
        _number --;
        return true;
    }
}

template<class T>
Stack<T>::~Stack() {
    delete [] _stack;
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T> &s) {
    {
        if(this != &s){
            _size = s._size;
            _stack = new T[_size];
            _top = s._top;
            _number = s._number;
            for (int i = 0; i < _size; i++){ //copies each element of Obj to new stack
                _stack[i] = s._stack[i];
            }
        }
        return *this;
    }
}






