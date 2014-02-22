#include <iostream>

using namespace std;

class DLLNode{
public:
  int key;
  DLLNode *next;
  DLLNode *prev;
  DLLNode(int key){next=NULL,prev=NULL,this->key=key;}
};

class DLL{
public:
  int count;
  DLLNode *head;
  DLL(){head=NULL;count=0;}
  void push(int key);
  void printDLL();
  void printBST(DLLNode *);
  DLLNode *DLLToBBST(int n);
};

DLLNode* DLL::DLLToBBST(int n){
  if(n==0) return NULL;
  DLLNode *l=DLLToBBST(n>>1);
  DLLNode *root;
  root=head;
  root->prev=l;
  head=head->next;
  DLLNode *r=DLLToBBST(n- (n>>1) -1);
  root->next=r;
  return root;
}

void DLL::printBST(DLLNode* t){
  if(t==NULL) return;
  cout<<t->key;
  printBST(t->prev);
  printBST(t->next);
}

void DLL::printDLL(){
  DLLNode *curr=head;
  for(;curr;curr=curr->next){{if(curr->prev)cout<<curr->prev->key<<'\t';cout<<curr->key<<'\t'; if(curr->next)cout<<curr->next->key;} cout<<endl;}
}

void DLL::push(int key){
  DLLNode *newNode=new DLLNode(key);
  newNode->next=head;
  if(head)head->prev=newNode;
  head=newNode;
  count++;
}

void init(DLL *l){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int key;
    cin>>key;
    l->push(key);
  }
}

int main(){
  DLL *a=new DLL();
  init(a);
  a->printDLL();
  DLLNode *root=a->DLLToBBST(a->count);
  a->printBST(root);
}