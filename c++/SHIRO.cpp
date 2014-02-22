#include <iostream>
#include <string.h>

using namespace std;

int main(){
  int T;
  cin>>T;
  while(T--){
  int N;
  cin>>N;
  int* a=new int[N];
  int total=0;
  for(int i=0;i<N;i++){
    cin>>a[i];
    total+=a[i];
  }
  double* p=new double[N];
  bool flag=false;
  int first_i=0;
  for(int i=0;i<N;i++){
    cin>>p[i];
    if(p[i]!=0 && flag==false){flag=true;first_i=i;}
    p[i]/=100;
  }
  
  //cout<<first_i<<'\t'<<p[first_i]<<endl;
  
  if(flag==false){cout<<"0"<<endl;continue;}
  
  double* DP=new double[total+1];
  memset(DP,0,sizeof(double)*(total+1));
  
  DP[a[first_i]]=p[first_i];
  DP[0]=(1-p[first_i]);
  
  //cout<<DP[a[first_i]]<<endl;
  
  for(int i=first_i+1;i<N;i++){
    if(a[i]==0)continue;
    for(int j=total;j>=0;j--){
      if(DP[j]==0)continue;
      else{
	//cout<<"here";
	DP[j+a[i]]+=DP[j]*p[i];
	DP[j]=DP[j]*(1-p[i]);
      }
    }
  }
  
  /*for(int i=0;i<=total;i++){
    cout<<DP[i]<<endl;
  }*/
  
  int mid=(total%2) + (total>>1);
  double prob=0;
  for(int i=mid;i<=total;i++){
    prob+=DP[i];
  }
  
  cout<<prob<<endl;
  }
}