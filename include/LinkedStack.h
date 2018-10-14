  /**
   *  Author: Matthew Marinets
   *  Date: 2018-10-13
   *  Copyright (c) 2018.
   */

#ifndef _LINKED_STACK_H
#define _LINKED_STACK_H

#include "LinkedList.h"

template <class T>				            // stack element type
class LinkedStack {				            // stack as a linked list
public:
    LinkedStack();				            // constructor
    int size() const;				        // number of items in the stack
    bool empty() const;			            // is the stack empty?
    const T& top() const;                   // the top element
    void push(const T& e);  		        // push element onto stack
    void pop();		                        // pop the stack
private:
    LinkedList<T> data;			            // linked list of elements
    int num_elements;					    // number of elements
};


/// implementation for templated class
template <class T>
LinkedStack<T>::LinkedStack()
: num_elements(0) {
    data = LinkedList<T>();
}


template <class T>
bool LinkedStack<T>::empty() const
{ return num_elements == 0; }


template <class T>
const T& LinkedStack<T>::top() const {
    return data.front();
}


template <class T>
void LinkedStack<T>::push(const T& e) {
    ++num_elements;
    data.addFront(e);
}


template <class T>
void LinkedStack<T>::pop() {
    --num_elements;
    data.removeFront();
}


template <class T>
int LinkedStack<T>::size() const {
    return num_elements;
}

#endif /* _LINKED_STACK_H */