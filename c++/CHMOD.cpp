#include <iostream>
#include <sstream>
using namespace std;

long long fastExp(long long val,long long exponent,long long MOD){
    long long result=1,store=val;
    while(exponent>0){
        if(exponent%2==1){
            result*=store;
            result=result%MOD;
        }
        store*=store;
        store=store%MOD;
        exponent=exponent>>1;
    }
    return result;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    stringstream s;
    int N;
    cin>>N;
    
    int** a=new int*[N+1];
    for(int i=0;i<N+1;i++){
        a[i]=new int[100];
    }
    
    for(int i=0;i<100;i++){a[0][i]=0;}
    int temp;
    
    for(int i=1;i<N+1;i++){
        for(int j=0;j<100;j++){
            a[i][j]=a[i-1][j];
        }
        cin>>temp;
        a[i][temp-1]++;
    }
    
    int T;
    cin>>T;
    
    while(T--){
        int L,R;long long M;
        cin>>L>>R>>M;
        long long total=1;
        for(int i=0;i<100;i++){
            int num_of_i=a[R][i]-a[L-1][i];
            if(num_of_i>0){
              //  cout<<num_of_i<<'\t'<<i+1<<endl;
                long long prod_of_i=fastExp(i+1,num_of_i,M);
                total*=prod_of_i;
                total=total%M;
            }
        }
        s<<total<<'\n';
    }
    cout<<s.str();
}
