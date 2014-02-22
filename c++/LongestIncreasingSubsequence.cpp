#include <iostream>

using namespace std;
int* DP;
int* a;
int length;

int binSearch(int val){
    int hi=length;
    int lo=0;
    int mid=(hi+lo)>>1;
    while(!(a[DP[mid]]<val && a[DP[mid+1]]>val) && mid!=0){
        if(a[DP[mid]]<val){lo=mid;}
        else{hi=mid;}
        mid=(hi+lo)>>1;
    }
    if(mid==0)return 0;
    return (mid+1);
}

int main(){
    int n;
    cin>>n;
    
    a=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    
    DP=new int[n];
    int* B=new int[n];
    
    DP[0]=0;
    B[0]=-1;
    length=0;// length of the LIS seen still now
    for(int i=1;i<n;i++){
        if(a[i]>a[DP[length]]){
            //cout<<a[i];
            DP[length+1]=i;
            B[i]=DP[length];
            length++;
        } else{
            int k=binSearch(a[i]);
            //cout<<k;
            DP[k]=i;
            B[i]=k-1;
        }
    }
    cout<<length+1<<endl;
    int i=DP[length];
    cout<<a[DP[length]]<<'\t';
    while(B[i]!=-1){
        cout<<a[B[i]]<<'\t';
        i=B[i];
    }
    cout<<endl;
}