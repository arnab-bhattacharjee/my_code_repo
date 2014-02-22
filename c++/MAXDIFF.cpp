#include <cstdio>
#include <algorithm>
#include <vector>
#define SIZE 100
using namespace std;

#define REP(i,x) for(int i=0;i<x;i++)
#define LL long long

int main() {
  vector<int> w(SIZE);
  int t;
  scanf("%d",&t);
  while(t--) {
    int n,k,temp;
    scanf("%d %d",&n,&k);
    int i=n;
    while(i--){scanf("%d",&w[i]);}
    sort(w.begin(),w.begin()+n);
    k=(n-k<k)?n-k:k;
    LL sum_dad=0,sum_son=0;
    REP(i,k)sum_son+=w[i];
    for(int i=k;i<n;i++)sum_dad+=w[i];
    printf("%lld\n",sum_dad-sum_son);
  }
}
    
    
  