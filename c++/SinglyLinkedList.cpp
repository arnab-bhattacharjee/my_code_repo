#include <cstdio>
#include <cassert>
#include <bits/algorithmfwd.h>

using namespace std;

class Node {
public:
  int key;
  Node* next;
};

class SinglyLinkedList {
private:
  Node* head;
  Node** tailRef;
  void push(Node*& _node,int newData);
public:
  SinglyLinkedList();
  void push(int newData);
  void display();
  void enqueue(int newData);
  void deleteList();
  void insertNth(int index, int newData);
  int pop();
  void sortedInsert(Node* _node);
  void insertSort();
  friend void append(SinglyLinkedList& L1, SinglyLinkedList& L2);
  friend void frontBackSplit(SinglyLinkedList& L1, SinglyLinkedList& L2, SinglyLinkedList& L3);
  void removeDuplicates();
  void append_(SinglyLinkedList& L2);
};

void SinglyLinkedList::display() {
  Node* current=head;
  while(current!=NULL){printf("%d -> ",current->key);current=current->next;}
  printf("\n");
}


SinglyLinkedList::SinglyLinkedList() {
  head=NULL;
  tailRef=&head;
}

void SinglyLinkedList::push(int newData) {
  if(head==NULL) {
    push(head,newData);
    tailRef=&(head->next);
  } else {
    push(head,newData);
  }
}

void SinglyLinkedList::push(Node*& _node,int newData) {
  Node* newNode=new Node();
  newNode->key=newData;
  newNode->next=_node;
  _node=newNode;
}

void SinglyLinkedList::enqueue(int newData) {
  Node* newNode=new Node();
  newNode->key=newData;
  *tailRef=newNode;
  tailRef=&((*tailRef)->next);
}

void SinglyLinkedList::deleteList() {
  if(head==NULL) return;
  Node* current=head;
  Node* next=head->next;
  while(next) {
    delete current;
    current=next;
    next=next->next;
  }
  delete current;
  head=NULL;
}

int SinglyLinkedList::pop() {
  assert(head!=NULL);
  Node* newHead=head->next;
  int headKey=head->key;
  delete head;
  head=newHead;
  return headKey;
}

void SinglyLinkedList::insertNth(int index, int newData) {
  if(index==0)push(newData);
  else {
    Node* current=head;
    for(int i=0;i<index-1;i++) {
      assert(current!=NULL);
      current=current->next;
    }
    assert(current!=NULL);
    if(!current->next) {
      push(current->next,newData);
      tailRef=&(current->next->next);
    } else {
      push(current->next,newData);
    }
  }
}

void SinglyLinkedList::sortedInsert(Node* _node) {
  if(!head || head->key > _node->key) {
    _node->next=head;
    head=_node;
  } else {
    Node* current=head;
    while(current->next && current->next->key < _node->key) {
      current=current->next;
    }
    _node->next=current->next;
    current->next=_node;
  }
}

void SinglyLinkedList::insertSort() {
  if(!head) return;
  Node* oldHead=head;
  Node* current=oldHead;
  head=NULL;
  while(current) {
    oldHead=oldHead->next;
    sortedInsert(current);
    current=oldHead;
  }
}

void append(SinglyLinkedList& L1, SinglyLinkedList& L2) {
  if(!L1.head){L1.head=L2.head;}
  else {
    Node* current=L1.head;
    while(current->next)current=current->next;
    current->next=L2.head;
  }
  L2.head=NULL;
}

void SinglyLinkedList::append_(SinglyLinkedList& L2) {
  if(!head){head=L2.head;}
  else {
    Node* current=head;
    while(current->next)current=current->next;
    current->next=L2.head;
  }
  L2.head=NULL;
}

void frontBackSplit(SinglyLinkedList& L1, SinglyLinkedList& L2, SinglyLinkedList& L3) {
  if(!L1.head || !L1.head->next){L2.head=L1.head;L3.head=NULL;}
  else {
    Node* slow=L1.head;
    Node* fast=L1.head->next;
    while(fast) {
      fast=fast->next;
      if(fast){fast=fast->next;slow=slow->next;}
    }
    L3.head=slow->next;
    slow->next=NULL;
    L2.head=L1.head;
  }
}

void SinglyLinkedList::removeDuplicates() {
  Node* current=head;
  if(!head || !head->next) return;
  else {
    while(current->next) {
      if(current->key==current->next->key){Node* nextNext=current->next->next;delete current->next;current->next=nextNext;}
      else {current=current->next;}
    }
  }
}

int main() {
  SinglyLinkedList L1,L2,L3,L4;
  L1.enqueue(12);
  L1.push(1);
  L1.display();	
  L1.push(3);
  L1.push(2);
  L1.display();
  L1.insertNth(4,2);
  L1.enqueue(8);
  L1.display();
  L1.insertSort();
  L1.removeDuplicates();
  L1.display();
  L2.push(10);L2.push(11);L2.push(12);
  L1.append_(L2);
  L1.display();L2.display();
  frontBackSplit(L1,L3,L4);
  L3.display();
  L4.display();
}