#include <cstdio>

using namespace std;

int P[100000],rank[100000];// represents the parent and rank of the ith node

int main() {
  int nodes,edges,x,y;
  scanf("%d%d",nodes,edges);
  REP(i,nodes) createSet(i);
  REP(i,edges) {scanf("%d%d",x,y);/*RX=findSet(x);RY=findSet(y);if(RX!=RY)*/mergeSet(x,y);}
}