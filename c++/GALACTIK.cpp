#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
#define Rep(i,x) for(int i=0;i<x;i++)
int N,M;
int* cost;
vector<vector<int> > g;
int* mark;
int* CC;
int cc;
vector<pair<int,int> > a;
void dfs(int u){
    Rep(i,g[u].size()){
        if(mark[g[u][i]]==0){
            mark[g[u][i]]=1;
            CC[g[u][i]]=cc;
            dfs(g[u][i]);
        }
    }
}

bool cmp(pair<int,int> i,pair<int,int> j){
    return (i.first<j.first);
}

int main(){
    std::cout.sync_with_stdio(false);
    cin>>N>>M;
    if(N==1){cout<<"0"<<endl;return 0;}
    g.resize(N);
    cost=new int[N];
    mark=new int[N];
    CC=new int[N];
    memset(mark,0,sizeof(int)*N);
    int u,v;
    while(M--){
        //cout<<"here";
        cin>>u>>v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    int min_cost=10000;
    
    //cout<<N<<endl<<endl;
    
    Rep(i,N){
        cin>>cost[i];
        if(cost[i]<0) cost[i]=10001;
        if(min_cost>cost[i])min_cost=cost[i];
    }
    
    cc=-1;
    
    Rep(i,N){
       // cout<<i<<endl;
        if(mark[i]==0){
            cc++;
            //cout<<"cc : "<<cc<<endl;
            mark[i]=1;
            CC[i]=cc;
            dfs(i);
        }
    }
    
    /*Rep(i,N){
        cout<<CC[i]<<'\t';
    }cout<<endl;*/
    
    //cout<<min_cost<<endl;
    cc++;
    //cout<<cc<<endl;
    a.resize(cc);
    
    Rep(i,cc)a[i].first=10001;
    
    Rep(i,N){
        if(a[CC[i]].first>cost[i])a[CC[i]].first=cost[i];
        a[CC[i]].second++;
    }
    
   // Rep(i,cc)cout<<a[i].first<<','<<a[i].second<<'\t';cout<<endl;
    
    Rep(i,cc){
        if(a[i].first>10000){cout<<"-1"<<endl;return 0;}
    }

    sort(a.begin(),a.end(),cmp);
    
    //Rep(i,cc)cout<<a[i].first<<','<<a[i].second<<'\t';cout<<endl;
    //cout<<endl;
    
    long long count=0;
    
    Rep(i,cc){
        count+=(cc-1)*a[i].first;
    }
    
    cout<<count<<endl;
    return 0;
}