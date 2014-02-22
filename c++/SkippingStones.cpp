#include <iostream>
#include <string.h>

using namespace std;
#define Rep(i,x,y) for(int i=x;i<y;i++)

int main(){
    int n,L,D;
    cin>>n>>L>>D;
    
    cout<<n<<L<<D;
    
    double* p=new double[n+1];
    Rep(i,0,n){
        cin>>p[i];
    }
    p[n]=1;
    
    Rep(i,0,n+1)cout<<p[i]<<'\t';
    cout<<endl;
    
    /*int* d=new int[n+1];
    Rep(i,0,n){
        cin>>d[i];
    }
    d[n]=D;
    
    Rep(i,0,n)cout<<d[i]<<'\t';
    cout<<endl;
    
    /*double* DP=new double[n+2];
    memset(DP,0,sizeof(double)*(n+2));
    DP[0]=1;
    
    /*Rep(i,1,n+2){
        int j=i-1;
        while(true){
            int l=d[i-1]-d[j-1];
            if(l>L)break;
            if(DP[i]<(DP[j]*p[i-1])){
                DP[i]=DP[j]*p[i-1];
            }
            j--;
            if(j<0)break;
        }
    }
    
    Rep(i,0,n+1)cout<<DP[i]<<'\t';
    cout<<endl;*/
    
    
}
