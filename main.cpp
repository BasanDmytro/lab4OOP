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
    k.push_back(7);
    
   // cout << k.begin() << endl;
    cout << k.size() << endl;
    return 0;
}
