//
//  ch28_fileIO_example1.cpp
//  cpp_programming
//
//  Created by Junghyun Kwon on 1/15/16.
//  Copyright © 2016 Junghyun Kwon. All rights reserved.
//

#include "ch28_fileIO_example1.hpp"
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

int example1_ch28(){
    ifstream file_reader("/Users/junghyunkwon/Documents/cpp_programming/cpp_programming/highscores.txt");
    if(!file_reader.is_open()){
        cout <<"Could not open file!" << '\n';
    }
    vector<int> scores;
    
    for(int i=0;i<10;i++){
        int score;
        file_reader >> score;
        scores.push_back(score);
    }
    return 0;
}