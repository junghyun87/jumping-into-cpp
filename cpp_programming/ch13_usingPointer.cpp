//
//  ch13_usingPointer.cpp
//  cpp_programming
//
//  Created by Junghyun Kwon on 1/14/16.
//  Copyright © 2016 Junghyun Kwon. All rights reserved.
//

#include "ch13_usingPointer.hpp"
#include <iostream>

using namespace std;


void enterNamesPointer(string *firstName, string *lastName){
    cout << "firstName?: ";
    getline(cin, *firstName, '\n');
    cout << "listName?: ";
    getline(cin, *lastName, '\n');
}

void enterNamesRef(string &firstName, string &lastName){
    cout << "firstName?: ";
    getline(cin, firstName, '\n');
    cout << "listName?: ";
    getline(cin, lastName, '\n');
}

void ex1_ch13(){
    string firstName, lastName;
    enterNamesPointer(&firstName, &lastName);
    cout << "Welcome " << firstName << " " << lastName << endl;
    
    enterNamesRef(firstName, lastName);
    cout << "Welcome " << firstName << " " << lastName << endl;
}
