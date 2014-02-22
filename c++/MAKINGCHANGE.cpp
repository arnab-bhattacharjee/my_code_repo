#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int* v=new int[n];
    for(int i=0;i<n;i++)
        cin>>v[i];
        
    int C;
    cin>>C;
    
    int* DP=new int[C+1];
    int* B=new int[C+1];
    
    DP[0]=0; // base case
    B[0]=0;
    for(int i=1;i<=C;i++){
        DP[i]=DP[i-v[0]]+1;
        B[i]=v[0];
        for(int j=1;j<n;j++){
            if(i-v[j]>0){
                if(DP[i-v[j]]+1<DP[i]){
                    DP[i]=DP[i-v[j]]+1;
                    B[i]=v[j];
                }
            }
        }
    }
        
    cout<<DP[C]<<endl;
    while(C>0){
        cout<<B[C];
        C=C-B[C];
    }
}