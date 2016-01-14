//
//  ch17_binaryTree.cpp
//  cpp_programming
//
//  Created by Junghyun Kwon on 1/14/16.
//  Copyright © 2016 Junghyun Kwon. All rights reserved.
//

#include "ch17_binaryTree.hpp"
#include <iostream>

using namespace std;

struct node
{
    int key_value;
    node* p_left;
    node* p_right;
};

node *insert(node* p_tree, int key){
    if (p_tree == NULL){
        node *p_new_tree = new node;
        p_new_tree->p_left = NULL;
        p_new_tree->p_right = NULL;
        p_new_tree->key_value = key;
        return p_new_tree;
    }
    
    if (key <p_tree->key_value){
        p_tree->p_left = insert(p_tree->p_left, key);
    }else{
        p_tree->p_right = insert(p_tree->p_right, key);
    }
    return p_tree;
}

void traverse_tree(node *p_tree){
    if (p_tree == NULL){
        return;
    } else{
        traverse_tree(p_tree->p_right);
        cout << p_tree->key_value << endl;
        traverse_tree(p_tree->p_left);
    }
}

void example1_ch17(){
    node* p_tree = new node;
    p_tree->key_value = 5;
    p_tree->p_right=NULL;
    p_tree->p_left=NULL;
    p_tree=insert(p_tree, 3);
    p_tree=insert(p_tree, 10);
    p_tree=insert(p_tree, 1);
    p_tree=insert(p_tree, 7);
    
    traverse_tree(p_tree);
}


