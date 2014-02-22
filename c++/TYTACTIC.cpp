#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
vector<int>* g;
int V,M;
int* begin_time;
int* end_time;
int* tree;
int* skill;
int t;
#define Rep(i,x) for(int i=0;i<x;i++)

void update(int idx, int diff){
    while(idx<V+1){
      tree[idx]+=diff; idx+=idx & -idx;
    }
}

int get(int idx){
   int cf=0;
   while(idx>0){
       cf+=tree[idx]; idx-=idx & -idx;
   }
   return cf;
}


void input(){
    cin>>V>>M;
    int u,v;
    
    tree=new int[V+1];
    skill=new int[V+1];
    
    memset(tree,0,sizeof(int)*(V+1));
    memset(skill,0,sizeof(int)*(V+1));
    
    Rep(i,V){
        cin>>skill[i+1];
    }
    
    g=new vector<int>[V+1];
    Rep(i,V-1){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void dfs(int u, int p){
    begin_time[u]=++t;
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
    
    Rep(i,V){update(begin_time[i+1],skill[i+1]);}
}

int main(){
    input();
    solve();
    
    while(M--){
        char c;int s,x;
        cin>>c;
        if(c=='Q'){
            cin>>s;
            cout<<get(end_time[s])-get(begin_time[s]-1)<<endl;
        } else{
            cin>>s>>x;
            update(begin_time[s],x-skill[s]);
            skill[s]=x;
        }
    }
} 