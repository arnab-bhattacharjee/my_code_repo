#include "UndirectedGraph.h"

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
  return adj[v];
}



int main() {
  Graph G(10);
  G.addEdge(1,2);
  G.addEdge(2,3);
  G.printGraph();
}