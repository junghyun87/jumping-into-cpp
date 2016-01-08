//
//  ch19.cpp
//  cpp_programming
//
//  Created by Junghyun Kwon on 1/8/16.
//  Copyright © 2016 Junghyun Kwon. All rights reserved.
//

#include "ch19.hpp"
#include <string>
#include <iostream>

using namespace std;

int example_ch19(){
    string input;
    cout << "enter a string: ";
    getline(cin,input,',');
    cout << "Typed: " << '\n' << input;
    cout << cin.get();
    return 0;
}