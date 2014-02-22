#include <queue>
#include <string.h>
#include <climits>

#include <cstdio>
#include <vector>

using namespace std;

class Graph {
private:
  int V;
  vector<int>* adj;
public:
  Graph(int V);
  void addEdge(int u,int v);
  void printGraph();
  const vector<int>& adjList(int v);
};

Graph::Graph(int V) {
  this->V=V;
  adj=new vector<int>[V];
}

void Graph::addEdge(int u, int v) {
  adj[u-1].push_back(v);
  adj[v-1].push_back(u);
}

void Graph::printGraph() {
  for(int i=0;i<V;i++) {
    printf("%d -> ",i+1);
    for(vector<int>::iterator  it=adj[i].begin(); it!=adj[i].end(); it++) {
      printf("%d -> ",*it);
    }
    printf("\n");
  }

}

const std::vector< int >& Graph::adjList(int v) {
  return adj[v-1];
}



int main() {
  int V,E;
  int u,v;
  scanf("%d %d",&V,&E);
  Graph* G=new Graph(V);
  int t=E;
  while(t--){scanf("%d %d",&u,&v);G->addEdge(u,v);}
  G->printGraph();
  queue<int> Q;
  
  int* d=new int[V+1];
  int* p=new int[V+1];
  int* color=new int[V+1];
  int dist;
  
  memset(d,INT_MAX,sizeof(int)*(V+1));
  memset(p,-1,sizeof(int)*(V+1));
  memset(color,0,sizeof(int)*(V+1));
  
  int s;
  scanf("%d",&s);
  d[s]=0;color[s]=1;
  Q.push(s);
  while(!Q.empty()) {
    int u=Q.front();
    Q.pop();
    for(vector<int>::const_iterator it=G->adjList(u).begin(); it!=G->adjList(u).end(); it++) {
      if(color[*it]==0){printf("here\n");Q.push(*it);color[*it]=1;p[*it]=u;d[*it]=d[u]+1;}
    }
  }
  for(int i=1; i<=V; i++){printf("%d\t",d[i]);}
}
  