#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
#define SIZE 100
#define ALPHABETSIZE 26
class FlipKartTest{
public:
  vector<vector<int> > g(ALPHABETSIZE);
  int mark[26];
  int child[26];
  int root;
  vector<int> roots;


//parse input into graph
void init(){
  char *s=new char[SIZE];
  cin.getline(s,SIZE);
  //cout<<s;
  for(int i=0;i<SIZE;i++){
    int first,second;
    if(s[i]>='A' && s[i]<='Z'){
      first=s[i]-'A';
      second=s[i+2]-'A';
      i+=2;
      cout<<first<<' '<<second<<endl;
      mark[first]++;
      mark[second]++; child[second]++;
      g[first].push_back(second);
    }
  }
  // for lexicographic ordering
  for(int i=0;i<ALPHABETSIZE;i++){
    sort(g[i].begin(),g[i].end());
  }
}

int getCountOfNodes(){
  int count=0;
  for(int i=0;i<ALPHABETSIZE;i++) if(mark[i]) count++;
  return count;
}

int getRoot(){
  int count=0;
  for(int i=0;i<ALPHABETSIZE;i++) if(mark[i] && !child[i]){ count++; root=i; cout<<"root="<<root<<endl; roots.push_back(i);}
  if(count==1) return root;
  else return -1;
}

// returns true if error type E1 is present
bool E1(){
  for(int i=0;i<ALPHABETSIZE;i++){
    if(g[i].size()>2) return true;
  }
  return false;
}

// returns true if error type E2 is present
bool E2(){
  for(int i=0;i<ALPHABETSIZE;i++){
    bool visited[ALPHABETSIZE];
    memset(visited,0,sizeof(bool)*ALPHABETSIZE);
    for(int j=0;j<g[i].size();j++)
      if(!visited[g[i][j]]) visited[g[i][j]]=true;
      else return true;
  }
  return false;
}

// DFS for cycle checking
bool dfs(int u){
  bool status=false;
  for(int i=0;i<g[u].size();i++){
    if(!mark[g[u][i]]) mark[g[u][i]]=1;
    else if(mark[g[u][i]]) return true;
    status=status || dfs(g[u][i]);
  }
  return status;
}

// returns true if error type E3 is present
bool E3(){
  bool status=false;
  memset(mark,0,sizeof(int)*ALPHABETSIZE);
  for(int i=0;i<roots.size();i++)
    status=status || dfs(roots[i]);
  return status;
}

// returns true if error type E4 is present
bool E4(){
  if (root==-1) return true;
  else return false;
}

// dfs to print Tree
void dfs2(int u){
  cout<<'('<<(char)(u+'A');
  for(int i=0;i<g[u].size();i++){
    dfs2(g[u][i]);
  }
  cout<<')';
}

//print Tree
void printTree(){
  for(int i=0;i<ALPHABETSIZE;i++){
    cout<<i<<"----";
    for(int j=0;j<g[i].size();j++){
       cout<<g[i][j];
    }
    cout<<endl;
  }
 dfs2(root);
 cout<<endl;
}

int main(){
  init();
  int count=getCountOfNodes();
  //cout<<count;
  root=getRoot();
  //cout<<root;
  
  if(E1()){ cout<<"E1"<<endl; return 0;}
  if(E2()){ cout<<"E2"<<endl; return 0;}
  if(E3()){ cout<<"E3"<<endl; return 0;}
  if(E4()){ cout<<"E4"<<endl; return 0;}
  
  
  printTree();
  return 0;
}