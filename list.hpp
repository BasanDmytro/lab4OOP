//
//  list.hpp
//  lab4OOP
//
//  Created by Дима Басан on 28.04.16.
//  Copyright © 2016 Дима Басан. All rights reserved.
//

#ifndef list_hpp
#define list_hpp

#include <stdio.h>
#include <iostream>

template<typename T>
class List {
protected:
    class Node {
        friend class ListIterator;
    public:
        Node* next;
        T val;
        Node() { }
        Node(T data) : next(NULL), val(data) { }
        ~Node() { }
        bool operator!=(Node* other) { return (val != other -> val && next != other -> next); }
        bool operator==(Node* other) { return (val == other -> val && next == other -> next); }
    };
    Node* head;
    
    friend class Node;
    friend class ListIterator;
public:
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef T value_type;
    typedef std::ptrdiff_t difference_type;
    typedef T* pointer;
    typedef T& reference;
    
    int size;
    List();
    ~List();
    int getSize(); //+
    void add(T data); //+
    void remove(int position); //+
    void purge(); //+
    
    class ListIterator {
        friend class Node;
        Node* p;
    public:
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef T value_type;
        typedef std::ptrdiff_t difference_type;
        typedef const T* pointer;
        typedef const T& reference;
        ListIterator() { }
        ListIterator(Node* l) : p(l) { }
        ListIterator operator++() { //+
            p = p != NULL ? p -> next : p;
            return p;
        }
        bool operator!=(ListIterator other) { return p != other.p; } //+
        bool operator==(ListIterator other) { return p == other.p; } //+
        bool operator<=(ListIterator other) { return p <= other.p; }
        bool operator>=(ListIterator other) { return p >= other.p; }
        bool operator<(ListIterator other) { return p < other.p; }
        bool operator>(ListIterator other) { return p > other.p; }
        ListIterator operator-(ListIterator other) { return (p - other.p);}
        ListIterator operator=(T other) { p -> val = other; return p; }
        T operator*() { return p -> val; } //+
    };
    
    int remove(ListIterator it); //+
    ListIterator begin() { return ListIterator(head); } //+
    ListIterator end() { //+
        Node* current = head;
        while (current)
            current = current -> next;
        return ListIterator(current);
    }
    List* operator=(T other) { this -> swap(other); return *this; } //+
   // bool operator=(T value) { std::cout << "error1" << std::endl;}
    void swap(ListIterator first, ListIterator second) {
        typedef typename std::iterator_traits<ListIterator>::value_type value_type;
        value_type tmp;
        tmp = *first;
        *first = *second;
        *second = tmp;
    }
};

template<class T>
List<T>::List() : head(NULL), size(0) { }

template<class T>
List<T>::~List() {
    Node* current = head;
    Node* to_remove = head;
    while(to_remove != NULL) {
        current = current -> next;
     //   delete to_remove;
        to_remove = current;
    }
    head = NULL;
    size = 0;
}


template<class T>
int List<T>::getSize() {
    return size;
}

template<class T>
void List<T>::add(T data) {
    Node* newNode = new Node;
    if (head == NULL) {
        head = newNode;
        newNode -> next = NULL;
        newNode -> val = data;
    } else {
        Node* current = head;
        while (current -> next != NULL) {
            current = current -> next;
        }
        current -> next = newNode;
        newNode -> next = NULL;
        newNode -> val = data;
    }
    size++;
}

template<class T>
void List<T>::remove(int position) {
    Node* to_del = head;
    if (position == 1) {
        head = head -> next;
        delete to_del;
    } else {
        Node* current = head;
        for (int i = 1; i < position - 1; i++) {
            current = current -> next;
        }
        to_del = current -> next;
        current -> next = to_del -> next;
        delete to_del;
    }
    size--;
}

template<class T>
void List<T>::purge() {
    while(head) {
        Node* tmp = head;
        head = head -> next;
        delete tmp;
    }
    size = 0;
    //    head = NULL;
}

template<class T>
int List<T>::remove(List<T>::ListIterator it) {
    int pos = 1;
    for (List<T>::ListIterator i = begin(); i != it; ++i) {
        pos++;
    }
    remove(pos);
    return pos - 1;
}


#endif /* list_hpp */
