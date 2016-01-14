//
//  ch16.cpp
//  cpp_programming
//
//  Created by Junghyun Kwon on 1/14/16.
//  Copyright © 2016 Junghyun Kwon. All rights reserved.
//

#include "ch16.hpp"
#include <iostream>

using namespace std;


int pow(int x, int y){
    if (y == 0){
        return 1;
    }
    return x*pow(x, y-1);
}

void ex1_ch16(){
    cout << pow(3,3) << endl;
    cout << pow(2,10) << endl;
    cout << pow(4,2) << endl;
}
