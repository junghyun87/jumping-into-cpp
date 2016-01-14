//
//  ch25_class.cpp
//  cpp_programming
//
//  Created by Junghyun Kwon on 1/14/16.
//  Copyright © 2016 Junghyun Kwon. All rights reserved.
//

#include "ch25_class.hpp"

#include <iostream>
using namespace std;

class vectorOfInt{
public:
    vectorOfInt();
    ~vectorOfInt();
    vectorOfInt(int size);
    int get(int index);
    void set(int index, int value);
    void pushback(int ele);
    void pushfront(int ele);
    vectorOfInt& operator=(const vectorOfInt& other);
    vectorOfInt(const vectorOfInt& other);

private:
    int *vector;
    int size;
    int currentPointer;

};

vectorOfInt::vectorOfInt(){
    vector = new int[32];
    size = 32;
    currentPointer=0;
}

vectorOfInt::~vectorOfInt(){
    delete vector;
}

vectorOfInt::vectorOfInt(int size){
    vector = new int[size];
    this->size = size;
    currentPointer=0;
}

int vectorOfInt::get(int index){
    if (index >= 0){
        return vector[index];
    }
    cout << "get:: out of range" << endl;
    return NULL;
}

void vectorOfInt::set(int index, int value){
    if (index >= 0){
        vector[index] = value;
    }else{
        cout << "set:: out of range" << endl;
    }
}

void vectorOfInt::pushback(int ele){
    if (currentPointer < size){
        vector[currentPointer] = ele;
        currentPointer++;
    }else{
        int newSize = size*2;
        int* newVector = new int[newSize];
        for(int i=0;i<size;i++){
            newVector[i]=vector[i];
        }
        delete []vector;
        vector = newVector;
        currentPointer++;
    }
}

void vectorOfInt::pushfront(int ele){
    if (currentPointer<size){
        for(int i=currentPointer;i>0;i--){
            vector[i]=vector[i-1];
        }
        vector[0]=ele;
        currentPointer++;
    }else{
        int newSize = size*2;
        int* newVector = new int[newSize];
        for(int i=currentPointer;i>0;i--){
            newVector[i]=vector[i-1];
        }
        delete []vector;
        newVector[0] = ele;
        vector = newVector;
        currentPointer++;
    }
}

vectorOfInt& vectorOfInt::operator=(const vectorOfInt& other){
    if(this == &other){
        return *this;
    }
    
    delete vector;
    vector = new int[other.size];
    size = other.size;
    for(int i=0;i<size;i++){
        vector[i] = other.vector[i];
    }
    currentPointer = other.currentPointer;
    
    return *this;
}

vectorOfInt::vectorOfInt(const vectorOfInt& other)
:size(other.size), currentPointer(other.currentPointer)
{
    vector = new int[size];
    for(int i=0;i<size;i++){
        vector[i] = other.vector[i];
    }
}



int main(){
    vectorOfInt v1;
    vectorOfInt *v2 = new vectorOfInt;
    vectorOfInt v3(15);
    v1.pushback(1);
    v1.pushfront(3);
    cout << v1.get(1)<<endl; //1
    v2->pushback(10);
    v2->pushfront(20);
    cout << v2->get(1)<<endl; //10
    v3.pushfront(0);
    v3.pushback(5);
    cout << v3.get(1)<<endl; //5
    vectorOfInt v4;
    v4 = v3;
    cout << v4.get(1)<<endl; //5
    vectorOfInt v5(v1);
    cout << v5.get(1) << endl; //1
}


