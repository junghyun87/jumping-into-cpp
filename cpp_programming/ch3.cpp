//
//  ch3.cpp
//  cpp_programming
//
//  Created by Junghyun Kwon on 1/7/16.
//  Copyright © 2016 Junghyun Kwon. All rights reserved.
//

#include "ch3.hpp"
#include <iostream>
#include <string>
using namespace std;

void example(){
    int thisisanum;
    cout <<"enter a num:";
    cin >> thisisanum;
    cout << "You entered: " << thisisanum << "\n";
    

    string str;
    cout <<"enter a string:";
    cin >> str;
    cout << "You entered: " << str << "\n";
    cin.get();
    
    string my_string;
    cout <<"enter a string: ";
    getline(cin,my_string,',');
    cout << "You entered: " << my_string << endl;
    cout << cin.get();
    
}

void printMyName(){
    string name;
    cout << "Enter your name:";
    getline(cin, name, '\n');
    cout << "Your name is " << name << endl;
}

void plusTwoNums(){
    int num1;
    int num2;
    cout << "Enter a number:";
    cin >> num1;
    cout << "Enter next number:";
    cin >> num2;
    cout << "The sum is: " << num1+num2 << endl;
}

void divided(){
    float num1, num2;
    cin >> num1;
    cin >> num2;
    cout << num1/num2 << endl;
}

int main(){
    divided();
}