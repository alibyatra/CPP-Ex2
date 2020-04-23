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
    int level;
    char gender;
    int size;
    
    node(string name)
  {
    this->name = name;
    this->left = NULL;
    this->right = NULL;
    this->level=0;
    this->gender='m';
 };
};

class Tree 
{
public:
    node* root;
     int size;
    Tree(string name)
    {
        this->root = new node(name);
        this->size=0;
    };

    void findSon(node *root, node** ptr ,const string son);
    Tree& addFather(string son , string father); 
    Tree& addMother(string son, string mother); 
    void printFamily(node *root, int space);
    void display();
    string relation(string relative);
    void findName(int level,node * root,node **ptr ,char gender);
    string find(string relation); 
    void remove(node** root);
    void remove(string name);
};
}
#endif