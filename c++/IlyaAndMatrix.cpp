#include <iostream>
#include <inttypes.h>

using namespace std;
#define Rep(i,x,y) for(int i=x;i<y;i++)
#define LL unsigned long long
#define INF std::numeric_limits<UL>::max()

LL getBeauty(LL** A, uint32_t rows, LL sum){
  if(rows==1)return A[1][1];
  for(int i=1;i<=rows;i+=2){
    for(int j=1;j<=rows;j+=2){
      sum+=A[i][j]+A[i][j+1]+A[i+1][j]+A[i+1][j+1];
      LL max=(A[i][j]>A[i][j+1])?A[i][j]:A[i][j+1];
      max=(max>A[i+1][j])?max:A[i+1][j];
      max=(max>A[i+1][j+1])?max:A[i+1][j+1];
      A[(i/2)+1][(i/2)+1]=max;
    }
  }
  rows=rows>>1;
  getBeauty(A,rows,sum);
}

int main(){
  uint32_t n;
  cin>>n;
  uint32_t rows=n>>1;
  
  LL** A=new LL*[rows+1];
  Rep(i,0,n+1)A[i]=new LL[rows+1];
  
  LL beauty=getBeauty(A,rows,0);
}