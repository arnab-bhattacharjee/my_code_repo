#include <iostream>
#include <cmath>
using namespace std;
#define ULL unsigned long long
int main(){
    int N;
    cin>>N;
    
    int *a=new int[N];
    for(int i=0;i<N;i++) cin>>a[i];
    
    int X;
    cin>>X;
    
    sort(a,a+n);
    
    ULL neg_total=0;
    for(int i=0;i<N;i++){
        if(a[i]>=0)break;
        neg_total+=(-a[i]);
    }
}
