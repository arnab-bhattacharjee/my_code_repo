#include <iostream>

using namespace std;
#define LL long long
#define REP(i,x) for(int i=0; i<x; i++)

void multiplyMatrices(LL a[2][2], LL b[2][2]) {
  LL c[2][2];
  REP(i,2) {
    REP(j,2) {
      c[i][j]=0;
      REP(k,2) {
	c[i][j]+=a[i][k]*b[k][j];
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
  LL f_1=1,f_2=1,n;
  
  cin >> n;
  n-=2;
  
  for(;n>0;n=n>>1) {
    if(n%2==1) multiplyMatrices(f,a);
    REP(i,2) REP(j,2) cout << f[i][j];
    cout<< endl;
    multiplyMatrices(a,a);
  }
  
  cout << f[0][0]*f_2+f[0][1]*f_1;
  
}