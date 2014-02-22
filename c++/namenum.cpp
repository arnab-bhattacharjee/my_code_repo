/*
ID: arnabbh1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define ALPHABET 26

vector<vector<char> > v(10);
ofstream fout("namenum.out");
bool flag=false;
class TrieNode{
    public:
    int val;
    TrieNode **edges;
    TrieNode(){
        val=-1;
        edges=new TrieNode*[ALPHABET];
    }
};

class Trie{
    public:
    TrieNode *root;
    Trie(){root=new TrieNode();}
    void insert(string s);
    TrieNode * find(string s);
};

void Trie::insert(string s){
    int i=0;
    TrieNode *tmp=root;
    while(s[i]){
        int pos=s[i]-'A';
        if(!tmp->edges[pos]){
            TrieNode *newNode=new TrieNode();
	    tmp->edges[pos]=newNode;
        }
        tmp=tmp->edges[pos];
        i++;
    }
    tmp->val=0; // signifies leaf
}

TrieNode *Trie::find(string s){
    TrieNode *tmp=root;
    for(int i=0;s[i];i++){
        int pos=s[i]-'A';
        if(!tmp->edges[pos]) return NULL;
        tmp=tmp->edges[pos];
    }
    if(tmp->val==0) return tmp;
    else return NULL;
}
Trie *trie;
void makeString(string& s,string& t,int leftLetters){
    if(leftLetters==0){ if(trie->find(t)){fout<<t<<endl;flag=true;} return;}
    int l=s.length();
    int pos=l-leftLetters;
    int n=s[pos]-'0';
    for(int i=0;i<v[n].size();i++){
        t[pos]=v[n][i];
        makeString(s,t,leftLetters-1);
    }
}

int main(){
    ifstream fin("dict.txt");
    trie=new Trie();
    while(true){
      string s;
      fin>>s;
      //cout<<s<<endl;
      if(fin.eof()) break;
      trie->insert(s);
    }
    fin.close();
    fin.open("namenum.in");
    string s;
    fin>>s;
    v[2].push_back('A');v[2].push_back('B');v[2].push_back('C');
    v[3].push_back('D');v[3].push_back('E');v[3].push_back('F');
    v[4].push_back('G');v[4].push_back('H');v[4].push_back('I');
    v[5].push_back('J');v[5].push_back('K');v[5].push_back('L');
    v[6].push_back('M');v[6].push_back('N');v[6].push_back('O');
    v[7].push_back('P');v[7].push_back('R');v[7].push_back('S');
    v[8].push_back('T');v[8].push_back('U');v[8].push_back('V');
    v[9].push_back('W');v[9].push_back('X');v[9].push_back('Y');
    
    string t=s;
    makeString(s,t,s.length());
    
    if(flag==false) fout<<"NONE"<<endl;
    
}