#include <iostream>
#include <string.h>

using namespace std;

#define Rep(i,x,y) for(int i=x;i<y;i++)
#define LL unsigned long long
#define INF std::numeric_limits<UL>::max()

int main(){
  string s,t;
  cin>>s>>t;
  
  LL** DP=new LL*[s.length()+1];
  Rep(i,0,s.length()+1){DP[i]=new LL[t.length()+1];memset(DP[i],0,sizeof(LL)*(t.length()));}
  
  Rep(i,1,s.length()+1){
    Rep(j,1,t.length()+1){
      LL val=(s[i-1]==t[j-1])?(1+DP[i-1][j-1]):0;
      DP[i][j]=DP[i][j-1]+val;
    }
  }
  
  int sum=0;
  Rep(i,1,s.length()+1){sum+=DP[i][t.length()];}
  cout<<sum<<endl;
}