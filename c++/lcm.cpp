#include <iostream>
#include <stdio.h>
 
using namespace std;
 
long long gcd(long long a,long long b){
if(a<b)swap(a,b);
if(b==0)return a;
return gcd(b,a%b);
}
 
long long lcm(long long a,long long b){
long long gcd_ab=gcd(a,b);
return (a*b)/gcd_ab;
}

int main(){
  long long a[32];
  for(int i=0;i<32;i++){
    a[i]=i+1;
  }
  long long lcm_n=a[0];
  for(int i=1;i<32;i++){
    lcm_n=lcm(lcm_n,a[i]);
    cout<<lcm_n<<'\t'<<i<<endl;
  }
  cout<<lcm_n<<endl;
}