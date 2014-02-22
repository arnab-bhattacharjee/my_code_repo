#include <cstdio>
#include <string.h>

#define REP(i,x) for(int i=0;i<x;i++)
#define rep(i,x,y) for(int i=x;i<y;i++)
#define LL long long

int getPowerOfTwo(LL num){int i=0;for(;num%2==0;num=num>>1,i++);return i;}
int getPowerOfFive(LL num){int i=0;for(;num%5==0;num=num/5,i++);return i;}
int main() {
  int n;
  scanf("%d",&n);
  LL** A=new LL*[n];  
  REP(i,n) {
    A[i]=new LL[n];
    REP(j,n) {
      scanf("%lld",&A[i][j]);
    }
  }
  
  //REP(i,n){REP(j,n){printf("%lld\t",A[i][j]);}printf("\n");}
  
  LL** MinTwos=new LL*[n+1];
  REP(i,n)MinTwos[i]=new LL[n+1];
  LL** MinFives=new LL*[n];
  REP(i,n)MinFives[i]=new LL[n];
  
  REP(i,n+1){MinTwos[0][i]=0;MinTwos[i][0]=0;}
  REP(i,n+1){MinFives[0][i]=0;MinFives[i][0]=0;}
    
  rep(i,1,n+1) {
    rep(j,1,n+1) {
      int numOfTwos=getPowerOfTwo(A[i-1][j-1]);
      int numOfFives=getPowerOfFive(A[i-1][j-1]);
      MinTwos[i][j]=(MinTwos[i-1][j]<MinTwos[i][j-1])?(MinTwos[i-1][j]+numOfTwos):(MinTwos[i][j-1]+numOfTwos);printf("%d\t",MinTwos[i][j]);
      MinFives[i][j]=(MinFives[i-1][j]<MinFives[i][j-1])?(MinFives[i-1][j]+numOfFives):(MinFives[i][j-1]+numOfFives);
    }
    printf("\n");
  }
}