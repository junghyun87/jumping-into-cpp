//
//  ch10.cpp
//  cpp_programming
//
//  Created by Junghyun Kwon on 1/14/16.
//  Copyright © 2016 Junghyun Kwon. All rights reserved.
//

#include "ch10.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int findMaximum(int nums[], int size){
    int maxNum = nums[0];
    for (int i=1;i<size;i++){
        if (nums[i] > maxNum){
            maxNum = nums[i];
        }
    }
    return maxNum;
}

int findMinimum(int nums[], int size){
    int minNum = nums[0];
    for (int i=1;i<size;i++){
        if (nums[i] < minNum){
            minNum = nums[i];
        }
    }
    return minNum;
}

int findAVG(int nums[], int size){
    float sum=0.0;
    for (int i=0;i<size;i++){
        sum += nums[i];
    }
    return sum/size;
    
}

int ex2(){
    int nums[50];
    srand(time(NULL));
    for (int i=0;i<50;i++){
        nums[i] = rand() % 100;
    }
    int maxNum = findMaximum(nums, 50);
    int minNum = findMinimum(nums, 50);
    int avg = findAVG(nums, 50);
    
    cout << maxNum << endl;
    cout << minNum << endl;
    cout << avg << endl;
    return 0;
}