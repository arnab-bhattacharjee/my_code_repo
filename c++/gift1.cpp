/*
ID: arnabbh1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
#define ALPHABET 26
int nodes;
class Node{
    public:
    int val;
    Node **edges;
    Node(){
        val=-1; 
        edges=new Node*[ALPHABET];
        for(int i=0;i<ALPHABET;i++) edges[i]=NULL;
    }
};

class Trie{
    Node *root;
    public:
    Trie(){root=new Node();}
    void insert(string s,int val);
    Node * getNode(string s);
};

void Trie::insert(string s,int val){
    Node *tmp=root;
    int len=s.length();
    for(int i=0;i<len;i++){
        int pos=s[i]-'a';
        if(pos<0) pos=s[i]-'A';
        if(tmp->edges[pos]==NULL)
        {nodes++;tmp->edges[pos]=new Node();}
        tmp=tmp->edges[pos];
        if(i==len-1)tmp->val=val;
    }
}

Node * Trie::getNode(string s){
    Node *tmp=root;
    for(int i=0;s[i];i++){
        int pos=s[i]-'a';
	if(pos<0) pos=s[i]-'A';
        if(tmp->edges[pos]) tmp=tmp->edges[pos];
        else return NULL;
    }
    return tmp;
}



int main(){

    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    int NP;
    fin>>NP;
    
    string *s=new string[NP];
    Trie* t=new Trie();
    for(int i=0;i<NP;i++) fin>>s[i], t->insert(s[i],0);
    
    string str;int amt,numOfMembers;
    for(int i=0;i<NP;i++){
        fin>>str>>amt>>numOfMembers;
        
        Node *tmp=t->getNode(str);
        if(numOfMembers!=0) tmp->val-=(amt/numOfMembers)*numOfMembers;
        
        for(int j=0;j<numOfMembers;j++){
            string st;
            fin>>st;
            tmp=t->getNode(st);
            tmp->val+=amt/numOfMembers;
        }
    }
    
    Node *tmp;
    for(int i=0;i<NP;i++){
        tmp=t->getNode(s[i]);
        fout<<s[i]<<' '<<tmp->val<<endl;
    }
    
}

