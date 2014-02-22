#include <iostream>

using namespace std;

class Node{
public:
  int key;
  Node* left;
  Node* right;
  Node(int key){this->key=key;left=NULL;right=NULL;}
};

class RBTree {
public:
  Node* root;
  RBTree();
  void insert(int key);
  Node* findNode(int key);
  void inorder(Node*);
  void preorder(Node*);
  void toDLL(Node*,Node**,Node**);
  void printDLL(Node*);
};

void RBTree::printDLL(Node* head){
  Node* curr=head;
  while(curr){cout<<curr->key<<'\t';curr=curr->right;}
  cout<<endl;
}

void RBTree::toDLL(Node* x, Node** headRef, Node** tailRef){
  Node* head;
  Node* tail;
  
  if(x==NULL){
    *headRef=x;
    *tailRef=x;
    return;
  }
  Node *leftHead,*leftTail,*rightHead,*rightTail;
  
  toDLL(x->left,&leftHead,&leftTail);
  toDLL(x->right,&rightHead,&rightTail);
  
  if(leftHead==NULL){
    head=x;
    //x->left=leftTail;
  } else{
    head=leftHead;
    leftTail->right=x;
    x->left=leftTail;
  }
  if(rightHead==NULL){
    tail=x;
    //x->right=rightHead;
  } else{
    tail=rightTail;
    rightHead->left=x;
    x->right=rightHead;
    tail=rightTail;
  }
  *headRef=head;
  *tailRef=tail;
}

void RBTree::preorder(Node* _node){
  if(_node==NULL)return;
  cout<<_node->key<<'\t';
  preorder(_node->left);
  preorder(_node->right);
}

void RBTree::inorder(Node* _node){
  if(_node==NULL) return;
  inorder(_node->left);
  cout<<_node->key<<'\t';
  inorder(_node->right);
}

RBTree::RBTree(){
  root=NULL;
}

void RBTree::insert(int key){
  Node* _node=new Node(key);
  
  Node* x=root;
  Node* y=NULL;
  
  if(root==NULL){
    root=_node;return;
  }

  while(x!=NULL){
    y=x;
    if(key>x->key){
      x=x->right;
    } else{
      x=x->left;
    }
  }
  
  if(key>y->key){
    y->right=_node;
  } else{
    y->left=_node;
  }
}

int main() {
  RBTree* _rb=new RBTree();
  _rb->insert(5);
  _rb->insert(3);
  _rb->insert(6);
   _rb->insert(4);
   _rb->insert(7);
   _rb->insert(2);
   _rb->insert(8);
  _rb->preorder(_rb->root);cout<<endl;
  _rb->inorder(_rb->root);cout<<endl;
  Node* head; Node* tail;
  _rb->toDLL(_rb->root,&head,&tail);
  _rb->printDLL(head);
  /*_rb->rightRotate(_rb->root);
  //cout<<_rb->root->key<<endl;
  _rb->inorder(_rb->root);cout<<endl;
  _rb->preorder(_rb->root);cout<<endl;
  _rb->leftRotate(_rb->root);
  _rb->inorder(_rb->root);cout<<endl;
  _rb->preorder(_rb->root);cout<<endl;*/
}