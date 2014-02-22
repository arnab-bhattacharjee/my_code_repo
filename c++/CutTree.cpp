#include <iostream>
#include <string.h>

using namespace std;

#define Rep(i,x,y) for(int i=x;i<y;i++)
int** DP;
void generateCombinations(int n){
  DP=new int*[n+1];
  Rep(i,0,n+1){DP[i]=new int[n+1];memset(DP[i],0,sizeof(int)*(n+1));}
  
  DP[1][0]=1;DP[1][1]=1;
  
  Rep(i,2,n+1){
    Rep(j,0,i/2+1){
      DP[i][j]=(j-1>=0)?DP[i-1][j]+DP[i-1][j-1]:DP[i-1][j];
      DP[i][i-j]=DP[i][j];
    }
  }
}

int main(){
  int n,k;
  cin>>n>>k;
  
  generateCombinations(n-1);
  
  int edges=n-1;
  int* V=new int[n+1];
  
  int u,v;
  while(edges--){
    cin>>u>>v;
    V[u]++;V[v]++;
  }
  
  int sum=2;
  Rep(i,1,n+1){
    Rep(j,1,k+1){
      if(j<=V[i]){sum+=DP[V[i]][j];}
      else break;
    }
  }
  cout<<sum<<endl;
}