#include <iostream>
#include <algorithm>
using namespace std;
string s;
int rank[50],tmp[50],sa[50],g,lcp[50];

bool cmp(int i, int j){
    if(rank[i]!=rank[j]) return (rank[i]<rank[j]);
    i+=g, j+=g;
    if(i<s.length() && j<s.length()){
        return (rank[i]<rank[j]);
    } else{
        return (i>j);
    }
}

void buildSA(){
    for(int i=0;s[i];i++){
        sa[i]=i;
        rank[i]=s[i];
    }
    
    for(g=1;;g=g<<1){
        sort(sa,sa+s.length(),cmp);
        for(int i=1;i<s.length();i++){
            tmp[i]=tmp[i-1]+cmp(sa[i-1],sa[i]);
        }
        for(int i=0;i<s.length();i++){
            rank[sa[i]]=tmp[i];
        }
        
        if(tmp[s.length()-1]==s.length()-1)break;
    }
}

void buildLCP(){
    for(int i=0;i<s.length();i++){
        cout<<rank[i]<<'\t';
    }
    cout<<endl;
    int h=0;
    for(int i=0;i<s.length();i++){
        if(rank[i]>0){
            int k=sa[rank[i]-1];
            cout<<k<<endl;
            while(s[i+h]==s[k+h])h++;
        }
        lcp[rank[i]]=h;
        if(h>0)h=h--;
    }
    
    for(int i=1;i<s.length();i++){
        cout<<lcp[i]<<'\t';
    }
    cout<<endl;
}

int main(){
    cin>>s;
    buildSA();
    for(int i=0;s[i];i++){
        cout<<sa[i]<<'\t';
    }
    cout<<endl;
    
    buildLCP();
}