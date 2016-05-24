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

template <class T >
class ContainerVector: protected List<T>, protected std::vector<T> {
    
public:
    typedef T                 value_type;
 //   typedef value_type&        reference;
 //   typedef const value_type& const_reference;
 //   typedef value_type*       pointer;
 //   typedef const value_type* const_pointer;
    
    using typename List<T>::Node;
    void push_back(T data);
    bool empty();
    int size();
    void erase(int position);
    void clear();
    
    
    class ConIter {
        Node *p;
    public:
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef T value_type;
        typedef std::ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;

        ConIter();
        ConIter(Node* l) : p(l) { }
        typedef typename List<T>::ListIterator iterator;
        ConIter operator++() {
            p = p != NULL ? p -> next : p;
            return p;
        }

        bool operator==(ConIter other) { return p == other.p; }
        bool operator<(ConIter *other) { return *p < *other; }
        bool operator>(ConIter *other) { return p > *other; }
        bool operator>=(ConIter *other) { return p >= *other; }
        bool operator<=(ConIter *other) { return p <= *other; }
        bool operator=(ConIter other) { p = other.p; return true; }
        bool operator!=(ConIter other) { return p != other.p; }
        void operator+(int count) { for(int i = 0; i < count; i++) ++p;}
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
    T operator[](T pos);
    T at(int pos);
    bool operator=(T value) { std::cout << "error1" << std::endl;}
    bool operator=(bool value) { std::cout << "error1" << std::endl;}
    bool operator-(T value) { std::cout << "error1" << std::endl;}
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
T ContainerVector<T>::operator[](T pos) {
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
T ContainerVector<T>::at(int pos) {
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
