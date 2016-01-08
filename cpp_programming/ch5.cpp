//
//  ch5.cpp
//  cpp_programming
//
//  Created by Junghyun Kwon on 1/7/16.
//  Copyright © 2016 Junghyun Kwon. All rights reserved.
//

#include "ch5.hpp"
#include <string>
#include <iostream>

using namespace std;

int example_ch5(){
    string result;
    if (result == ""){
        cout << "init value of string is empty string." << endl;
    }
    for(int i=0, j=0;i<3;i++){
        j = i + 1;
        cout << j << endl;
    }
    return 0;
}