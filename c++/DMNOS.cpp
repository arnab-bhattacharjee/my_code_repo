#include <iostream>

using namespace std;
#define LL unsigned long long
#define REP(i,x) for(int i=0; i<x; i++)

LL fib[60]={0};

void multiplyMatrices(LL a[2][2], LL b[2][2]) {
  LL c[2][2];
  REP(i,2) {
    REP(j,2) {
      c[i][j]=0;
      REP(k,2) {
	c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%1000000007)%1000000007;
      }
    }
  }
  REP(i,2)
    REP(j,2)
      a[i][j]=c[i][j];
}

int main() {
  LL a[2][2]={{1,1},{1,0}};
  LL f[2][2]={{1,0},{0,1}};
  LL f_1=1,f_2=1,n=1000000000000000000;
  
  
    // at first generate Fib[1],Fib[2],Fib[2^2],... and so on
  fib[0]=1;
  for(int i=1;n>0;n=n>>1,i++) {
    fib[i]=a[0][0];
    multiplyMatrices(a,a);
  }
  
  REP(i,60) {cout<<fib[i]<<endl;}
  
  /*LL testCases;
  cin>>testCases;
  while(testCases--){

  cin>>n;
  n-=2;
  
  

  
  cout << (f[0][0]*f_2)%1000000007+(f[0][1]*f_1)%1000000007;
  }*/
  
}