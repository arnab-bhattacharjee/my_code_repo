#include <iostream>
using namespace std;

class node{
    public:
        node *next;
        int key;
        node(int key){this->key=key, next=NULL;}
};

node *
listReverse(node *head){
    // size of list <2
    if(!head || !head->next) return head;
    
    node *prev,*curr,*next;
    for(prev=NULL, curr=head, next=head->next;next;prev=curr, curr=next, next=next->next){
        //cout<<curr->key<<endl;
        curr->next=prev;
    }
    curr->next=prev;
    return curr;
}


void
printList(node * head){
    node *curr;
    for(curr=head;curr;curr=curr->next) cout<<curr->key<<'\t';
    cout<<endl;

}

node *
kListReverse(node *head, int k){
    // size of list <2
    if(!head || !head->next) return head;
    
    k--;
    node *prev,*curr,*next;
    for(prev=NULL, curr=head, next=head->next;next && k--;prev=curr, curr=next, next=next->next){
        curr->next=prev;
    }
    curr->next=prev;
    return curr;
}



int
main(){
    node *n1=new node(5), *n2=new node(4), *n3=new node(3), *n4=new node(2), *n5=new node(1);
    n1->next=n2, n2->next=n3, n3->next=n4, n4->next=n5;
    node *head=listReverse(n1);
    printList(head);
    node *currHead,*nextHead,*prevTail;
    int k=4;
    for(prevTail=NULL, currHead=head;currHead;){
        int count=k;
        for(nextHead=currHead;nextHead && count--;nextHead=nextHead->next);
        node *tmp=kListReverse(currHead,k);
        if(prevTail)prevTail->next=tmp;
        else {head=tmp;}
        prevTail=currHead;
        currHead=nextHead;
    }
    printList(head);
}
