#include <stdio.h>
#include <string>
#include<iostream>
using namespace std;
namespace family{

class Tree{
string son;
public:
Tree(string son){
this->son=son;}
Tree addFather(string som,string fathername);
Tree addMother(string son,string mothername);
string relation(string son);
string find(string son);
void display();
bool remove(string son);
};

}