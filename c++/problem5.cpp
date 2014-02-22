#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int g;
int* sa;
int* rank;
int len;
string s;

int substrCmp(string str1,string str2){
    int l1=str1.length();
    int l2=str2.length();
    
    int i;
    
    for(i=0;i<l1 && str2[i];i++){
        if(str1[i]==str2[i])continue;
        else if(str1[i]<str2[i]) return -1;
        else return 1;
    }
    
    if(i==l1)return 0;
    else return 1;
}

bool cmp(int i,int j){
    if(rank[i]!=rank[j]) return (rank[i]<rank[j]);
    i+=g;j+=g;
    if(i<len && j<len) return (rank[i]<rank[j]);
    else return (i>j);
}

int main(){
    int W;
    cin>>W;
    
    string* P=new string[W];
    for(int i=0;i<W;i++){
        cin>>P[i];
    }
    
    int N;
    cin>>N;
    string t;
    while(N--){
        cin>>t;
        s+=t;
        s+='$';
    }
    //cout<<s<<endl;
    len=s.length();
    //cout<<len<<endl;
    sa=new int[len];
    rank=new int[len];
    for(int i=0;i<len;i++){
        sa[i]=i;
        rank[i]=s[i];
    }
    
    int* pos=new int[len];
    pos[0]=0;
    
    for(g=1;;g=g<<1){
        sort(sa,sa+len,cmp);
        for(int i=1;i<len;i++){
            pos[i]=pos[i-1]+cmp(sa[i-1],sa[i]);
        }
        
        for(int i=0;i<len;i++){
            rank[sa[i]]=pos[i];
        }
        
        if(pos[len-1]==len-1)break;
    }
    
    /*for(int i=0;i<len;i++){
        cout<<sa[i]<<endl;
    }*/
    
    for(int i=0;i<W;i++){
    
    int hi=len-1;
    int lo=0;
    int mid=(hi+lo)>>1;
    
    string p=P[i];
    
    int ret;
    
    while(hi>lo){
        ret=substrCmp(p,s.substr(sa[mid]));
        //cout<<p<<'\t'<<s.substr(sa[mid])<<'\t'<<mid<<endl;
        if(ret==1){lo=mid+1;}
        else {hi=mid;}
        mid=(hi+lo)>>1;
    }
    
    
    
    //cout<<endl<<s.substr(sa[lo])<<endl;
    int left=lo;
    
    ret=substrCmp(p,s.substr(sa[lo]));
    if(ret!=0){cout<<"0"<<endl;continue;}
    
    hi=len-1;
    mid=(hi+lo)>>1;
    while(hi>lo){
        //cout<<sa[lo]<<'\t'<<sa[hi]<<endl;
        ret=substrCmp(p,s.substr(sa[mid]));
        //cout<<p<<'\t'<<s.substr(sa[mid])<<'\t'<<mid<<endl;
        if(ret==0){lo=mid;}
        else{hi=mid-1;}
        if(mid==(hi+lo)>>1){if(substrCmp(p,s.substr(sa[hi]))==0)mid=hi;break;}
        mid=(hi+lo)>>1;
    }
    
    cout<<mid-left+1<<endl;
    }
    
}

