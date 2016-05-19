//
//  ContainerVector.hpp
//  lab4OOP
//
//  Created by Дима Басан on 02.05.16.
//  Copyright © 2016 Дима Басан. All rights reserved.
//

#ifndef ContainerVector_hpp
#define ContainerVector_hpp

#include "vector.hpp"
#include "list.hpp"
#include <vector>

template <typename T>
class ContainerVector: protected List<T>, protected std::vector<T> {
    
public:
    using typename List<T>::Node;
    void push_back(T data);
    bool empty();
    int size();
    void erase(int position);
    void clear();
    
    class ConIter: protected List<T>::ListIterator {
        Node *p;
    public:
        ConIter();
        ConIter(Node* l) : p(l) { }
        typedef typename List<T>::ListIterator iterator;
        ConIter operator++() {
            p = p != NULL ? p -> next : p;
            return p;
        }
        bool operator==(ConIter other) { return p == other.p; }
        bool operator=(ConIter other) { p = other.p; return true; }
        T operator=(T other) {
            Node* current;
            current -> val = other;
            p = current;
            p -> val = other;
            return p;
        }
        bool operator!=(ConIter other) { return p != other.p; }
   //     void operator+(int count) { for(int i = 0; i < count; i++) p++;}
        T operator*() { if (p) { return p -> val; } return T(); }
    };
    
    ConIter begin() { return ConIter(this -> head); }
    ConIter end() {
        Node* current = this -> head;
        while (current)
            current = current -> next;
        return ConIter(current);
    }
    void erase(ConIter it);
    T back();
    T front();
    T operator[](int pos);
    T at1(int pos);
    T operator=(T value) { this -> val = value; return *this;}
};

template <typename T>
void ContainerVector<T>::push_back(T data) {
    this -> add(data);
}

template <typename T>
bool ContainerVector<T>::empty() {
    if (this -> getSize() == 0) {
        return true;
    } else {
        return false;
    }
}

template <typename T>
int ContainerVector<T>::size() {
    return this -> getSize();
}

template <typename T>
void ContainerVector<T>::erase(int position) {
    this -> remove(position);
}

template <typename T>
void ContainerVector<T>::clear() {
    this -> purge();
}

template <typename T>
void ContainerVector<T>::erase(ConIter it) {
    int pos = 1;
    for (ContainerVector<T>::ConIter i = begin(); i != it; ++i) {
        pos++;
    }
    this -> remove(pos);
}


template <typename T>
T ContainerVector<T>::back() {
    ConIter iterForReturnBack = begin();
    for (int i = 0; i < this -> getSize() - 1; i++) {
        ++iterForReturnBack;
    }
    return *iterForReturnBack;
}

template <typename T>
T ContainerVector<T>::front() {
    return *begin();
}

template <typename T>
T ContainerVector<T>::operator[](int pos) {
    int count = 0;
    ContainerVector<T>::ConIter iter = begin();
    if (pos == 0) {
        return *begin();
    }
    while (count < pos) {
        ++iter;
        count++;
    }
    return *iter;
    
}

template <typename T>
T ContainerVector<T>::at1(int pos) {
    int count = 0;
    ContainerVector<T>::ConIter iter = begin();
    if (pos == 0) {
        return *begin();
    }
    while (count < pos) {
        ++iter;
        count++;
    }
    return *iter;
    
}
#endif /* ContainerVector_hpp */
