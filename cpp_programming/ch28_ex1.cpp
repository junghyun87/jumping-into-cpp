//
//  ch28_ex1.cpp
//  cpp_programming
//
//  Created by Junghyun Kwon on 1/15/16.
//  Copyright © 2016 Junghyun Kwon. All rights reserved.
//

#include "ch28_ex1.hpp"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int printScores(fstream &file){
    file.seekg(0,ios::beg);
    int value;
    while(!file.eof()){
        if(!file.read(
                     reinterpret_cast<char*>(&value),sizeof(value))){
            cout << "error reading from file" << endl;
            break;
        }
        cout << value << endl;
    }
    return 0;
}

int main(){
    fstream file(
                 "/Users/junghyunkwon/Documents/cpp_programming/cpp_programming/highscores2.txt",
                 ios::binary|ios::in|ios::out
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
    while (!file.eof()){
        if (! file.read(reinterpret_cast<char*>(&cur_score),sizeof(cur_score))){
            cout << "Error reading from file." << endl;
            break;
        }
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
    while(file.read(reinterpret_cast<char*>(&cur_score),sizeof(cur_score)))
    {
        scores.push_back(cur_score);
    }
    
    if( !file.eof()){
        cout << "Bad score/read";
        return 0;
    }
    
    file.clear();
    
    file.seekp(pre_score_pos);
    
    file.write(reinterpret_cast<char*>(&new_high_score),
               sizeof(new_high_score));

    
    for (vector<int>::iterator itr = scores.begin();
         itr!=scores.end();
         ++itr)
    {
        file.write(reinterpret_cast<char*>(&*itr), sizeof(*itr));
    }
    
    printScores(file);
    
}