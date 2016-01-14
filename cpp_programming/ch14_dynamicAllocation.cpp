//
//  ch14_dynamicAllocation.cpp
//  cpp_programming
//
//  Created by Junghyun Kwon on 1/14/16.
//  Copyright © 2016 Junghyun Kwon. All rights reserved.
//

#include "ch14_dynamicAllocation.hpp"
#include <iostream>

using namespace std;

void ex1_ch14(){
    int **p_p_table=NULL;
    p_p_table = new int*[8];
    for (int i=0;i<8;i++){
        p_p_table[i] = new int[9];
    }
    for (int i=0;i<8;i++){
        for (int j=0;j<9;j++){
            p_p_table[i][j] = (i+2)*(j+1);
        }
    }
    
    //display
    for (int i=0;i<8;i++){
        for (int j=0;j<9;j++){
            cout << p_p_table[i][j] << " ";
        }
        cout << endl;
    }
    
    //delete
    for (int i=0;i<8;i++){
        delete [] p_p_table[i];
    }
    delete [] p_p_table;
}


void ex2_ch14(){
    int length, width, height;
    cout << "length: ";
    cin >> length;
    cout << "width: ";
    cin >> width;
    cout << "height: ";
    cin >> height;
    
    int *** p_p_p_table = NULL;
    p_p_p_table = new int**[length];
    for (int i=0;i<length;i++){
        p_p_p_table[i] = new int*[width];
    }
    for (int i=0;i<length;i++){
        for (int j=0;j<width;j++){
            p_p_p_table[i][j] = new int[height];
        }
    }
    for (int i=0;i<length;i++){
        for (int j=0;j<width;j++){
            for (int k=0;k<height;k++){
                p_p_p_table[i][j][k]=i*j*k;
            }
        }
    }
    //display
    for (int i=0;i<length;i++){
        cout << "When i=" << i << ":"<<endl;
        for (int j=0;j<width;j++){
            for (int k=0;k<height;k++){
                cout << p_p_p_table[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }
    
    //delete
    for (int i=0;i<length;i++){
        for (int j=0;j<width;j++){
            delete [] p_p_p_table[i][j];
        }
    }
    
    for (int i=0;i<length;i++){
        delete [] p_p_p_table[i];
    }
    
    delete [] p_p_p_table;
}
