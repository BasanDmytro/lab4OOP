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
#include <algorithm>
using namespace std;

bool wayToSort(int i, int j) { return i > j; }

int main(int argc, const char * argv[]) {
    ContainerVector<int>k;

    k.push_back(1);
    k.push_back(7);
    k.push_back(3);
    k.push_back(4);
    
    
    cout << "First element = " << k.at1(0) << endl;

    cout << k.front() << endl;
    cout << k.back() << endl;
    
   // sort(k.begin(), k.end(), greater<int>());
    
    for (ContainerVector<int>::ConIter p = k.begin(); p != k.end(); ++p) {
        cout << *p << " ";
    }
    cout << endl;
    
    cout << k.size() << endl;
    return 0;
}
