#include <iostream>
using namespace std;
int N;
char **a;
void printMines(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<a[i][j];
        }
    cout<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin>>N;
    a=new char*[N];
    int **count=new int*[N];
    for(int i=0;i<N;i++) a[i]=new char[N], count[i]=new int[N];
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) cin>>a[i][j];
    for(int i=0;i<N;i++) for(int j=0;j<N;j++){
        count[i][j]=0;
        if(i-1>=0 && a[i-1][j]=='*') count[i][j]++;
        if(j-1>=0 && a[i][j-1]=='*') count[i][j]++;
        if(i-1>=0 && j-1>=0 && a[i-1][j-1]=='*') count[i][j]++;
        if(i+1<N && a[i+1][j]=='*') count[i][j]++;
        if(j+1<N && a[i][j+1]=='*') count[i][j]++;
        if(i+1<N && j+1<N && a[i+1][j+1]=='*') count[i][j]++;
        if(i-1>=0 && j+1<N && a[i-1][j+1]=='*') count[i][j]++;
        if(i+1<N && j-1>=0 && a[i+1][j-1]=='*') count[i][j]++;
    }
    //for(int i=0;i<N;i++){ for(int j=0;j<N;j++) cout<<count[i][j]<<'\t'; cout<<endl;}
    char **b=new char*[N];
    for(int i=0;i<N;i++) b[i]=new char[N];
    for(int i=0;i<N;i++) for(int j=0;j<N;j++){cin>>b[i][j]; if(b[i][j]=='x' && a[i][j]=='*'){ printMines(); return 0;}}
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(b[i][j]=='x') cout<<count[i][j];
            else cout<<'.';
        }
        cout<<endl;
    }
    return 0;
}