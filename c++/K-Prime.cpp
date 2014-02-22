#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define SIZE 100001
int main(){
    int *a=new int[SIZE];
    //vector <int> prime_1;
    vector<int> primes;
    memset(a,0,sizeof(int)*SIZE);
    
    a[0]=1;a[1]=1;
    
    for(int i=2;i<SIZE;i++){
        if(a[i]==0){
            primes.push_back(i);
            for(int j=i<<1;j<SIZE;j+=i){
                if(a[j]==0){
                    a[j]=1;
                }
            }
        }
    }
    
    int* k=new int[SIZE];
    memset(k,0,sizeof(int)*SIZE);
    
    //cout<<primes[0];
    
    for(int i=2;i<SIZE;i++){
      if(a[i]==0){k[i]++;continue;}
      int l=i;
      for(int j=0;primes[j]<sqrt(l) && j<primes.size();j++){
	if(l%primes[j]==0)k[i]++;
	while(l%primes[j]==0)l/=primes[j];
      }
      if(l!=1)k[i]++;
    }
    
    //for(int i=1;i<SIZE;i++)cout<<k[i]<<endl;
    
    int **prime,count_1=0,count_2=0,count_3=0,count_4=0,count_5=0;
    prime=new int*[5];
    for(int i=0;i<5;i++)prime[i]=new int[SIZE];

    for(int i=0;i<SIZE;i++){
      if(k[i]==1)count_1++;
      if(k[i]==2)count_2++;
      if(k[i]==3)count_3++;
      if(k[i]==4)count_4++;
      if(k[i]==5)count_5++;
      prime[0][i]=count_1;
      prime[1][i]=count_2;
      prime[2][i]=count_3;
      prime[3][i]=count_4;
      prime[4][i]=count_5;
  }
  
  int t,A,B,K;
  cin>>t;
  while(t--){
    cin>>A>>B>>K;
    cout<<prime[K-1][B]-prime[K-1][A-1]<<endl;
  }
   
}