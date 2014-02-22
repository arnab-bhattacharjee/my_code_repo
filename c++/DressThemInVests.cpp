#include <stdio.h>
#include <string.h>

#define LL long long
#define Rep(i,x) for(int i=0;i<x;i++)
int main() {
  int n,m; LL x,y;
  scanf("%d%d%lld%lld",&n,&m,&x,&y);
  LL* a=new LL[n];
  Rep(i,n){scanf("%lld",&a[i]);}
  LL* b=new LL[m];
  Rep(i,m){scanf("%lld",&b[i]);}
  int i=0,j=0,k=0;
  int* u=new int[n];
  int* v=new int[n];
  memset(u,0,sizeof(int)*n);
  memset(v,0,sizeof(int)*n);
  while(i<n && j<m) {
    if(a[i]-x<=b[j] && a[i]+y>=b[j]){u[k]=i;v[k]=j;k++;i++;j++;}
    else if(a[i]-x>b[j]){j++;}
    else {i++;}
  }
  printf("%d\n",k);
  Rep(i,k){printf("%d %d\n",u[i]+1,v[i]+1);}
}
  