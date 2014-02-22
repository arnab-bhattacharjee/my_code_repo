#include <iostream>
#include <limits>
#include <string.h>
using namespace std;
#define Rep(i,x,y) for(int i=x;i<y;i++)


int* DP;
int choice[]={1,2,5};
int getToNumUsingOneTwoFive(int n){
   DP=new int[n+1];
   memset(DP,1,sizeof(int)*(n+1));
   
   DP[0]=0;
   
   Rep(i,1,n+1){
       Rep(j,0,3){
        if((i-choice[j])>=0)
        DP[i]=(DP[i]>(DP[i-choice[j]]+1))?(DP[i-choice[j]]+1):DP[i];
       }
   }
}

int main(){
   getToNumUsingOneTwoFive(1000);
   
   int t;
   cin>>t;
   while(t--){
   int n;
   cin>>n;
   int* A=new int[n];
   int min=10000;
   Rep(i,0,n){cin>>A[i];min=(A[i]<min)?A[i]:min;}
   
   Rep(i,0,n)A[i]-=min;
   
   int count[5];
   Rep(i,0,5)count[i]=0;
   
   int sum=0;int grp;
   Rep(i,0,n){
       sum+=DP[A[i]];
       grp=A[i]%5;
       count[grp]++;
   }
   
   int a=count[3]-(count[0]+count[1]+count[2]);
   int b=count[4]-(count[0]+count[2]);
   
   //cout<<a<<endl<<b<<endl;
   
   int max_a_b=(a>b)?a:b;
   
   if(max_a_b>0)sum-=max_a_b;
  
   cout<<sum<<endl;
   }
}
