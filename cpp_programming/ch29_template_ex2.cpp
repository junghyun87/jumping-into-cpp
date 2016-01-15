//
//  ch29_template_ex2.cpp
//  cpp_programming
//
//  Created by Junghyun Kwon on 1/15/16.
//  Copyright © 2016 Junghyun Kwon. All rights reserved.
//

#include "ch29_template_ex2.hpp"

#include <iostream>
using namespace std;
using namespace webeng;

template <typename Type> vectorOfAny<Type>::vectorOfAny(){
    vector = new Type[32];
    size = 32;
    currentPointer=0;
}

template <typename Type> vectorOfAny<Type>::~vectorOfAny(){
    delete vector;
}

template <typename Type> vectorOfAny<Type>::vectorOfAny(int size){
    vector = new Type[size];
    this->size = size;
    currentPointer=0;
}

template <typename Type> Type vectorOfAny<Type>::get(int index){
    if (index >= 0){
        return vector[index];
    }
    cout << "get:: out of range" << endl;
    return NULL;
}

template <typename Type> void vectorOfAny<Type>::set(int index, Type value){
    if (index >= 0){
        vector[index] = value;
    }else{
        cout << "set:: out of range" << endl;
    }
}

template <typename Type> void vectorOfAny<Type>::pushback(Type ele){
    if (currentPointer < size){
        vector[currentPointer] = ele;
        currentPointer++;
    }else{
        int newSize = size*2;
        Type *newVector = new Type[newSize];
        for(int i=0;i<size;i++){
            newVector[i]=vector[i];
        }
        delete []vector;
        vector = newVector;
        currentPointer++;
    }
}

template <typename Type> void vectorOfAny<Type>::pushfront(Type ele){
    if (currentPointer<size){
        for(int i=currentPointer;i>0;i--){
            vector[i]=vector[i-1];
        }
        vector[0]=ele;
        currentPointer++;
    }else{
        int newSize = size*2;
        Type *newVector = new Type[newSize];
        for(int i=currentPointer;i>0;i--){
            newVector[i]=vector[i-1];
        }
        delete []vector;
        newVector[0] = ele;
        vector = newVector;
        currentPointer++;
    }
}

template <typename Type> vectorOfAny<Type>& vectorOfAny<Type>::operator=(const vectorOfAny& other){
    if(this == &other){
        return *this;
    }
    
    delete vector;
    vector = new Type[other.size];
    size = other.size;
    for(int i=0;i<size;i++){
        vector[i] = other.vector[i];
    }
    currentPointer = other.currentPointer;
    
    return *this;
}

template <typename Type> vectorOfAny<Type>::vectorOfAny(const vectorOfAny& other)
:size(other.size), currentPointer(other.currentPointer)
{
    vector = new Type[size];
    for(int i=0;i<size;i++){
        vector[i] = other.vector[i];
    }
}



int main(){
    vectorOfAny<int> v1;
    vectorOfAny<int> *v2 = new vectorOfAny<int>;
    vectorOfAny<int> v3(15);
    v1.pushback(1);
    v1.pushfront(3);
    cout << v1.get(1)<<endl; //1
    v2->pushback(10);
    v2->pushfront(20);
    cout << v2->get(1)<<endl; //10
    v3.pushfront(0);
    v3.pushback(5);
    cout << v3.get(1)<<endl; //5
    vectorOfAny<int> v4;
    v4 = v3;
    cout << v4.get(1)<<endl; //5
    vectorOfAny<int> v5(v1);
    cout << v5.get(1) << endl; //1
    
    vectorOfAny<float> v6;
    vectorOfAny<float> *v7 = new vectorOfAny<float>;
    vectorOfAny<float> v8(15);
    v6.pushback(1.3);
    v6.pushfront(3.3);
    cout << v6.get(1)<<endl; //1.3
    v7->pushback(10.8);
    v7->pushfront(20.8);
    cout << v7->get(1)<<endl; //10.8
    v8.pushfront(0);
    v8.pushback(5.9);
    cout << v8.get(1)<<endl; //5.9
    vectorOfAny<float> v9;
    v9 = v8;
    cout << v9.get(1)<<endl; //5.9
    vectorOfAny<float> v10(v6);
    cout << v10.get(1) << endl; //1.3
}
