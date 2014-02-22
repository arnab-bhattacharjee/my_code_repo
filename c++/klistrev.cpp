#include <iostream>

using namespace std;

class Node{
public:
  int key;
  Node *next;
  Node(int key){
    this->key=key;
    next=NULL;
  }
};

class LinkedList{
public:
  Node *head;
  pair<Node *,Node *> kRevList(Node *,int k);
  void push(int key);
  pair<LinkedList *,LinkedList *> alternatingSplit();
  pair<LinkedList *,LinkedList *> middleSplit();
  void alternatingMerge(LinkedList *);
  LinkedList(){
    head=NULL;
  }
  void printList(){
    Node *tmp=head;
    for(;tmp;tmp=tmp->next) cout<<tmp->key<<' '; cout<<endl;
  }
};

void LinkedList::alternatingMerge(LinkedList* l){
  if(!head){ head=l->head; return;}
  Node *curra=head;
  Node *currb=l->head;
  Node *nexta=head->next,*nextb=l->head->next;
  while(nexta && nextb){
    curra->next=currb;
    currb->next=nexta;
    curra=nexta;
    currb=nextb;
    nexta=curra->next;
    nextb=currb->next;
  }
  if(!nexta){cout<<"here";curra->next=currb; currb->next=nextb;}
  if(!nextb){curra->next=currb; currb->next=nexta;}
}

std::pair< LinkedList*, LinkedList* > LinkedList::middleSplit(){
  pair<LinkedList *,LinkedList *> heads;
  heads.first=new LinkedList();
  heads.second=new LinkedList();
  heads.first->head=head;
  if(!head || !head->next) return heads;
  Node *tmpa=head;
  Node *tmpb=head->next;
  while(tmpb){
    cout<<tmpb->key<<endl;
    if(tmpb) tmpb=tmpb->next;
    if(tmpb) tmpb=tmpb->next, tmpa=tmpa->next;
  }
  heads.second->head=tmpa->next;
  tmpa->next=NULL;
  return heads;
}

std::pair< LinkedList*, LinkedList* > LinkedList::alternatingSplit(){
  Node *tmpa=head;
  if(!tmpa) return make_pair<LinkedList *,LinkedList *>(NULL,NULL);
  Node *tmpb=head->next;
  pair<LinkedList *,LinkedList *> heads;
  heads.first=new LinkedList();
  heads.second=new LinkedList();
  heads.first->head=tmpa, heads.second->head=tmpb;
  while(tmpb){
    tmpa->next=tmpa->next->next;
    if(tmpb->next && tmpb->next->next)tmpb->next=tmpb->next->next;
    else tmpb->next=NULL;
    tmpa=tmpa->next, tmpb=tmpb->next;
  }
  return heads;
}

void LinkedList::push(int key){
  Node *newNode=new Node(key);
  newNode->next=head;
  head=newNode;
}

pair<Node *,Node *> LinkedList::kRevList(Node *curr,int k){
  pair<Node *,Node *> headTail;
  headTail.second=curr;
  Node *prev=NULL,*nxt=curr->next;
  for(int i=0;i<k-1 && nxt;i++){
    cout<<curr->key<<' '<<nxt->key<<endl;
    curr->next=prev;
    prev=curr;
    curr=nxt;
    nxt=nxt->next;
  }
  curr->next=prev;
  headTail.first=curr;
  cout<<headTail.first->key<<' '<<headTail.second->key<<endl;
  return headTail;
}

void input(LinkedList *l){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int key;
    cin>>key;
    l->push(key);
  }
}

int main(){
  LinkedList *l=new LinkedList();
  input(l);
  l->printList();
  int k;
  cin>>k;
  Node *prev=NULL,*curr=l->head,*nxt=curr;
  bool firstTime=true;
  while(true){
    for(int i=0;i<k && nxt;i++) nxt=nxt->next;
    pair<Node *,Node *> headTail;
    headTail=l->kRevList(curr,k);
    if(prev) prev->next=headTail.first;
    headTail.second->next=nxt;
    if(firstTime){ l->head=headTail.first; firstTime=false;}
    if(nxt==NULL) break;
    prev=curr;
    curr=nxt;
  }
  l->printList();
  /*pair<LinkedList *,LinkedList *> heads=l->alternatingSplit();
  heads.first->printList();
  heads.second->printList();*/
  /*pair<LinkedList *,LinkedList *> heads=l->middleSplit();
  heads.first->printList();
  heads.second->printList();
  heads.first->alternatingMerge(heads.second);
  heads.first->printList();*/
  LinkedList *r=new LinkedList();
  input(r);
  l->printList();
  r->printList();
  l->alternatingMerge(r);
  l->printList();
}