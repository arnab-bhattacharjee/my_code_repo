/*
ID: arnabbh1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
int main(){
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");
    int M,S,C;
    fin>>M>>S>>C;
    if(M>=C){ fout<<C<<endl; return 0;}
    int *a=new int[C];
    int *b=new int[C];
    for(int i=0;i<C;i++) fin>>a[i];
    
    sort(a,a+C);
    
    int interval=a[C-1]-a[0]+1;
    
    for(int i=1;i<C;i++) b[i]=a[i]-a[i-1]-1;
    
    sort(b+1,b+C);
    
    //for(int i=0;i<C;i++) cout<<b[i]<<' ';
    
    int max=0;
    for(int i=0;i<M-1;i++) max+=b[C-1-i];
    
    fout<<interval-max<<endl;
}
