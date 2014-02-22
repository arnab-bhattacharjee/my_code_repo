#include <iostream>
#include <sstream>
using namespace std;

class SegmentTree{
    private:
    long *A,*M,*L,*R,*T;
    long n;
    void preprocess(long node,long lo,long hi);
    long *query(long node,long i,long j,long lo,long hi);
    void update(long node,long i,long val,long lo,long hi);
    public :
    SegmentTree(long *A,long n);
    void preprocess();
    long query(long i,long j);
    void printM();
    void update(long i,long val);
};

void SegmentTree::update(long i,long val){
    update(1,i,val,0,n-1);
}

void SegmentTree::update(long node,long idx,long val,long lo,long hi){
    if(lo==hi && idx==hi) M[node]=val, L[node]=val, R[node]=val, T[node]=val;
    else{
        long mid=(hi+lo)/2;
        if(idx<=mid) update(node*2,idx,val,lo,mid);
        else update(node*2+1,idx,val,mid+1,hi);
        
        //fix M[node]
        long left=M[2*node];
        long right=M[2*node+1];
        long max_lr=max(left,right);
        long tmp=R[2*node]+L[2*node+1];
        M[node]=max(max_lr,tmp);
        
        //fix L[node]
        tmp=T[node*2]+L[2*node+1];
        L[node]=max(tmp,L[node*2]);
        
        //fix R[node]
        tmp=T[node*2+1]+R[2*node];
        R[node]=max(tmp,R[2*node+1]);
        
        // fix T[node]
        T[node]=T[node*2]+T[node*2+1];
    }
}

long SegmentTree::query(long i,long j){
    long *a=query(1,i,j,0,n-1);
    
    return a[0];
}

long *SegmentTree::query(long node,long i,long j,long lo,long hi){
    //cout<<lo<<' '<<hi<<endl;
    if(i>hi || j<lo) return NULL;
    
    // 0-max 1-left 2-right 3-total
    long *temp=new long[4];
    if(i<=lo && j>=hi) {
        temp[0]=M[node], temp[1]=L[node], temp[2]=R[node], temp[3]=T[node];
        //cout<<temp[0]<<endl;;
        return temp;
    }
    long *left=query(node*2,i,j,lo,(hi+lo)/2);
    long *right=query(node*2+1,i,j,(hi+lo)/2+1,hi);
    if(left==NULL) return right;
    if(right==NULL) return left;
    
    //fix max
    long max_lr=max(left[0],right[0]);
    //cout<<lo<<"---"<<hi<<endl;
    //cout<<M[node*2]<<' '<<M[node*2+1]<<endl;
    long tmp1=left[2]+right[1];
    temp[0]=max(max_lr,tmp1);
    
    // fix left
    long tmp2=left[3]+right[1];
    temp[1]=max(tmp2,left[1]);
    
    //fix right
    long tmp3=left[2]+right[3];
    temp[2]=max(tmp3,right[2]);
    
    //fix total
    long tmp4=left[3]+right[3];
    temp[3]=tmp4;
    
    return temp;
}

void SegmentTree::printM(){
    for(long i=1;i<(n<<1);i++) cout<<M[i]<<'\t'<<L[i]<<'\t'<<R[i]<<'\t'<<T[i]<<endl;
}

SegmentTree::SegmentTree(long *A,long n){
    this->A=A;
    this->n=n;
    M=new long[n<<1], L=new long[n<<1], R=new long[n<<1], T=new long[n<<1];
}

void SegmentTree::preprocess(long node,long lo,long hi){
    if(hi==lo) M[node]=A[hi], L[node]=A[hi], R[node]=A[hi], T[node]=A[hi];
    else{
        preprocess(node*2,lo,(hi+lo)/2);
        preprocess(node*2+1,(hi+lo)/2+1,hi);
        
        //fix M[node]
        long left=M[2*node];
        long right=M[2*node+1];
        long max_lr=max(left,right);
        long mid=R[2*node]+L[2*node+1];
        M[node]=max(max_lr,mid);
        
        //fix L[node]
        long tmp=T[node*2]+L[2*node+1];
        L[node]=max(tmp,L[node*2]);
        
        //fix R[node]
        tmp=T[node*2+1]+R[2*node];
        R[node]=max(tmp,R[2*node+1]);
        
        // fix T[node]
        T[node]=T[node*2]+T[node*2+1];
    }
}

void SegmentTree::preprocess(){
    preprocess(1,0,n-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    stringstream ss;
    long n;
    cin>>n;
    long *a=new long[n];
    for(long i=0;i<n;i++) cin>>a[i];
    SegmentTree *seg_tree=new SegmentTree(a,n);
    seg_tree->preprocess();
    
    long m;
    cin>>m;
    while(m--){
        long i,j;
        cin>>i>>j;
        ss<<seg_tree->query(i-1,j-1)<<'\n';
    }
    cout<<ss.str();
    return 0;
}
