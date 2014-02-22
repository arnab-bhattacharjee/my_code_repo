#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int* a=new int[n];
    
    for(int i=0;i<n;i++)
        cin>>a[i];
        
    int* DP=new int[n];
    //DP[i] - max. value contiguous subsequnce ending at i
    int* B=new int[n];
    
    DP[0]=a[0];//base case
    
    for(int i=1;i<n;i++){
        DP[i]=max(DP[i-1]+a[i],a[i]);
        B[i]=(DP[i-1]+a[i]>a[i])?i-1:i;
    }
    
    int maximum=0;
    
    for(int i=0;i<n;i++){
        maximum=(DP[maximum]>DP[i])?maximum:i;
    }
    
    cout<<DP[maximum]<<endl;
    
    int i=maximum;
    
    stack<int> S;
    
    while(B[i]!=i){
        S.push(i);
        i=B[i];
    }
    S.push(i);
    
    while(!S.empty()){
        cout<<a[S.top()]<<'\t';
        S.pop();
    }
    cout<<endl;
}