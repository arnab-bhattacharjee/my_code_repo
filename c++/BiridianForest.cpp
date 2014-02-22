#include <iostream>
#include <vector>
#include <set>
#include <string.h>
using namespace std;
vector<vector<int> > g;
int r,c;
int* d;
void dfs()

int main(){
    cin>>r>>c;
    g.resize(r*c);
    char** a=new char*[r];
    d=new int[];
    for(int i=0;i<r;i++){
        a[i]=new char[c];
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin<<a[i][j];
        }
    }
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i-1>=0 && a[i-1][j]!='T'){
                g[i*c+j].push_back((i-1)*c+j);
            }
            if(i+1<r && a[i+1][j]!='T'){
                g[i*c+j].push_back((i+1)*c+j);
            }
            if(j-1>=0 && a[i][j-1]!='T'){
                g[i*c+j].push_back(i*c+j-1);
            }
            if(j+1<c && a[i][j+1]!='T'){
                g[i*c+j].push_back(i*c+j+1);
            }
        }
    }
    
}
