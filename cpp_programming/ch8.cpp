//
//  ch8.cpp
//  cpp_programming
//
//  Created by Junghyun Kwon on 1/8/16.
//  Copyright © 2016 Junghyun Kwon. All rights reserved.
//

#include "ch8.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void ex1(){
    srand(time(NULL));
    int numOfHeads=0,numOfTails=0;
    while(1){
        cout << "Toss the coin (press t) or end the game (press e): ";
        string choice;
        cin >> choice;
        if (choice == "t"){
            int toss = rand()%2;
            if (toss == 0){
                cout << "Head!" << endl;
                numOfHeads++;
            } else{
                cout << "Tail!" << endl;
                numOfTails++;
            }
        } else if (choice == "e"){
            break;
        }
        cin.ignore();
        
    }
    cout << "# of Heads: " << numOfHeads << ", # of tails: " << numOfTails << endl;
    
}

int main(){
    ex1();
}