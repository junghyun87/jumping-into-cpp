//
//  ch29_template_ex2.hpp
//  cpp_programming
//
//  Created by Junghyun Kwon on 1/15/16.
//  Copyright © 2016 Junghyun Kwon. All rights reserved.
//

#ifndef ch29_template_ex2_hpp
#define ch29_template_ex2_hpp

#include <stdio.h>

#endif /* ch29_template_ex2_hpp */

namespace webeng{
    
    template<typename Type>
    class vectorOfAny{
    public:
        vectorOfAny();
        ~vectorOfAny();
        vectorOfAny(int size);
        Type get(int index);
        void set(int index, Type value);
        void pushback(Type ele);
        void pushfront(Type ele);
        vectorOfAny& operator=(const vectorOfAny& other);
        vectorOfAny(const vectorOfAny& other);
        
    private:
        Type *vector;
        int size;
        int currentPointer;
        
    };
}