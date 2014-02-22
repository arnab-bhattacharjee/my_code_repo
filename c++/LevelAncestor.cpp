#include <iostream>
#include <vector>
using namespace std;
vector<vector <int> > g;
int n;
int* parent;

void dfs(int u,int p){
    parent[u]=p;
    for(int i=0;i<g[u].size();i++){
        if(g[u][i]!=p){
            dfs(g[u][i],u);
        }
    }
}

int main(){
    cin>>n;
    g.resize(n);
    int u,v;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    parent=new int[n];
    
    dfs(0,-1);
    
    /*for(int i=0;i<n;i++){
        cout<<parent[i]<<'\t';
    }
    cout<<endl;*/
    
    int logarithm=0;
    int a=n-1;
    for(;a>0;logarithm++,a=a>>1);
    //cout<<logarithm;
    
    int** P=new int*[n];
    for(int i=0;i<n;i++){P[i]=new int[logarithm];}
    
    for(int i=0;i<n;i++)P[i][0]=parent[i];
    
    for(int i=0;i<n;i++){
        for(int j=1;j<logarithm;j++){
            if(P[i][j-1]>0){
            P[i][j]=P[P[i][j-1]][j-1];
            } else{
                P[i][j]=-1;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<logarithm;j++){
            cout<<P[i][j]<<'\t';
        }
        cout<<endl;
    }
    
}