//
//  ch18_STL.cpp
//  cpp_programming
//
//  Created by Junghyun Kwon on 1/14/16.
//  Copyright © 2016 Junghyun Kwon. All rights reserved.
//

#include "ch18_STL.hpp"

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


void registerUser(map<string, string> &addrbook){
    string name, email;
    cout << "name?: ";
    getline(cin,name,'\n');
    cout << "email?: ";
    getline(cin,email,'\n');
    addrbook[name] = email;
}

void removeUser(map<string, string> &addrbook){
    string name;
    cout << "name to remove?: ";
    getline(cin,name,'\n');
    addrbook.erase(name);
}

void updateUser(map<string, string> &addrbook){
    string name;
    cout << "name to update?: ";
    getline(cin,name,'\n');
    map<string, string>::iterator itr = addrbook.find(name);
    if (itr != addrbook.end()){
        string email;
        cout << "update email: ";
        getline(cin,email,'\n');
        addrbook[name] = email;
    }else{
        cout << "no one having such name." << endl;
    }
}

void printUser(map<string,string> &addrbook){
    for(map<string,string>::iterator itr = addrbook.begin(),
        end = addrbook.end();
        itr != end; ++itr){
        cout << itr->first <<", " << itr->second << endl;
    }
}

void ex1_ch18(){
    int choice=0;
    map<string, string> addrbook;
    while(1){
        cout << "Menu" << endl;
        cout << "1. register a user." << endl;
        cout << "2. remove a user." << endl;
        cout << "3. update a user." << endl;
        cout << "4. print users." << endl;
        cout << "0. exit" << endl;
        cout << "choose: ";
        cin >> choice;
        cin.ignore();
        if (choice == 0){
            break;
        } else if(choice == 1){
            registerUser(addrbook);
        } else if(choice == 2){
            removeUser(addrbook);
        } else if(choice == 3){
            updateUser(addrbook);
        } else if(choice==4){
            printUser(addrbook);
        }
    }
}

void updateScores(vector<int> &v_scores,int score){

        vector<int>::iterator iter = v_scores.begin();
        for(vector<int>::iterator end=v_scores.end();
            iter!=end;++iter){
            if (*iter < score){
                break;
            }
        }
        v_scores.insert(iter, score);


}

void showScores(vector<int> &v_scores){
    for(vector<int>::iterator iter = v_scores.begin(),
        end = v_scores.end();iter!=end;++iter){
        cout << *iter << endl;
    }
}

void ex2_ch18(){
    vector<int> v_scores;
    int score;
    while(1){
        cout << "enter new score: ";
        cin >> score;
        cout << "input check: " << score << endl;
        updateScores(v_scores,score);
        showScores(v_scores);
    }
}

int main(){
    ex2_ch18();
}