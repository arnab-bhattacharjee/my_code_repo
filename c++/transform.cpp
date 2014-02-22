/*
ID: arnabbh1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

void rotate(char **a,char **b,int n){
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) b[j][n-1-i]=a[i][j];
}

bool equals(char **a,char **b,int n){
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(a[i][j]!=b[i][j]) return false;
    return true;
}

void reflect(char **a, char **b,int n){
    for(int i=0;i<n;i++) for(int j=0;j<=(n>>1);j++){
        b[i][n-1-j]=a[i][j];
        b[i][j]=a[i][n-1-j];
    }
}

int main(){
  
    ifstream fin("transform.in");
    ofstream fout("transform.out");
    int n;
    fin>>n;
    char **a=new char*[n];char **g=new char*[n];char **b=new char*[n]; char **tmp=new char*[n];
    
    for(int i=0;i<n;i++) a[i]=new char[n], b[i]=new char[n], g[i]=new char[n], tmp[i]=new char[n];
    
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) fin>>a[i][j];
    
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) fin>>g[i][j];
    
    
    
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) tmp[i][j]=a[i][j];
    
    for(int i=1;i<4;i++){
        rotate(tmp,b,n);
	//for(int j=0;j<n;j++){ for(int k=0;k<n;k++) fout<<b[j][k]; fout<<endl;}
	//fout<<endl;
	for(int j=0;j<n;j++) for(int k=0;k<n;k++) tmp[j][k]=b[j][k];
        if(equals(b,g,n)){ fout<<i<<endl; return 0;}
    }

    for(int i=0;i<n;i++) for(int j=0;j<n;j++) tmp[i][j]=a[i][j];

    reflect(tmp,b,n);
    //for(int j=0;j<n;j++){ for(int k=0;k<n;k++) fout<<b[j][k]; fout<<endl;}fout<<endl;
    if(equals(b,g,n)){ fout<<"4"<<endl; return 0;}
    
    for(int j=0;j<n;j++) for(int k=0;k<n;k++) tmp[j][k]=b[j][k];
    for(int i=1;i<4;i++){
        rotate(tmp,b,n);
	//for(int j=0;j<n;j++){ for(int k=0;k<n;k++) fout<<b[j][k]; fout<<endl;}fout<<endl;
	for(int j=0;j<n;j++) for(int k=0;k<n;k++) tmp[j][k]=b[j][k];
        if(equals(b,g,n)){ fout<<"5"<<endl; return 0;}
    }
    
    if(equals(a,g,n)){ fout<<"6"<<endl; return 0;}
    
    fout<<"7"<<endl; return 0;
}