#include <iostream>
#include <string.h>
using namespace std;
#define Rep(i,x,y) for(int i=x;i<y;i++)
#define LL unsigned long long

// if A[i] is true number is prime
bool* generatePrimes(int n){
  bool* A=new bool[n+1];
  Rep(i,0,n+1)memset(A,true,sizeof(bool)*n);
  Rep(i,2,n+1){
    if(A[i]==false)continue;
    for(int j=i<<1;j<n+1;j+=i){
      A[j]=false;
    }
  }
  return A;
}

int main(){
  bool* A=generatePrimes(10000);
  int t;
  cin>>t;
  while(t--){
  int n;
  cin>>n;
  int* T=new int[n];
  int max=0;
  Rep(i,0,n){
    cin>>T[i];
    max=(T[i]>max)?T[i]:max;
  }

  LL lcm=1;

  Rep(i,2,max+1){
    if(A[i]==false)continue;
    bool flag=true;
    while(flag){
      flag=false;
      Rep(j,0,n){
	if(T[j]%i==0){if(!flag){lcm*=i;lcm%=1000000007;}T[j]/=i;flag=true;}
      }
    }
  }
  cout<<lcm<<endl;
  }
}