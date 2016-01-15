//
//  ch29_template.cpp
//  cpp_programming
//
//  Created by Junghyun Kwon on 1/15/16.
//  Copyright © 2016 Junghyun Kwon. All rights reserved.
//

#include "ch29_template.hpp"
#include <iostream>
#include <vector>

using namespace std;


template <typename T>
T vectorSum(vector<T> &v){
    
    //http://stackoverflow.com/questions/5192874/question-about-vector-iterator-in-template-functions
    //This tells the compiler that vector<T>::iterator should be treated as a type,
    //something it can't assume since iterator is dependent on what T is.
    T result = 0;
    for(typename vector<T>::iterator iter=v.begin(),
        end = v.end(); iter != end;++iter){
        result+= *iter;
    }
    return result;
}

int ex1_ch29(){
    vector<int> values;
    values.push_back(1);
    values.push_back(2);
    values.push_back(3);
    values.push_back(4);
    int result =0;
    result = vectorSum(values);
    cout << result << endl;
    
    vector<float> values_f;
    values_f.push_back(1.5);
    values_f.push_back(2.5);
    values_f.push_back(3.5);
    values_f.push_back(4.7);
    float result_f =0;
    result_f = vectorSum(values_f);
    cout << result_f << endl;
    
    return 0;
}
//
//vector<int>::iterator iter = v_scores.begin();
//for(vector<int>::iterator end=v_scores.end();
//    iter!=end;++iter){
//    if (*iter < score){
//        break;
//    }
//}
