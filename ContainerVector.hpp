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
class ContainerVector: public List<T>, protected std::vector<T> {
    
public:
    
    void push_back(T data);
    bool empty();
    int size();
    void erase(int position);
    void clear();
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
    
}



#endif /* ContainerVector_hpp */
