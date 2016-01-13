//
//  ch7.cpp
//  cpp_programming
//
//  Created by Junghyun Kwon on 1/14/16.
//  Copyright © 2016 Junghyun Kwon. All rights reserved.
//

#include "ch7.hpp"
#include <iostream>
#include <string>

using namespace std;

void getLyrics_ch7();

void printMenu_ch7(){
    int select;
    bool breakFlag=true;
    while(breakFlag){
        cout << "Select one" << endl;
        cout << "menu 1" << endl;
        cout << "menu 2" << endl;
        cout << "menu 3" << endl;
        cout << "exit 0" <<endl;
        cout << "choose: ";
        cin >> select;
        switch (select){
            case 0:
                breakFlag = false;
                break;
            case 1:
                getLyrics_ch7();
                break;
        }
        
    }
}

void getLyrics_ch7(){
    string lyrics ="";
    for(int i=99;i>0;i--){
        if(i==1){
            cout << i << " bottle of beer on the wall, " << i << " bottle of beer."<<endl;
            cout << "Take one down and pass it around, no more bottles of beer on the wall." <<endl;
        }else{
            cout << i << " bottles of beer on the wall, " << i << " bottles of beer."<<endl;
            cout << "Take one down and pass it around, " << i-1 << "bottles of beer on the wall." <<endl;
        }
    }
    cout << "No more bottles of beer on the wall, no more bottles of beer." <<endl;
    cout << "Go to the store and buy some more, 99 bottles of beer on the wall." <<endl;
}

int main(){
    printMenu_ch7();
}