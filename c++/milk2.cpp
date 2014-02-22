/*
ID: arnabbh1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> p1,pair<int,int> p2){
  if(p1.first!=p2.first) return (p1.first<p2.first);
  else return (p1.second>p2.second);
}

int main(){
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");
    int n;
    fin>>n;
    vector <pair<int,int> > v(n);
    int rightmost=0;
    for(int i=0;i<n;i++){
        fin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end(),cmp);

    //for(int i=0;i<v.size();i++) fout<<v[i].first<<" "<<v[i].second<<endl;

    
    vector<pair<int,int> > a;
    rightmost=v[0].second;
    a.push_back(v[0]);
    for(int i=1;i<n;i++){
      if(v[i].second>rightmost){ a.push_back(v[i]); rightmost=v[i].second;}
    }
    
    //for(int i=0;i<a.size();i++) fout<<a[i].first<<" "<<a[i].second<<endl;
    
    int maxMilkingTime=a[0].second-a[0].first,maxNonMilkingTime=0,milkingTime=a[0].second-a[0].first;
    int i=0;
    while(i<a.size()-1){
        if(a[i].second>=a[i+1].first){
            milkingTime+=a[i+1].second-a[i].second;
            maxMilkingTime=(milkingTime>maxMilkingTime)?milkingTime:maxMilkingTime;
        }
        else {
            maxNonMilkingTime=((a[i+1].first-a[i].second)>maxNonMilkingTime)?(a[i+1].first-a[i].second):maxNonMilkingTime;
            milkingTime=a[i+1].second-a[i+1].first;
        }
         i++;
    }
    fout<<maxMilkingTime<<' '<<maxNonMilkingTime<<endl;
}