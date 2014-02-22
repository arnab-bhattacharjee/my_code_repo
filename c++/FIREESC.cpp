#include <cstdio>
#include <string.h>
#include <assert.h>

using namespace std;
#define LL long long
#define swap(x,y) LL temp=x;x=y;y=temp
#define REP(i,x) for(LL i=1;i<x;i++)

class Node {
public:
  LL key;
  Node* next;
  Node(){key=0;next=0;}
};

class Queue {
private:
  LL arr[100001];
  LL tail;
  LL head;
public:
  Queue(){head=0;tail=0;memset(arr,0,sizeof(arr));}
  void enqueue(LL val){arr[tail]=val;tail=(tail+1)%100001;}
  LL dequeue(){assert(isEmpty()==false);head+=1;return arr[head-1];}
  bool isEmpty(){bool isEmpty=(head==tail)? true: false;return isEmpty;}
};

int main() {
  LL vertices,edges,x,y;
  LL color[100001];
  int t;
  scanf("%d",&t);
  while(t--) {
    scanf("%lld%lld",&vertices,&edges);
    Node** adjList=new Node*[vertices+1];
    memset(adjList,0,sizeof(Node *)*(vertices+1));
    
    while(edges--) {
      scanf("%lld%lld",&x,&y);
      if(x>y) {swap(x,y);}
      // insert node y as neighbour of x
      Node* temp=new Node();
      temp->key=y;
      temp->next=adjList[x];
      adjList[x]=temp;
    }
    
    /*REP(i,vertices+1) {
      Node* it=adjList[i];
      while(it){printf("%lld",it->key);it=it->next;}
      printf("\n");
    }*/
    
    // BFS 
    Queue Q;
    // color[i] = 0:white, 1:grey, 2:black
    memset(color,0,sizeof(color));// color all nodes as white
    LL count,noOfWaysOfSelectingCap=1,noOfTrees=0;
    REP(i,vertices+1) {
      if(color[i]==0) {
	count=0;
	noOfTrees++;
	Q.enqueue(i);
	while(!Q.isEmpty()) {
	  LL x=Q.dequeue();
	  count++;
	  color[x]=1;
	  Node* it=adjList[x];
	  while(it){if(color[it->key]==0)Q.enqueue(it->key);it=it->next;}
	  color[x]=2;
	}
	noOfWaysOfSelectingCap=(noOfWaysOfSelectingCap*count)%1000000007;
      }
    }
    printf("%lld %lld\n",noOfTrees,noOfWaysOfSelectingCap);
  }
}