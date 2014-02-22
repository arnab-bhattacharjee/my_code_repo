#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

#define LL long long
#define REP(i,x) for(int i=0;i<x;i++)
#define rep(i,n,x) for(int i=n;i<x;i++)

// using Dynamic Programming paradigm
LL getBinomialCoefficient(LL rows, LL cols) {
  // create a n*k array for storing values
  rows+=1; cols+=1;
  LL** binCoeffs=new LL*[rows];
  REP(i,rows) {binCoeffs[i]=new LL[cols]; memset(binCoeffs[i],0,sizeof(binCoeffs[i]));} // set the values to 0
  
  REP(i,rows) {
    cout << i << endl;
    for(int j=0;j<=i && j<cols;j++) {
      binCoeffs[i][j]=(j==0)?1:binCoeffs[i-1][j]+binCoeffs[i-1][j-1];
      cout << "binCoeffs[" << i << "]" << "[" << j << "] = " << binCoeffs[i][j] << endl;
    }
  }
  return binCoeffs[rows-1][cols-1];
  
}

int main() {
  int n,r;
  cin >> n;
  cin >> r;
  assert(r<=n);
  
  LL result=getBinomialCoefficient(n, r);
  
  cout << result;
}