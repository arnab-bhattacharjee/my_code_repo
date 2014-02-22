#include <stdio.h>
#include <vector>
#include <stack>
#include <string.h>

using namespace std;

class Graph {
private:
  int V;
  int E;
  vector<int>* adjList;
public:
  Graph(int V, int E); // constructor
  void addEdge(int u,int v); //add edge (u,v) to graph
  vector<int>& adj(int u); // returns the adj list of vertex u
  void printGraph();
};

Graph::Graph(int V, int E) {
  this->V=V;
  this->E=E;
  adjList=new vector<int>[V];
}

void Graph::addEdge(int u, int v) {
  adjList[u].push_back(v);
  adjList[v].push_back(u);
}

vector<int>& Graph::adj(int u) {
  return adjList[u];
}

void Graph::printGraph() {
  for(int i=0;i<V;i++) {
    vector<int> adj_i=adj(i);
    for(vector<int>::iterator it=adj_i.begin();it!=adj_i.end();it++){printf("%d->\t",*it);}
    printf("\n");
  }
}

int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  Graph* G=new Graph(n,m);// graph with n vertices and m edges
  int t=m;
  int u,v;
  while(t--){scanf("%d%d",&u,&v);G->addEdge(u,v);}
  G->printGraph();
  
  stack<int> S;
  int* color=new int[V];
  int* parent=new int[V];
  
  memset(color,0,sizeof(int)*V);
  memset(parent,-1,sizeof(int)*V);
  
  for(int i=0;i<V;i++) {
    if(color[i]==1){
      color[i]=1;
      S.push(i);
      while(!S.empty()) {
	int u=S.top();S.pop();
	vector<int> adj_u=G->adj(u);
	for(vector<int>::iterator it=adj_u.begin();it!=adj_u.end();it++){S.push(*it);color[i=1];}
      }
    }
  }
}