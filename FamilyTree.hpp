#ifndef FAMILYTREE_H
#define FAMILYTREE_H
#include<stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

namespace family{

class node
{
public:
    string name;
    node *left; //Father
    node *right; //Mother
    node(string); 
};


class Tree {

    public:

    node* root;

    Tree();
    Tree(string); 
    
    Tree& addFather(string , string); 
    Tree& addMother(string, string); 

    void display();  
    
    string relation(string); 
    string find(string); 
    
    string remove(string node); 

};
}
#endif