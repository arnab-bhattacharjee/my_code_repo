#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return (a[first]<b[first]);
}

int main(){
    vector<int> factors[100000];
    for(int i=1;i<=100000;i++){
        for(int j=i;j<=100000;j+=i){
            factors[j-1].push_back(i);
        }
    }
    
    /*for(int i=0;i<factors[71].size();i++){
        cout<<factors[71][i]<<endl;
    }*/
    
    int N,Q;
    cin>>N>>Q;
    
    int* num=new int[N];
    for(int i=0;i<N;i++)cin>>num[i];
    
    int* L=new int[Q];
    int* R=new int[Q];
    int* K=new int[Q];
    
    vector<pair<int,int> > v;
    map<int,int> m;
    
    for(int i=0;i<Q;i++){
        cin>>L[i]>>R[i]>>K[i];
        pair<int,int> p;
        p.first=L[i];p.second=K[i];
        v.push_back(p);
        m.insert(p);
        p.first=R[i];
        v.push_back(p);
        m.insert(p);
    }
    
    sort(v.begin(),v.end(),cmp);
    int t[100000];
    for(int i=0;i<100000;i++){
        for(int j=0;j<factors[a[i]-1].size();j++){
            t[factors[a[i-1][j]]]++;
        }
        if(i==v[first]-1)
    }
}
