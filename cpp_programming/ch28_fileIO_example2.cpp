//
//  ch28_fileIO_example2.cpp
//  cpp_programming
//
//  Created by Junghyun Kwon on 1/15/16.
//  Copyright © 2016 Junghyun Kwon. All rights reserved.
//

#include "ch28_fileIO_example2.hpp"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int example2_ch28(){
    fstream file(
        "/Users/junghyunkwon/Documents/cpp_programming/cpp_programming/highscores.txt",
                 ios::in|ios::out
                 );
    if (!file.is_open()) {
        cout << "Could not open file!" << '\n';
        return 0;
    }
    int new_high_score;
    cout << "Enter a new high score: ";
    cin >> new_high_score;
    
    streampos pre_score_pos = file.tellg();
    int cur_score;
    while (file >> cur_score){
        if (cur_score < new_high_score){
            break;
        }
        pre_score_pos = file.tellg();
    }
    
    if (file.fail() && !file.eof())
    {
        cout << "Bad score/read";
        return 0;
    }
    file.clear();
    
    file.seekg(pre_score_pos);
    
    vector<int> scores;
    while( file>> cur_score)
    {
        scores.push_back(cur_score);
    }
    
    if( !file.eof()){
        cout << "Bad score/read";
        return 0;
    }
    
    file.clear();
    
    file.seekp(pre_score_pos);
    
    if (pre_score_pos != streampos(0)){
        file << endl;
    }
     
    file << new_high_score << endl;
    
    for (vector<int>::iterator itr = scores.begin();
         itr!=scores.end();
         ++itr)
    {
        file << *itr << endl;
    }
    return 0;
}