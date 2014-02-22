#include <cstdio>

#define REP(i,x) for(int i=0;i<x;i++)
#define LL long long

void mulMatrices(LL a[2][2], LL b[2][2]){
  LL c[2][2];
  REP(i,2) {
    REP(j,2) {
      c[i][j]=0;
      REP(k,2) {
	c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%1000000007)%1000000007;
      }
    }
  }
  REP(i,2)REP(j,2)a[i][j]=c[i][j];
}

int main() {
  LL steps;
  scanf("%lld",&steps);
  
  int t_1=0;
  int t_2=3;
  
  if(steps==1)printf("%d",t_1);
  else if(steps==2)printf("%d",t_2);
  else {
    LL b[2][2]={{2,3},{1,0}};
    LL a[2][2]={{2,0},{0,3}};
    
    for(steps-=3;steps>0;steps=steps>>1) {
      if(steps%2){mulMatrices(a,b);}
      mulMatrices(b,b);
    }
    
    printf("%lld",((((((a[0][0]+a[1][0])%1000000007)*t_2)%1000000007+((a[0][1]+a[1][1])*t_1)%1000000007)%1000000007)%1000000007));
  }
}