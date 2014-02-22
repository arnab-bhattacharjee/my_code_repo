#include <inttypes.h>
#include <algorithm>
#include <stdio.h>
using namespace std;

#define Rep(i,x,y) for(int i=x;i<y;i++)
#define LL unsigned long long
#define INF std::numeric_limits<UL>::max()

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
  int P,M;
  scanf("%d%d",&P,&M);
  int N[1001];
  int sum=0;
  Rep(i,0,M){scanf("%d",&N[i]);sum+=N[i];}
  
  bool DP[1001][1001];
  
  DP[0][0]=true;
  Rep(i,0,P+1){
    Rep(j,1,M+1){
      DP[i][j]=DP[i][j-1];
      bool temp=(i-N[j-1]>=0)?DP[i-N[j-1]][j-1]:false;
      DP[i][j]=DP[i][j]||temp;
    }
  }
  
  int A[1001];
  Rep(i,0,P)scanf("%d",&A[i]);
  
  int32_t noOfProperFamilies=0;
  int32_t count=1;
  Rep(i,0,P){
    if(A[i]==A[i+1])count++;
    else{if(DP[count][M]){noOfProperFamilies++;}count=1;}
  }
  
  printf("%d\n",noOfProperFamilies);
  }
}