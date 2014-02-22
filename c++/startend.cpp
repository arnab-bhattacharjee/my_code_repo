#include <iostream>
#include <vector>
using namespace std;
vector<int>* g;
int V;
int* begin_time;
int* end_time;
int t=1;
#define Rep(i,x) for(int i=0;i<x;i++)
void input(){
    cin>>V;
    int u,v;
    g=new vector<int>[V+1];
    Rep(i,V-1){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void dfs(int u, int p){
    begin_time[u]=t++;
    cout<<u<<'\t'<<t<<endl;
    Rep(i,g[u].size()){
        if(g[u][i]!=p){
            dfs(g[u][i],u);
        }
    }
    end_time[u]=t;
}

void solve(){
    begin_time=new int[V+1];
    end_time=new int[V+1];
    
    dfs(1,-1);
}

int main(){
    input();
    solve();
    
    Rep(i,V+1)cout<<begin_time[i]<<'\t';
    cout<<endl;
    Rep(i,V+1)cout<<end_time[i]<<'\t';
}