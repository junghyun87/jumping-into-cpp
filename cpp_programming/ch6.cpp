//
//  ch6.cpp
//  cpp_programming
//
//  Created by Junghyun Kwon on 1/13/16.
//  Copyright © 2016 Junghyun Kwon. All rights reserved.
//

#include "ch6.hpp"
#include <iostream>
#include <string>

using namespace std;


void getLyrics();

void printMenu_ch6(){
    int select;
    while(1){
        cout << "Select one" << endl;
        cout << "menu 1" << endl;
        cout << "menu 2" << endl;
        cout << "menu 3" << endl;
        cout << "exit 0" <<endl;
        cout << "choose: ";
        cin >> select;
        if (select == 0){
            break;
        }else if(select == 1){
            getLyrics();
        }
        
    }
}

void getLyrics(){
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
