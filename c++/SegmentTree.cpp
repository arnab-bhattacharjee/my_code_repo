#include <iostream>

using namespace std;

class SegmentTree{
    private:
    int *A,*M;
    int n;
    void preprocess(int node,int hi,int lo);
    int query(int node,int i,int j,int hi,int lo);
    public:
    void printM(){for(int i=1;i<2*n;i++) cout<<M[i]<<endl;}
    SegmentTree(int *A,int n);
    void preprocess();
    int query(int i,int j);
};

SegmentTree::SegmentTree(int *A,int n){
    this->A=A;
    this->n=n;
    M=new int[2*n];
}

void SegmentTree::preprocess(int node,int hi,int lo){
    //cout<<hi<<' '<<lo<<endl;
    if(hi==lo) M[node]=hi;
    else{
        preprocess(node<<1,(hi+lo)>>1,lo);
        preprocess((node<<1)+1,hi,((hi+lo)>>1)+1);
        if(A[M[node<<1]]<A[M[(node<<1)+1]]) M[node]=M[node<<1];
        else{M[node]=M[(node<<1)]+1;}
    }
}

int SegmentTree::query(int node,int i,int j,int hi,int lo){
    //cout<<hi<<' '<<lo<<endl;
    if(hi<=j && lo>=i) return M[node];
    if(hi<i || lo>j) return -1;
    int p1=query(node*2,i,j,(hi+lo)/2,lo);
    int p2=query(node*2+1,i,j,hi,((hi+lo)/2)+1);
    if(p1==-1) return p2;
    if(p2==-1) return p1;
    if(A[p1]<=A[p2]) return p1;
    else return p2;
}

int SegmentTree::query(int i,int j){
    return query(1,i,j,n-1,0);
}

void SegmentTree::preprocess(){
    preprocess(1,n-1,0);
}

int main(){
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    SegmentTree* seg_tree=new SegmentTree(a,n);
    seg_tree->preprocess();
    seg_tree->printM();
    int idx=seg_tree->query(6,8);
    cout<<idx<<' '<<a[idx];
}
