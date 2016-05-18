//
//  main.cpp
//  lab4OOP
//
//  Created by Дима Басан on 28.04.16.
//  Copyright © 2016 Дима Басан. All rights reserved.
//

#include <iostream>
#include "ContainerVector.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    ContainerVector<int>k;

  //  k.push_back(1);
    k.push_back(2);
    k.push_back(3);
    k.push_back(4);

    cout << k.front() << endl;
    cout << k.back() << endl;
    for (ContainerVector<int>::ConIter p = k.begin(); p != k.end(); ++p) {
        cout << *p << " ";
    }
    cout << endl;
    
    cout << k.size() << endl;
    return 0;
}
