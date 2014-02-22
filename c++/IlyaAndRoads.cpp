#include <iostream>
#include <string.h>
#include <limits>

using namespace std;
#define Rep(i,x,y) for(int i=x;i<y;i++)
#define UL unsigned long long
#define INF std::numeric_limits<short>::max()
int main(){
  unsigned int n,m,k;
  cin>>n>>m>>k;
  
  UL** cost=new UL*[n+1];
  Rep(i,0,n+1){cost[i]=new UL[n+1];}
  
  Rep(i,0,n+1)Rep(j,0,n+1){cost[i][j]=INF;}

  unsigned int t=m;
  while(t--){
    unsigned int li,ri;
    UL ci;
    cin>>li>>ri>>ci;
    Rep(i,li,ri+1){if(cost[i][ri]>ci)cost[i][ri]=ci;}
    Rep(i,li,ri+1){if(cost[li][i]>ci)cost[li][i]=ci;}
  }
  
  Rep(i,0,n+1){Rep(j,0,n+1){cout<<cost[i][j]<<'\t';}cout<<endl;}cout<<endl;
  
  UL** DP=new UL*[n+1];
  Rep(i,0,n+1){DP[i]=new UL[n+1];}
  
  Rep(i,0,n+1)Rep(j,0,n+1){DP[i][j]=INF;}
  Rep(i,0,n+1){DP[i][0]=0;}
  
  Rep(i,1,n+1){
    Rep(j,1,i+1){
      DP[i][j]=DP[i-1][j];
      for(int k=1;k<=i && k<=j;k++){
	if(DP[i-k][j-k]!=INF && cost[i-k+1][i]!=INF){
	  if(DP[i][j]>(DP[i-k][j-k]+cost[i-k+1][i]))
	    DP[i][j]=DP[i-k][j-k]+cost[i-k+1][i];
	}
      }
    }
  }
  
  Rep(i,0,n+1){Rep(j,0,n+1){cout<<DP[i][j]<<'\t';}cout<<endl;}cout<<endl;

  if(DP[n][k]!=INF){
    cout<<DP[n][k]<<endl;
  }else{cout<<"-1\n";}

}