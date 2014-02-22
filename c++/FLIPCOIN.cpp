#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sstream>
using namespace std;
#define getcx getchar_unlocked
#define putcx putchar_unlocked
inline void readInt( int &n ) {
    n=0;
    int ch=getcx();
    while( ch < '0' || ch > '9' ){ch=getcx();}
    while( ch >= '0' && ch <= '9' )
    n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
}

class SegTreeNode{
    public:
    bool flag;
    int count;
    SegTreeNode(){flag=false, count=0;}
};

class SegTree{
    private:
    SegTreeNode M[300000];
    int n;
    void update(int node,int lo,int hi,int i,int j);
    int query(int node,int lo,int hi,int i,int j);
    public:
    void print();
    SegTree(int n);
    void update(int i,int j);
    int query(int i,int j);
};

SegTree::SegTree(int n){
    this->n=n;
}

void SegTree::print(){
    for(int i=1;i<(n<<2);i++) cout<<i<<'\t'<<M[i].count<<'\t'<<M[i].flag<<endl;
}

void SegTree::update(int node,int lo,int hi,int i,int j){
    //cout<<"lo"<<lo<<'\t'<<"hi:"<<hi<<endl;
    if(hi<i || lo>j) return;
    if(lo>=i && hi<=j){
            M[node].count=hi-lo+1-M[node].count;
            if(!(hi==lo)){
                M[node].flag=!(M[node].flag);
            }
    } else{
        if(M[node].flag){
            //cout<<lo<<'\t'<<hi<<endl;
            M[node].flag=false;
            int mid=(lo+hi)>>1;
	        if(!(mid==lo)) M[node*2].flag=!(M[node*2].flag);
            if(!(mid+1==hi)) M[node*2+1].flag=!(M[node*2+1].flag);

            M[node*2].count=mid-lo+1-M[node*2].count;
            M[node*2+1].count=hi-mid-M[node*2+1].count;
        }
        update(node*2,lo,(lo+hi)/2,i,j);
        update(node*2+1,(lo+hi)/2+1,hi,i,j);
        M[node].count=M[node*2].count+M[node*2+1].count;
    }
}

int SegTree::query(int node,int lo,int hi,int i,int j){
    if(hi<i || lo>j) return 0;
    if(lo>=i && hi<=j){
        //cout<<lo<<'\t'<<hi<<'\t'<<M[node]->count<<endl;
        return M[node].count;
    } else{
        int mid=(hi+lo)>>1;
        if(M[node].flag){
            M[node].flag=false;
            if(!(mid==lo)) M[node*2].flag=!(M[node*2].flag);
            if(!(mid+1==hi)) M[node*2+1].flag=!(M[node*2+1].flag);

            M[node*2].count=mid-lo+1-M[node*2].count;
            M[node*2+1].count=hi-mid-M[node*2+1].count;
        }
        int leftCount=query(node<<1,lo,mid,i,j);
        int rightCount=query((node<<1)+1,mid+1,hi,i,j);
        //cout<<lo<<'\t'<<hi<<endl;
        //cout<<leftCount<<'\t'<<rightCount<<endl<<endl;
        return leftCount+rightCount;
    }
}

int SegTree::query(int i,int j){
    query(1,0,n-1,i,j);
}

void SegTree::update(int i,int j){
    update(1,0,n-1,i,j);
}

int main(){
    stringstream ss;
    int n,q;
    readInt(n); readInt(q);
    SegTree s(n);
    while(q--){
        int qType,i,j;
        readInt(qType); readInt(i); readInt(j);
        if(qType==0) s.update(i,j);
        if(qType==1) ss<<s.query(i,j)<<'\n';
    }
    cout<<ss.str();
}

