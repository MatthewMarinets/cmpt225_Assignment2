  /**
   *  Author: Matthew Marinets
   *  Date: 2018-10-13
   *  Copyright (c) 2018.
   */

#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

template <class T>
struct Node {				        // a node in a list of strings
    T elem;				            // element value
    Node<T>* next;				    // next item in the list
};

template <class T>
class LinkedList {			        // a linked list of strings
public:
    LinkedList();				    // empty list constructor
    ~LinkedList();			        // destructor
    bool empty() const;				// is list empty?
    const T& front() const;	        // get front element
    void addFront(const T& e);	    // add to front of list
    void removeFront();				// remove front item list
private:
    Node<T>* head;				    // pointer to the head of list
};


/// implementation for templated class
template <class T>
LinkedList<T>::LinkedList()			// constructor
: head(NULL) {  }


template <class T>
LinkedList<T>::~LinkedList()			// destructor
    { while (!empty()) removeFront(); }


template <class T>
bool LinkedList<T>::empty() const			// is list empty?
    { return head == NULL; }


template <class T>
const T& LinkedList<T>::front() const		// get front element
    { return head->elem; }


template <class T>
void LinkedList<T>::addFront(const T& e) {	// add to front of list
    Node<T>* v = new Node<T>;
    v->elem = e;
    v->next = head;
    head = v;
}


template <class T>
void LinkedList<T>::removeFront() {
    Node<T>* old = head;
    head = old->next;
    delete old;
}

#endif /* _LINKED_LIST_H */
