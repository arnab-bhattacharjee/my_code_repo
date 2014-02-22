#include <iostream>

using namespace std;

class Node{
public:
  int key;
  Node* left;
  Node* right;
  Node* parent;
  int color; // 0-red, 1-black
  Node(int key){this->key=key;left=NULL;right=NULL;parent=NULL;color=0;}
};

class RBTree {
private:
  Node* NIL;
  void RBInsertFixup(Node*);
public:
  Node* root;
  RBTree();
  void insert(int key);
  Node* findNode(int key);
  void inorder(Node*);
  void preorder(Node*);
  void rightRotate(Node*);
  void leftRotate(Node*);
};

void RBTree::leftRotate(Node* x){
  Node* y=x->right;
  x->right=y->left;
  y->left->parent=x;
  
  y->parent=x->parent;
  
  if(x->parent==NIL){root=y;}
  else if(x->parent->left==x){x->parent->left=y;}
  else {x->parent->right=y;}
  
  y->left=x;
  x->parent=y;
}

void RBTree::rightRotate(Node* x){
  Node* y=x->left;
  x->left=y->right;
  y->right->parent=x;
  
  y->parent=x->parent;
  
  if(x->parent==NIL){root=y;}
  else if(x->parent->left==x){x->parent->left=y;}
  else {x->parent->right=y;}
  
  y->right=x;
  x->parent=y;
}

void RBTree::preorder(Node* _node){
  if(_node==NIL)return;
  cout<<_node->key<<'\t';
  preorder(_node->left);
  preorder(_node->right);
}

void RBTree::inorder(Node* _node){
  if(_node==NIL) return;
  inorder(_node->left);
  cout<<_node->key<<'\t';
  inorder(_node->right);
}

RBTree::RBTree(){
  NIL=new Node(-1);
  NIL->color=1;
  root=NIL;

}

void RBTree::insert(int key){
  Node* _node=new Node(key);
  
  Node* x=root;
  Node* y=NIL;

  while(x!=NIL){
    y=x;
    if(key>x->key){
      x=x->right;
    } else{
      x=x->left;
    }
  }
  
  _node->parent=y;
  if(y==NIL){root=_node;_node->left=NIL;_node->right=NIL;}
  else if(key>y->key){
    y->right=_node;
    _node->left=NIL;
    _node->right=NIL;
  } else{
    y->left=_node;
    _node->left=NIL;
    _node->right=NIL;
  }
  RBInsertFixup(_node);
}

void RBTree::RBInsertFixup(Node* z){
  //cout<<z->parent->key;
  while(z->parent->color==0){
    if(z->parent==z->parent->parent->left){
      Node* y=z->parent->parent->right;
      if(y->color==0){
	z->parent->color=1;
	y->color=1;
	z->parent->parent->color=0;
	z=z->parent->parent;
      } else{
	  if(z==z->parent->right){
	    leftRotate(z->parent);
	  }
	  z->parent->parent->color=0;
	  z->parent->color=1;
	  rightRotate(z->parent->parent);
      }
    } else{
      Node* y=z->parent->parent->left;
      if(y->color==0){
	z->parent->color=1;
	y->color=1;
	z->parent->parent->color=0;
	z=z->parent->parent;
      } else{
	  if(z==z->parent->left){
	    rightRotate(z->parent);
	  }
	  z->parent->parent->color=0;
	  z->parent->color=1;
	  leftRotate(z->parent->parent);
      }
    }
  }
  root->color=1;
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
  /*_rb->rightRotate(_rb->root);
  //cout<<_rb->root->key<<endl;
  _rb->inorder(_rb->root);cout<<endl;
  _rb->preorder(_rb->root);cout<<endl;
  _rb->leftRotate(_rb->root);
  _rb->inorder(_rb->root);cout<<endl;
  _rb->preorder(_rb->root);cout<<endl;*/
}