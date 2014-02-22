#include <iostream>
using namespace std;
#define Rep(i,x) for(int i=0;i<x;i++)
string a[1000];
string b[1000];
int mark[1000];
int main(){
  string s;
  cin>>s;
  int j=0,count=-1;
  for(int i=0;s[i];i++){
    if(s[i]>='A' && s[i]<='Z'){if(count==0)j++;count++;}
    else{
      if(count==1)mark[j]=1;
      count=0;
      a[j]+=s[i];
    }
  }
  
  Rep(i,j+1){
    if(mark[i]==1){
      b[i]=a[i-1]+'9'+a[i];
    }else{
      b[i]='9'+a[i];
    }
  }
  
  if(s[0]>='0' && s[0]<='9'){
    if(j){b[0]=a[0]+'9';}
    else{b[0]=a[0];}
  }
  string max="";
  Rep(i,j+1){
    count=0;
    for(int k=0;b[i][k];k++){
      if(b[i][k]=='0')count++;
      else{break;}
    }
    b[i]=b[i].substr(count);
    if(max.length()<b[i].length()){max=b[i];}
    else if(max.length()==b[i].length()){
      max=(max.compare(b[i])<0)?b[i]:max;
    }
  }
  if(max==""){cout<<0;}
  else//Rep(i,j+1){cout<<b[i]<<endl;}
  {cout<<max<<endl;}
}