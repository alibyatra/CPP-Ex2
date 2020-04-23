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
    int gender;
    string name;
    node *left; //Father
    node *right; //Mother
    node(string); 
};

class Tree 
{
public:
    node* root;

    Tree();
    Tree(string); 
    void findSon(node *root, node** ptr ,const string son);
    Tree& addFather(string son , string father); 
    Tree& addMother(string son, string mother); 
    void printFamily(node *root, int space);
    void display();  
    
    string relation(string);
    string find(string relation, node *root); 
    string find(string relation); 
    void remove(node* name);
    string remove(string name);
};
}
#endif