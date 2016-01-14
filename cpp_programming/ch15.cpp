//
//  ch15.cpp
//  cpp_programming
//
//  Created by Junghyun Kwon on 1/14/16.
//  Copyright © 2016 Junghyun Kwon. All rights reserved.
//

#include "ch15.hpp"
#include <iostream>

using namespace std;

struct LinkedItem {
    int id;
    LinkedItem *nextItem;
};

LinkedItem* addNewLinkedItem(LinkedItem* p_head, int id){
    LinkedItem* newItem = new LinkedItem;
    newItem->id = id;
    newItem->nextItem = p_head;
    return newItem;
}

void traverseList(LinkedItem* p_head){
    LinkedItem* p_current = p_head;
    while(p_current){
        cout << p_current->id << " ";
        p_current = p_current->nextItem;
    }
    cout << endl;
}

LinkedItem* removeItem(LinkedItem* p_head, int id){
    LinkedItem* p_current = p_head;
    LinkedItem* p_previous = NULL;
    while(p_current){
        if(p_current->id == id){
            LinkedItem* remaining =NULL;
            if (p_previous == NULL){
                remaining = p_current->nextItem;
                delete p_current;
                return remaining;
            }else{
                p_previous->nextItem = p_current->nextItem;
                delete p_current;
                return p_head;
            }
            
        }else{
            p_previous =p_current;
            p_current = p_current->nextItem;
        }
    }
    cout << "Not found" <<endl;
    return p_head;
}

void ex1_ch15(){
    LinkedItem* p_head = NULL;
    p_head=addNewLinkedItem(p_head,1);
    p_head=addNewLinkedItem(p_head,2);
    p_head=addNewLinkedItem(p_head,3);
    p_head=addNewLinkedItem(p_head,4);
    traverseList(p_head);
    p_head=removeItem(p_head, 2);
    traverseList(p_head);
    p_head=removeItem(p_head, 4);
    traverseList(p_head);
    
}
