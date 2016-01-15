//
//  ch25_class.hpp
//  cpp_programming
//
//  Created by Junghyun Kwon on 1/14/16.
//  Copyright © 2016 Junghyun Kwon. All rights reserved.
//

#ifndef ch25_class_hpp
#define ch25_class_hpp

#include <stdio.h>

#endif /* ch25_class_hpp */
namespace webeng{
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
}