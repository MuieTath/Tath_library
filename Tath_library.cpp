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
void pre_order(Node*r);
Node* remove_node(Node* r,int rem);
Node* searchNode(Node* r, int find);
void in_order(Node* r);
void post_order(Node* r);
bool recursive_research(Node* r,int find);
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
    if(recursive_research(r,5)==true){
        cout<<"number was found\n";
    }
    else{
        cout<<"not found\n";
    }
    return 0;
        
}
//------------------------------------------------------------------------------------------------------------------------------------------------

Node* iterative_insertion(Node* Root,int add){
    Node* curr=Root;
    if(Root==NULL) 
        return new Node(add);
    if(Root->value==add){
        Root->c++;
        return Root;
    }
    while(curr!=nullptr){
         if(curr->value==add){
            curr->c++;
            return Root;
        }
        if(add<curr->value){
            if(curr->left==nullptr){
            curr->left=new Node(add);
            return Root;
        }
            curr=curr->left;
        }
        else if(add>curr->value){
            if(curr->right==nullptr){
            curr->right=new Node(add);
            return Root;
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
//------------------------------------------------------------------------------------------
bool recursive_research(Node* r,int find){
    if(r==NULL){
        return false;
    }
    if(r->value==find){
        return true;
    }
    if(find>r->value){
     r=r->right;
     return recursive_research(r,find);   
    }
    else if(find<r->value){
        r=r->left;
        return recursive_research(r,find);
    }
    else
        return false;
}
//-----------------------------------------------------------------------------------
void pre_order(Node*r){
    if(r!=NULL){
        cout<<r->value<<" ";
        pre_order(r->left);
        pre_order(r->right);
    }
}
//------------------------------------------------------------------------------------
void in_order(Node* r){
    if(r!= NULL){
        in_order(r->left);
        cout<<r->value<<" ";
        in_order(r->right);
    }
}
//-------------------------------------------------------------------------------------
void post_order(Node* r){
    if(r!=NULL){
        post_order(r->left);
        post_order(r->right);
        cout<<r->value<<" ";
    }
}
//-------------------------------------------------------------------------------------
Node* remove_node(Node* r, int rem){
    if(r==NULL){
        return NULL;
    }
    Node* parent=nullptr;
    Node* curr=r;
    while (curr!=nullptr&&curr->value!=rem){
        parent=curr;
        if (rem<curr->value){
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
    }
    if(curr==nullptr){
        return r;
    }
    if(curr->left!=nullptr&&curr->right!=nullptr) {
        Node* succParent=curr;
        Node* successivo=curr->right;
        while (successivo->left!=nullptr){
            succParent=successivo;
            successivo=successivo->left;
        }
        curr->value=successivo->value;
        curr=successivo;
        parent=succParent;
    }
    Node* child=(curr->left!=nullptr)?curr->left:curr->right;
    if (parent==nullptr){
        delete curr;
        return child;
    }
    if(parent->left==curr){
        parent->left=child;
    }
    else{
        parent->right=child;
    }
    delete curr;
    return r;
}