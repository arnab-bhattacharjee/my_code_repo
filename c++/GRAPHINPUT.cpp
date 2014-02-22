#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;
#define REP(i,x) for(int i=0;i<x;i++)
#define vi vector<int>
#define vvi vector< vi >
#define swap(x,y) int temp=x;x=y;y=temp
#define all(c) (c).begin(),(c).end()

int numOfEdges,numOfVerices;

void getInput(vvi& G) {
  cin >> numOfEdges;
  int u,v;
  
  REP(i,numOfEdges) {
    cin>>u>>v;
    assert(u!=v && u<=numOfVerices && v<=numOfVerices);
    if(u>v) {swap(u,v);}
    G[u].push_back(v);
  }
}

void print(vvi& G) {
  REP(i,numOfVerices) {
    for(typeof(G[i].begin()) it=G[i].begin();it!=G[i].end();it++) {
      cout << *it;
    } cout << endl;
  }
}

int main() {
  cin >> numOfVerices;
  vvi G(numOfVerices);
  getInput(G);
  print(G);
}