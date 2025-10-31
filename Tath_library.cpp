#include <iostream>

using namespace std;
struct Node{
  int value;
  Node* left,* right;
  int c;                                                          
    Node(int v){
        value=v;
        left=nullptr;
        right=nullptr;
        c=0;
    }
    Node(Node* other)
    {
        value=other->value;
        left=other->left;
        right=other->right;
        c=0;
    }
    Node(Node &other)
    {
        value=other.value;
        left=other.left;
        right=other.right;
        c=0;
    }
    
};
bool iterative_research(Node* r,int find);
Node* recursive_insertion(Node* Root,int add);
Node* iterative_insertion(Node* Root,int add);
int main(){
    Node* r=new Node(10);
    r=iterative_insertion(r,15);
    r=iterative_insertion(r,5);
    r=iterative_insertion(r,6);
    r=iterative_insertion(r,11);
    r=iterative_insertion(r,12);
    if(iterative_research(r,5)==true){
        cout<<"number was found\n";
    }
    cout<<"not found\n";
    return 0;
        
}
//------------------------------------------------------------------------------------------------------------------------------------------------

Node* iterative_insertion(Node* Root,int add)
{
    Node* curr=Root;
    if(Root==NULL) 
        return new Node(add);
    if(Root->value==add){
        Root->c++;
    }
    while(curr!=nullptr){
         if(curr->value==add){
            curr->c++;
            return curr;
        }
        if(add<curr->value){
            if(curr->left==nullptr){
            curr->left=new Node(add);
            return curr;
        }
            curr=curr->left;
        }
        else if(add>curr->value){
            if(curr->right==nullptr){
            curr->right=new Node(add);
            return curr;
        }
            curr=curr->right;
        }
    }
    return Root;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------

Node* recursive_insertion(Node* Root,int add){
    if(Root==NULL)
        return new Node(add);
    if(Root->value==add)
        return Root;
    if(add>Root->value){
        Root->right=recursive_insertion(Root->right, add);
    }else if(add<Root->value){
        Root->left=recursive_insertion(Root->left, add);
    }
    return Root;
}
//---------------------------------------------------------------------------------------------------------------------------------------------

bool iterative_research(Node* r,int find){
    Node* curr=r;
    if(r==NULL)
        return false;
    if(r->value==find)
        return true;
    while(curr!=nullptr){
         if(curr->value==find){
            return true;
        }
        if(find<curr->value){
            if(curr->left==nullptr){
            return false;
        }
            curr=curr->left;
        }
        else if(find>curr->value){
            if(curr->right==nullptr){
            return false;
        }
            curr=curr->right;
        }
    }
    
}