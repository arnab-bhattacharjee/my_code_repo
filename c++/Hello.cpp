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
int T;
cin>>T;
while(T--){
long long D,D1,U,N;
scanf("%lld.%lld %lld %lld",&D,&D1,&U,&N);
cout<<D1<<endl;
D*=100;D+=D1;
long long* M=new long long[N];
long long* R=new long long[N];
long long* C=new long long[N];
long long* T=new long long[N];
for(int i=0;i<N;i++){
long long temp;
scanf("%lld %lld.%lld %lld",&M[i],&R[i],&temp,&C[i]);
cout<<temp<<endl;
R[i]*=100;
R[i]+=temp;
C[i]*=100;
T[i]=R[i]*U;
}
long long min=D*U,min_i=0;
for(int i=0;i<N;i++){
long long a,b;
  if(min_i==0){
  a=T[i]*M[i]+C[i];
  b=D*U*M[i];
}
else{
  long long lcm_n=lcm(M[i],M[min_i]);
  a=T[i]*lcm_n+C[i]*(lcm_n/M[i]);
  b=T[min_i-1]*lcm_n+C[i]*(lcm_n/M[min_i-1]);
}
if(a<b){
min_i=i+1;
}
}
cout<<min_i<<endl;
}
}