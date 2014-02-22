#include <cstdio>

class Node {
public:
  int key;
  Node* right;
  Node* left;
  Node* parent;
  Node(int key);
};

Node::Node(int key) {
  this->key=key;
  left=right=parent=NULL;
}


class BST {
private:
  Node* root;
public:
  BST();
  void BSTInsert(int key);
  void BSTLeftRotate(Node* _node);
  void BSTRightRotate(Node* _node);
  void BSTInorderTraversal();
  void BSTInorderTraversal(Node* _node);
  void BSTPreorderTraversal();
  void BSTPreorderTraversal(Node* _node);
  Node* fetchNode(int key);
};
void BST::BSTLeftRotate(Node* alpha) {
  Node* beta=alpha->right;
  
  printf("%d %d\n",alpha->key,beta->key);
  
  printf("%d %d\n",alpha->parent->key,beta->parent->key);
  
  beta->parent=alpha->parent;
  alpha->parent->left=beta;
  alpha->parent=beta;
  alpha->right=beta->left;
  beta->left=alpha;
  
  
}
Node* BST::fetchNode(int key) {
  Node* temp=root;
  while(temp!=NULL) {
    if(temp->key==key){return temp;}
    else if(temp->key<key){temp=temp->right;}
    else{temp=temp->left;}
  }
  return NULL;
}
void BST::BSTInorderTraversal() {
  BSTInorderTraversal(root);printf("\n");
}
void BST::BSTInorderTraversal(Node* _node) {
  if(_node==NULL)return;
  else {BSTInorderTraversal(_node->left);printf("%d\t",_node->key);BSTInorderTraversal(_node->right);}
}
void BST::BSTPreorderTraversal() {
  BSTPreorderTraversal(root);printf("\n");
}
void BST::BSTPreorderTraversal(Node* _node) {
  if(_node==NULL)return;
  else {printf("%d\t",_node->key);BSTPreorderTraversal(_node->left);BSTPreorderTraversal(_node->right);}
}
BST::BST() {
  root=NULL;
}
void BST::BSTInsert(int key) {
  Node* x=root;
  Node* y=NULL;
  
  while(x!=NULL) {
    y=x; // maintain parent information
    if(x->key<key){x=x->right;} // move left is key is smaller 
    else{x=x->left;} // move right if key is larger
  }
  
  Node* _node=new Node(key);
  if(y!=NULL) {
    if(y->key < key){y->right=_node;}
    else {y->left=_node;}
    _node->parent=y;
  } else {root=_node;}
}
int main() {
  BST* _bst=new BST();
  int n;scanf("%d",&n);
  while(n--){int key;scanf("%d",&key);_bst->BSTInsert(key);}
  _bst->BSTInorderTraversal();
  _bst->BSTPreorderTraversal();
  Node* _node=_bst->fetchNode(1);
  _bst->BSTLeftRotate(_node);
  _bst->BSTInorderTraversal();
  _bst->BSTPreorderTraversal();
}