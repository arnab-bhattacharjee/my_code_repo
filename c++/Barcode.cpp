#include <cstdio>
#include <string.h>

#define REP(i,x) for(int i=0; i<x; i++)

int main() {
  int n,m,x,y;
  scanf("%d %d %d %d\n", &n, &m, &x, &y);
  char* temp=new char[m+1]; int total=0;
  int* count=new int[m];
  int* cum_count=new int[m];
  memset(count, 0, sizeof(int)*m);
  
  REP(i,n) {
   scanf("%s", temp);
   //printf("%s\n", temp);
   REP(j,m) {
     if(temp[j]=='#') count[j]++;
   }
  }
  
  REP(i,m) {
    cum_count[i]=(i==0)?count[i]:cum_count[i-1]+count[i];
  }
  
  //REP(i,m)printf("%d\t%d\n", count[i], cum_count[i]);
  
  int* M=new int[m+1]; // the best way of converting nxi matrix with the last col. comprising of #s
  int* N=new int[m+1]; // the best way of converting nxi matrix with the last col. comprising of .s
  
  REP(i,m+1){M[i]=i*n;N[i]=i*n;}
  //REP(i,m+1)printf("%d\t%d\n", M[i], N[i]);

  
  for(int i=1; i<=m; i++) {
    for(int j=x; j<=y && i-j>=0; j++) {
      int possible_min=(i-j-1>=0)?N[i-j]+cum_count[i-1]-cum_count[i-j-1]:N[i-j]+cum_count[i-1];//printf("%d\t%d\n", i, possible_min);
      M[i]=(M[i]>possible_min)?possible_min:M[i];
      possible_min=(i-j-1>=0)?M[i-j]+n*(j)-(cum_count[i-1]-cum_count[i-j-1]):M[i-j]+n*j-cum_count[i-1];//printf("%d\t%d\n", i, possible_min);
      N[i]=(N[i]>possible_min)?possible_min:N[i];
    }
  }
  int min=(M[m]<N[m])?M[m]:N[m];
  printf("%d\n", min);
}