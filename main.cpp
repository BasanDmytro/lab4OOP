//
//  main.cpp
//  lab4OOP
//
//  Created by Дима Басан on 28.04.16.
//  Copyright © 2016 Дима Басан. All rights reserved.
//

#include <iostream>
#include "ContainerVector.hpp"
#include <vector>

using namespace std;

template <class T>
void print(T element) {
    cout << element << " ";
}

int main(int argc, const char * argv[]) {
    
    ContainerVector<int> testElement;

    testElement.push_back(1);
    testElement.push_back(7);
    testElement.push_back(3);
    testElement.push_back(4);
    testElement.push_back(3);
    testElement.push_back(9);
    
    cout << "Size of testElement" << testElement.size() << endl;
    
    cout << "First element = " << testElement.at(0) << endl;
    
    cout << "Last element" << testElement.back() << endl;
    
    if (is_sorted(testElement.begin(), testElement.end())) {
        cout << "ContainerVector testElement is sorted" << endl;
    } else {
        cout << "ContainerVector testElement is not sorted" << endl;
    }
 
    auto hasValue = find(testElement.begin(), testElement.end(), 7);
    
    if (hasValue != testElement.end()) {
        cout << "testElement has value: " << "7" << '\n';
    } else {
        cout << "testElement hasn't value: " << "7" << '\n';
    }
    
    long countOfElment = count(testElement.begin(), testElement.end(), 3);
    
    cout << "Count of element(3) in testElement" << countOfElment << endl;
    
    cout << "Print testElement" << endl;
    for_each(testElement.begin(), testElement.end(), print<int>);
    
    return 0;
}
