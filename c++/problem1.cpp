#include <iostream>

using namespace std;
#define Rep(i,x) for(int i=0;i<x;i++)
int main(){
    int n;
    cin>>n;
    int* a=new int[n];
    Rep(i,n){
        cin>>a[i];
    }
    int* b=new int[n];
    int* c=new int[n];
    int count_0=0;
    int count_1=0;
    Rep(i,n){
        if(a[i]==0){count_0++;}
        else{count_1++;}
        b[i]=count_0;
        c[i]=count_1;
    }
    
    if(count_1==n-1){}
    
    //Rep(i,n)cout<<b[i]<<'\t';cout<<endl;
    //Rep(i,n)cout<<c[i]<<'\t';cout<<endl;
    
    
    int max=0;
    int max_i=0,max_j=0;
    
    Rep(i,n){
        for(int j=i;j<n;j++){
            if(i==0){
                if(max<(b[j]-c[j])){
                    max=b[j]-c[j];
                    max_i=0;max_j=j;
                }
            } else{
                if(max<(b[j]-b[i-1]-c[j]+c[i-1])){
                    max=b[j]-b[i-1]-c[j]+c[i-1];
                    cout<<max<<'\t'<<i<<'\t'<<j<<endl;
                    max_i=i;max_j=j;
                }
            }
        }
    }
    
    //cout<<max_i<<max_j<<endl;
    
    int left_1=(max_i-1>=0)?c[max_i-1]:0;
    int right_1=c[n-1]-c[max_j-1];
    //cout<<left_1<<right_1;
    
    cout<<max+left_1+right_1;
}