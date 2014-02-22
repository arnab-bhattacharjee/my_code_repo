#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int b;
    cin>>b;
    while(b--){
    string a,s,t;
    cin>>a;
    int len=a.length();
    
    if(len%2){cout<<"-1"<<endl;continue;}
    
    s=a.substr(0,len>>1);
    t=a.substr(len>>1);
    
    //cout<<s<<endl<<t;
    
    int sAlphabets[26];
    int tAlphabets[26];
    memset(sAlphabets,0,sizeof(sAlphabets));
    memset(tAlphabets,0,sizeof(tAlphabets));
    for(int i=0;s[i];i++){sAlphabets[s[i]-'a']++;}
    for(int i=0;t[i];i++){tAlphabets[t[i]-'a']++;}
    
    //for(int i=0;i<26;i++){cout<<sAlphabets[i]<<'\t';}cout<<endl;
    
    int sum=0;
    
    for(int i=0;i<26;i++){
        if(sAlphabets[i]!=tAlphabets[i]){
            sum+=(sAlphabets[i]>tAlphabets[i])?sAlphabets[i]-tAlphabets[i]:tAlphabets[i]-sAlphabets[i];
        }
    }
    
    cout<<(sum>>1)<<endl;
    }
}
