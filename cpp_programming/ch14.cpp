//
//  ch14.cpp
//  cpp_programming
//
//  Created by Junghyun Kwon on 1/8/16.
//  Copyright © 2016 Junghyun Kwon. All rights reserved.
//

#include "ch14.hpp"
#include <iostream>

using namespace std;

void myfunc(int **val, int sizex, int sizey){
    for(int i =0;i<sizex;i++){
        for (int j=0;j<sizey;j++){
            cout << *(*(val+i)+j) << endl;
        }
    }
}

int example_ch14(){
    int **x = new int*[3];
    for(int i = 0;i<3;i++){
        x[i] = new int[5];
        for (int j=0;j<5;j++){
            x[i][j] = j;
        }
    }
    
    myfunc(x, 3, 5);
    return 0;
}