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
    this->level=0;
 }


 Tree::Tree(): root(NULL){}

 Tree::Tree(string name)
 {
    this->root = new node(name);
 }

void Tree::findSon(node *root, node** ptr ,const string son) 
 {
    if(root == NULL) *ptr=NULL;
    if(root->name == son)
    {
      *ptr = root  ;
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
    throw 'Error, there is at least one word empty!';
    return *this;
    }
     if(this->root==NULL)
    {
        throw 'The family tree doesnt exist!';
        return  *this;
    }
    node *ptr;
    findSon(this->root,&ptr ,son);
    if(ptr==NULL)
    {
        throw 'the son doesnt exist!';
        return *this;
    }
    else
    {
        ptr->left=new node(father);
        ptr->left->level=ptr->level+1;
        ptr->left->gender='m';
    }
    return *this;
 }
 
 Tree& Tree::addMother(string son, string mother)
 {
    if (son=="" || mother=="")
    {
    throw 'Error, there is at least one word empty!';
    return *this;
    }
     if(this->root==NULL)
    {
        throw 'The family tree doesnt exist!';
        return  *this;
    }
    node *ptr;
    findSon(this->root,&ptr ,son);
    if(ptr==NULL)
    {
        throw 'the son doesnt exist!';
        return *this;
    }
    else
    {
        ptr->right=new node(mother);
        ptr->right->level=ptr->level+1;
        ptr->right->gender='f';
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

string Tree::find(string relation, node *root)
{
if(relation == "grandfather")
    {
        return root->left->left->name;
    }
    else if(relation == "grandmother")
    {
        if(root->left->right != nullptr)
        {
            return root->left->right->name;
        }
        if(root->right->right != nullptr)
        {
            return root->right->right->name;
        }
    }
    else
    {
        string str ;
        str.append(relation.begin()+6,relation.end());
        return find(str, root->left);
    }
    throw "we couldn't find the "+ relation +"in the tree";
}

string Tree::find(string relation)
{
    if (relation == "me")
        return (root->name);
    if ((relation == "father") && (root->left!=nullptr))
        return (root->left->name);
    if ((relation == "mother") && (root->right!=nullptr))
        return (root->right->name);
        else 
        {   
           try
            {
              return find(relation, root);
            }  
            catch(const std::exception& e)
            {
               throw runtime_error("The tree cannot handle the: " + relation + " relation");
            }
         }
}

void printFamily(node *root, int space)  
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

 void Tree::remove(node* root)
 {
  if(root != nullptr)
  {
  remove(root->left);
  remove(root->right);
  delete root;
  }
 }

 string Tree::remove(string name)
 {
    node *ptr;
    findSon(this->root,&ptr,name);
    if(ptr!=NULL)
        remove(ptr);
    else 
        cout << "the Family Tree doesn't exist" << endl;
  }
 }