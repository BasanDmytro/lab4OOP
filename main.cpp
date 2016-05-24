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
    
    ContainerVector<int> testContainerVector;

    testContainerVector.push_back(1);
    testContainerVector.push_back(7);
    testContainerVector.push_back(3);
    testContainerVector.push_back(4);
    testContainerVector.push_back(3);
    testContainerVector.push_back(9);
    
    cout << "Size of testContainerVector = " << testContainerVector.size() << endl << endl;
    
    cout << "First element = " << testContainerVector.at(0) << endl << endl;;
    
    cout << "Last element = " << testContainerVector.back() << endl << endl;;
    
    if (is_sorted(testContainerVector.begin(), testContainerVector.end())) {
        cout << "ContainerVector testContainerVector is sorted" << endl << endl;
    } else {
        cout << "ContainerVector testContainerVector is not sorted" << endl << endl;
    }
 
    auto hasValue = find(testContainerVector.begin(), testContainerVector.end(), 7);
    
    if (hasValue != testContainerVector.end()) {
        cout << "testContainerVector has value: " << "7" << endl << endl;
    } else {
        cout << "testContainerVector hasn't value: " << "7" << endl << endl;
    }
    
    long countOfElment = count(testContainerVector.begin(), testContainerVector.end(), 3);
    
    cout << "Count of number(=3) in testContainerVector = " << countOfElment << endl << endl;
    
    cout << "Print testContainerVector" << endl;
    for_each(testContainerVector.begin(), testContainerVector.end(), print<int>);
    
    return 0;
}
