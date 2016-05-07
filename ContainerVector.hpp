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
#include <stdio.h>

template <typename T>
class ContainerVector: protected Vector<T>, protected List<T> {
    static List<T> element;
   // friend class ListContainerVector;
public:
    class ListContainerVector {
        T value;
        T begin() {
            element.begin();
        }
        T end() {
            element.end();
        }
    
    };
    
    void push_back(T data) {
        element.add(data);
    }
    
    bool empty() {
       if (element.head == NULL) {
           return true;
       } else {
           return false;
       }
    }
    
    int size() {
        element.getSize();
    }
    
    void erase(int position) {
        element.remove(position);
    }
    
    void clear() {
        element.purge();
    }
    
    
};

#endif /* ContainerVector_hpp */
