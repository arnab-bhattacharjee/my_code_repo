#include <iostream>

using namespace std;
#define Rep(i,x,y) for(int i=x;i<y;i++)

int main(){
    string s,t;
    cin>>s>>t;
    
    int slen=s.length();
    int tlen=t.length();
    
    int** DP=new int*[slen+1];
    Rep(i,0,slen+1){
        DP[i]=new int[tlen+1];
    }
    
    DP[0][0]=0;
    Rep(i,1,slen+1){DP[i][0]=0;}
    Rep(i,1,tlen+1){DP[0][i]=0;}
    
    Rep(i,1,slen+1){
        Rep(j,1,tlen+1){
            if(s[i-1]==t[j-1]){
                DP[i][j]=DP[i-1][j-1]+1;
            } else{
                DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
            }
        }
    }
    
    /*Rep(i,0,slen+1){
        Rep(j,0,tlen+1){
            cout<<DP[i][j]<<'\t';
        }cout<<endl;
    }*/
    
    cout<<DP[slen][tlen]<<endl;
}
