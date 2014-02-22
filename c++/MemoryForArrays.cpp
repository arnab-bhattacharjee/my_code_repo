#include <iostream>
#include <string.h>
using namespace std;
#define Rep(i,x,y) for(int i=x;i<y;i++)
int main(){
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    int a[30];
    memset(a,0,sizeof(a));
    int b[30];
    memset(b,0,sizeof(b));
    int c[30];
    memset(c,0,sizeof(c));
    
    int num,k;
    int count=0;
    Rep(i,0,n){
        cin>>num;
        count=0;
        while(num>0){
            a[count++]+=num%2, num=num>>1;
        }
    }
    
    Rep(i,0,30)cout<<a[i]<<'\t';cout<<endl;
    
    Rep(i,0,m){
        cin>>num, b[num]++;
    }
    
    Rep(i,0,30)cout<<b[i]<<'\t';cout<<endl;
    
    count=0;
    Rep(i,0,30){
        Rep(j,i,30){
            count+=min(a[j]<<(j-i),b[i]);
            a[j]=max(0,(a[j]-(b[i]>>(j-i)+b[i]%()));
            b[i]=max(0,b[i]-(a[j]<<(j-i)));
            if(b[i]==0)break;
        }
    }
    
    cout<<count<<endl;
        
}
