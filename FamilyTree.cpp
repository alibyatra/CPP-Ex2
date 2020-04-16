#include <iostream>
#include <string.h>
#include "FamilyTree.hpp"
#include <string>
#include <exception>
#include <bits/stdc++.h>
using namespace std;
 namespace family{

  node::node(string name)
  {
    this->name = name;
    this->left = NULL;
    this->right = NULL;
 }


 Tree::Tree(): root(NULL){}


 Tree::Tree(string name)
 {
    this->root = new node(name);;
 }


 Tree& Tree::addFather(string son, string father)
 {
    return *this;
 }
 


 Tree& Tree::addMother(string son, string mother)
 {
    return *this;
 }

 

 string Tree::relation(string name)
 {  
    return "relation";    
 }



string Tree::find(string a)
 {
    if (a.compare("uncle") == 0)
    {
         return  string("the tree can't handle the uncle relation");
    }
    return "find";
 }


 void Tree::display()
 {
    cout << "display"<< endl; 
 }


 string Tree::remove(string name){
     return "remove" ;
 }
}