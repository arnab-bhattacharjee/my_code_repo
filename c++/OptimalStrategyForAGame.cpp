#include <iostream>
#include <string.h>
using namespace std;
int** P1;
int** P2;
int* a;
int* cf;
void solve(int i,int j){
    cout<<i<<'\t'<<j<<endl;
    if(j<=i)return;
    int total;
    if(i==0){total=cf[j];}
    else {total=cf[j]-cf[i-1];}
    if((j-i)%2==0){ // second player is playing
        if(!P1[i+1][j])solve(i+1,j);
        if(!P1[i][j-1])solve(i,j-1);
        P2[i][j]=max(total-P1[i+1][j],total-P1[i][j-1]);
    } else{
        if(!P2[i+1][j])solve(i+1,j);
        if(!P2[i][j-1])solve(i,j-1);
        P1[i][j]=max(total-P2[i+1][j],total-P2[i][j-1]);
    }
}

int main(){
    int n;
    cin>>n;
    
    a=new int[n];
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    cf=new int[n];
    cf[0]=a[0];
    for(int i=1;i<n;i++){
        cf[i]=cf[i-1]+a[i];
    }
    
    P1=new int*[n];
    P2=new int*[n];
    
    for(int j=0;j<n;j++){
        P1[j]=new int[n]; memset(P1[j],0,sizeof(int)*n);
        P2[j]=new int[n]; memset(P2[j],0,sizeof(int)*n);
    }
    
    for(int i=0;i<n;i++){
        P2[i][i]=a[i];
    }
    
    solve(0,n-1);
    
    for(int i=0;i<n;i++){for(int j=0;j<n;j++)cout<<P1[i][j]<<'\t';cout<<endl;}
    for(int i=0;i<n;i++){for(int j=0;j<n;j++)cout<<P2[i][j]<<'\t';cout<<endl;}
    cout<<P1[0][n-1];
}