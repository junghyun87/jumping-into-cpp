//
//  ch11.cpp
//  cpp_programming
//
//  Created by Junghyun Kwon on 1/14/16.
//  Copyright © 2016 Junghyun Kwon. All rights reserved.
//

#include "ch11.hpp"
#include <iostream>
#include <string>

using namespace std;

struct UserInfo{
    string name;
    string addr;
    string tel;
};

void ex1_ch11(){
    UserInfo uInfo;
    cout << "name?: ";
    getline(cin,uInfo.name,'\n');
    cout << "addr?: ";
    getline(cin,uInfo.addr,'\n');
    cout << "tel?: ";
    getline(cin,uInfo.tel,'\n');
    
    cout << uInfo.name << endl;
    cout << uInfo.addr << endl;
    cout << uInfo.tel << endl;
}

