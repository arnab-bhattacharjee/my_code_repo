/*
ID: arnabbh1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
vector<pair<int,int> > v;

bool cmp(pair<int,int> p1,pair<int,int> p2){
    return (p1.first<p2.first);
}
int main(){
    ifstream fin("milk.in");
    ofstream fout("milk.out");
    int N,M;
    fin>>N>>M;
    v.resize(M);
    while(M--){
        fin>>v[M].first>>v[M].second;
    }
    
    sort(v.begin(),v.end(),cmp);
    
    int cost=0;
    for(int i=0;i<N;i++){
        if(N<v[i].second){
            cost+=N*v[i].first; break;
        } else{
            cost+=v[i].first*v[i].second;
            N-=v[i].second;
        }
    }
    
    fout<<cost<<endl;
}
