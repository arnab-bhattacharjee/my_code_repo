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
    cin>>N>>M;
    g.resize(N);
    cost=new int[N];
    mark=new int[N];
    CC=new int[N];
    memset(mark,0,sizeof(int)*N);
    int u,v;
    while(M--){
        cin>>u>>v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    int min_cost=10000;
    
    Rep(i,N){cin>>cost[i];if(min_cost>cost[i])min_cost=cost[i];}
    
    cc=-1;
    
    Rep(i,N){
        if(mark[i]==0){
            cc++;
            dfs(i);
        }
    }
    
    Rep(i,N){
        cout<<CC[i]<<'\t';
    }cout<<endl;
    
    cout<<min_cost<<endl;
    cc++;
    a.resize(cc);
    //memset(size,0,sizeof(cc));
    
    Rep(i,cc)a[i].first=10000;
    
    Rep(i,N){
        if(a[CC[i]].first>cost[i])a[CC[i]].first=cost[i];
        a[CC[i]].second++;
    }
    
    Rep(i,cc)cout<<a[i].first<<','<<a[i].second<<'\t';cout<<endl;
    
    //sort(mins,mins+cc);
    //Rep(i,cc)cout<<mins[i]<<'\t';cout<<endl;
    sort(a.begin(),a.end(),cmp);
    
    Rep(i,cc)cout<<a[i].first<<','<<a[i].second<<'\t';cout<<endl;
    cout<<endl;
    
    int count=0;
    
    int* cf=new int[cc];
    
    cf[0]=a[0].second;
    
    for(int i=1;i<cc;i++){
        cf[i]=cf[i-1]+a[i].second;
    }
    
    Rep(i,cc)cout<<cf[i]<<'\t';cout<<endl;
    
    int i=0;
    
    while(i<cc){
        if(a[i].first==min_cost){count+=min_cost*(cf[cc-1]-cf[i]);i++;}
        else break;
    }
    
    if(i==cc) {cout<<count<<endl;return 0;}
    
    while(i<cc){
        if(a[i].first<min_cost<<1){count+=a[i].first*(cf[cc-1]-cf[i]);i++;}
        else break;
    }
    
    if(i==cc) {cout<<count<<endl;return 0;}
    
    while(i<cc){
        count+=2*min_cost*(cf[cc-1]-cf[i]);
        i++;
    }
    
    cout<<count<<endl;
    
}
