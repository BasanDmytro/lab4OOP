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

template<class Iterator, class Fun>
Fun for_each_my(Iterator first, Iterator last, Fun f) {
    while (first!=last) {
        f(*first);
        ++first;
    }
    return f;
}

int main(int argc, const char * argv[]) {
    
    ContainerVector<int> testContainerVector;
    vector<int> testVector;

    testContainerVector.push_back(1);
    testContainerVector.push_back(7);
    testContainerVector.push_back(3);
    testContainerVector.push_back(4);
    testContainerVector.push_back(3);
    testContainerVector.push_back(9);
    
    testVector.push_back(1);
    testVector.push_back(7);
    testVector.push_back(3);
    testVector.push_back(4);
    testVector.push_back(3);
    testVector.push_back(9);
    
    cout << "Size of testContainerVector = " << testContainerVector.size() << endl << endl;
    
    cout << "First element = " << testContainerVector.at(0) << endl << endl;;
    
    cout << "Last element = " << testContainerVector.back() << endl << endl;;
    
    if (std::is_sorted(testContainerVector.begin(), testContainerVector.end())) {
        cout << "ContainerVector testContainerVector is sorted" << endl << endl;
    } else {
        cout << "ContainerVector testContainerVector is not sorted" << endl << endl;
    }
 
    auto hasValue = std::find(testContainerVector.begin(), testContainerVector.end(), 7);
    
    if (hasValue != testContainerVector.end()) {
        cout << "testContainerVector has value: " << "7" << endl << endl;
    } else {
        cout << "testContainerVector hasn't value: " << "7" << endl << endl;
    }
    
    long countOfElment = std::count(testContainerVector.begin(), testContainerVector.end(), 3);
    
    cout << "Count of number(=3) in testContainerVector = " << countOfElment << endl << endl;
    
    // print containers by for_each
    
    cout << "Print testContainerVector by std::for_each" << endl;
    std::for_each(testContainerVector.begin(), testContainerVector.end(), print<int>);
    cout << endl;
    
    cout << "Print testContainerVector by my for_each" << endl;
    for_each_my(testContainerVector.begin(), testContainerVector.end(), print<int>);
    cout << endl;
    
    cout << "Print testVector by std::for_each" << endl;
    std::for_each(testVector.begin(), testVector.end(), print<int>);
    cout << endl;
    
    cout << "Print testVector by my for_each" << endl;
    for_each_my(testVector.begin(), testVector.end(), print<int>);
    cout << endl;
    
    return 0;
}
