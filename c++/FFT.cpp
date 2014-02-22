#include <iostream>
#include <vector>
using namespace std;

void FFT(int *p, vector<complex<double> > &a){
  int n=a.size();
  if(n==1) return p1[0];
  int mid=n>>1;
  int *p0=new int[mid];
  int *p1=new int[mid];
  vector<complex<double> > a0(n>>1),a1(n>>1);
  for(int i=0;i<mid;i++) p0[i]=p[i<<1], p1[i]=p[(i<<1) + 1];
  FFT(p0,a0);
  FFT(p1,a1);
  
}

int main(){
  int N;
  cin>>N; // Assume N is a power of 2
  int *p1=new int[N];
  vector<complex<double> > a(N);
  for(int i=0;i<N;i++) cin>>p1[i];
  FFT(p1,a);
}