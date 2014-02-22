#include <iostream>
#include <cassert>
using namespace std;
#define Rep(i,x) for(Node* i=x;i;i=i->next)

class Node{
public:
  int key;
  Node* next;
  Node(int key){this->key=key;next=NULL;}
};

class LinkedList{
public:
  Node* head;
  Node** tailRef;
  LinkedList(){head=NULL;tailRef=&head;}
  void push(int key);
  void printList();
  int count();
  int getNth(int n);
  void enqueue(int key);
  void deleteList();
  int pop();
  void insertNth(int n,int key);
  void frontBackSplit(Node** front,Node** back);
  void alternatingSplit(Node** aRef,Node** bRef);
  void shuffleMerge(Node* b);
  void reverse();
  void reverse(Node** aHeadRef,Node** aTailRef);
};

void LinkedList::reverse(Node** aHeadRef, Node** aTailRef){
  Node* curr=*aHeadRef;
  Node* bHead=*aHeadRef;
  Node* bTail=*aTailRef;
  if(curr==NULL || curr->next==NULL)return;
  Node* prev=NULL;
  Node* next=curr->next;
  while(curr->next!=bTail->next){
    curr->next=prev;
    prev=curr;
    curr=next;
    next=next->next;
  }
  curr->next=prev;
  *aHeadRef=curr;
  *aTailRef=bHead;
}

void LinkedList::reverse(){
  if(head==NULL || head->next==NULL)return;
  Node* prev=NULL;
  Node* curr=head;
  Node* next=curr->next;
  
  while(curr->next){
    curr->next=prev;
    prev=curr;
    curr=next;
    next=next->next;
  }
  curr->next=prev;
  head=curr;
}

void LinkedList::shuffleMerge(Node* b){
  Node* newHead=NULL;
  Node** tailRef=&newHead;
  
  Node* curr_a=head;Node* curr_b=b;
  while(true){
    if(!curr_a && !curr_b)break;
    if(curr_a){*tailRef=curr_a;tailRef=&(curr_a->next);curr_a=curr_a->next;}
    if(curr_b){*tailRef=curr_b;tailRef=&(curr_b->next);curr_b=curr_b->next;}
  }
  *tailRef=NULL;
  head=newHead;
}

void LinkedList::alternatingSplit(Node** aRef, Node** bRef){
  int count=0;
  Node* curr=head;
  
  Node* aHead=NULL;Node** aTailRef=&aHead;
  Node* bHead=NULL;Node** bTailRef=&bHead;
  
  while(curr){
    Node* next=curr->next;
    if(count%2==0){*aTailRef=curr;aTailRef=&(curr->next);}
    else{*bTailRef=curr;bTailRef=&(curr->next);}
    curr=next;count++;
  }
  *aTailRef=NULL;
  *bTailRef=NULL;
  *aRef=aHead;
  *bRef=bHead;
}

void LinkedList::frontBackSplit(Node** front, Node** back){
  int numOfNodes=count();
  if(numOfNodes<=1){front=&head;*back=NULL;}
  else{
    Node* slow=head;Node* fast=head->next;
    while(fast->next){fast=fast->next;if(fast->next){fast=fast->next;slow=slow->next;}}
    *back=slow->next;
    slow->next=NULL;
    *front=head;
  }
}

void LinkedList::insertNth(int n,int key){
  if(n==0){push(key);return;}
  Node* curr=head;
  while(n>1){assert(curr->next!=NULL);curr=curr->next;n--;}
  assert(curr!=NULL);
  Node* nextNext=curr->next;
  Node* newNode=new Node(key);
  curr->next=newNode;
  newNode->next=nextNext;
}

int LinkedList::pop(){
  assert(head!=NULL);
  int key=head->key;
  Node* next=head->next;
  delete head;
  head=next;
  return key;
}

void LinkedList::deleteList(){
  for(Node* curr=head;curr;){Node* next=curr->next;delete curr;curr=next;}
  head=NULL;
  tailRef=&head;
}

int LinkedList::getNth(int n){
  int count=-1;
  Rep(i,head){count++;if(count==n)return(i->key);}
  return -1;
}

void LinkedList::push(int key){
  Node* newNode=new Node(key);
  if(!head){head=newNode;tailRef=&(head->next);}
  else{newNode->next=head;head=newNode;}
}

void LinkedList::enqueue(int key){
  Node* newNode=new Node(key);
  if(!head){head=newNode;tailRef=&(head->next);}
  else{*tailRef=newNode;tailRef=&(newNode->next);}
}

void LinkedList::printList(){
  //Rep(i,head){cout<<i->key<<'\t';}
  Node* curr=head;
  while(curr!=*tailRef){cout<<curr->key<<'\t';curr=curr->next;}
  cout<<endl;
}

int LinkedList::count(){
  int count=0;
  Rep(i,head){count++;}
  return count;
}

int main(){
  LinkedList* LL=new LinkedList();
  LL->push(1);LL->push(2);LL->enqueue(56);LL->enqueue(12);LL->push(45);LL->push(18);LL->push(100);LL->enqueue(91);LL->enqueue(19);
/*  cout<<LL->count()<<endl;
  LL->printList();
  cout<<LL->getNth(1)<<endl;
  //cout<<LL->pop()<<endl;
  LL->insertNth(2,14);
  //LL->deleteList();
  LL->printList();
  LinkedList *front=new LinkedList();LinkedList* back=new LinkedList();
  //LL->frontBackSplit(&(front->head),&(back->head));
  LL->alternatingSplit(&(front->head),&(back->head));
  front->printList();back->printList();
  LinkedList* testList=new LinkedList();
  testList->push(45);testList->push(29);testList->push(11);testList->push(19);testList->push(23);
  front->shuffleMerge(testList->head);*/
  LL->printList();
  LL->reverse(&(LL->head),&(LL->head->next->next));
  /*int k=3;
  int count=0;
  Node** aTail=&(LL->head);Node* aHead=LL->head;Node* prev=NULL;Node* next;
  while(*aTail){
    count++;
    if(count==k){Node* next=&(*aTail->next);LL->reverse(&aHead,aTail);prev->next=aHead;*aTail=next;}
    else{}
  }*/
}