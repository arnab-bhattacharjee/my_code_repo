#include <iostream>
using namespace std;
#define Rep(i,x) for(int i=0;i<x;i++)
int a[1000000];
int main(){
  int t;
  cin>>t;
  while(t--){
  string s;
  cin>>s;
  int flag=0,j=0,count=0;
  for(int i=0;s[i];i++){
    if(s[i]=='#'){
      if(flag){a[j]=count;j++;}
      flag=0;count=0;
    }else{
      if(flag){count++;}
      else{flag=1;count++;}
    }
  }
  //Rep(i,s.length()){cout<<a[i]<<endl;}
  int max=0;count=0;
  Rep(i,j){
    if(a[i]>max){
      max=a[i];
      count++;
    }
  }
  
  cout<<count<<endl;
  }
} 