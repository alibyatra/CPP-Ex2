#include <iostream>
#include <string.h>
#include "FamilyTree.hpp"
#include <string>
#include <exception>
#include <bits/stdc++.h>
bool static check1 = false ;


using namespace std;
using namespace family;

void Tree::findSon(node *root, node** ptr ,const string son) 
 {
    if(root == NULL) return;
    if(root->name == son)
    {
      *ptr = root;
    }
    else
    {
        Tree::findSon(root->left, ptr ,son );
        Tree::findSon(root->right, ptr ,son );
    }
 }

 Tree& Tree::addFather(string son, string father)
 {
      if (son=="" || father=="")
    {
    throw out_of_range{"Error, there is at least one word empty!"};
    return *this;
    }
     if(this->root==NULL)
    {
    throw out_of_range{"The family tree doesn't exist!"};
        return  *this;
    }
    node *ptr=nullptr;
    findSon(this->root,&ptr ,son);
    if(ptr==NULL)
    {
    throw out_of_range{"the son doesn't exist!"};
        return *this;
    }
     if(ptr->left!=NULL)
    {
    throw out_of_range{"the is already father!"};
        return *this;
    }
    else
    {
        ptr->left=new node(father);
        ptr->left->level=ptr->level+1;
        ptr->left->gender='m';
         this->size++;
    }
    return *this;
 }
 
 Tree& Tree::addMother(string son, string mother)
 {
    if (son=="" || mother=="")
    {
    throw out_of_range{"Error, there is at least one word empty!"};
    return *this;
    }
     if(this->root==NULL)
    {
    throw out_of_range{"The family tree doesn't exist!"};
        return  *this;
    }
    node *ptr=nullptr;
    findSon(this->root,&ptr ,son);
    if(ptr==NULL)
    {
    throw out_of_range{"the son does't exist!"};
        return *this;
    }
    if(ptr->right!=NULL)
    {
    throw out_of_range{"there is already mother!"};
        return *this;
    }
    else
    {
        ptr->right=new node(mother);
        ptr->right->level=ptr->level+1;
        ptr->right->gender='f';
        this->size++;
    }
    return *this;
 }

 string Tree::relation(string relative)
 {
    node *ptr=nullptr;
    findSon(this->root, &ptr , relative);
    if(ptr==NULL)
    {
        return "unrelated" ;
    }
    
    string str=ptr->name;

    if(str.compare(this->root->name)==0 && ptr->level==0)
    {
        return "me .";
    }
    if(ptr->level==1 && str.compare(this->root->right->name)==0)
    {
        return "mother";
    }
    if(ptr->level==1 && str.compare(this->root->left->name)==0)
    {
        return "father";
    }
     if(ptr->level==2 && (str.compare(this->root->left->left->name)==0 ||str.compare(this->root->right->left->name)==0))
    {
        return "grandfather";
    }
     if(ptr->level==2 && (str.compare(this->root->left->right->name)==0 ||str.compare(this->root->right->right->name)==0))
    {
        return "grandmother";
    }
    string relate="";
    if(ptr->level>2)
    {
        
        int h=ptr->level;
        while(h!=2)
        {
            relate=relate+"great-";
            h--;
        }
        if(ptr->gender=='f')
            relate+="grandmother";
        if(ptr->gender=='m')
            relate+="grandfather";
        
    }
    return relate;
 }

string Tree::find(string relation)
{
    int l =relation.length(),i=0;
    
    if(relation.compare("mother")==0||relation.compare("Mother")==0)
    {
        return this->root->right->name;
    }
    if(relation.compare("father")==0||relation.compare("Father")==0)
    {
        return this->root->left->name;
    }
    if(relation.compare("grandmother")==0||relation.compare("Grandmother")==0)
    {
        return this->root->right->right->name;
    }
    if(relation.compare("grandfather")==0||relation.compare("Grandfather")==0)
    {
        return this->root->left->left->name;
    }

     int height=0;
        string str = relation;
        while ((str != "grandmother" ) && (str != "grandfather"))
        {
            if(str.substr(0,6)!=("great-"))
                {
                 throw runtime_error("cannot find the reletion");
                 
                }
            str = str.substr(6,(str.length()-6));
            height++;
        }
        height=height+2;
        
        char gender='m';
        if(str.compare("grandfather")==0)
        {
            gender='m';
        }
        else {
            gender='f';        
        }
        
       node *ptr=nullptr;
       findName(height,this->root,&ptr,gender);
       check1=false;
        if(ptr==NULL)
            throw runtime_error("cannot find the reletion");
       
        return ptr->name;
        
 }

void Tree::findName(int height,node * root,node **ptr ,char gender)
{
    if(root == NULL) return;
    if( root->level == height && root->gender==gender )
    {
        *ptr = root;
        check1 = true ;

    }
    if(!check1)
    {
        Tree::findName(height , root->left , ptr ,gender);
        Tree::findName(height ,  root->right , ptr,gender );
    }
    
}

 void Tree::printFamily(node *root, int space)  
{   
   int COUNT=10;
    if (root == NULL)  
        return;   
    space += COUNT;  
    printFamily(root->right, space);  
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<root->name<<"\n";    
    printFamily(root->left, space);  
}  

 void Tree::display()
 {
    cout << "display Fmaily :\n"<< endl; 
    printFamily(root,0);
   cout << "**********************************" << endl; 
 }

 void Tree::remove(string name)
 {
    node *ptr;
    findSon(this->root,&ptr,name);
    if(ptr!=NULL)
    {
        if (ptr->name == "me")
          throw runtime_error("This function can't give you the " + name + "'s name");
        ptr->left = nullptr;
        ptr->right = nullptr;
        ptr = nullptr;
        delete ptr;
    }
    else 
      throw runtime_error("the Family Tree doesn't exist");
 }