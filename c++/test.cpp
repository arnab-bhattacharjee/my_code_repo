#include <iostream>
#include <sstream>
#include <cstdio>
using namespace std;

class SegmentTree{
    private:
    int *A,*M,*L,*R,*T;
    int n;
    void preprocess(int node,int lo,int hi);
    int *query(int node,int i,int j,int lo,int hi);
    //void update(int node,int i,int val,int lo,int hi);
    public :
    SegmentTree(int *A,int n);
    void preprocess();
    int query(int i,int j);
    void printM();
    //void update(int i,int val);
    ~SegmentTree();
};

/*void SegmentTree::update(int i,int val){
    update(1,i,val,0,n-1);
}

void SegmentTree::update(int node,int idx,int val,int lo,int hi){
    if(lo==hi && idx==hi) M[node]=val, L[node]=val, R[node]=val, T[node]=val;
    else{
        int mid=(hi+lo)/2;
        if(idx<=mid) update(node*2,idx,val,lo,mid);
        else update(node*2+1,idx,val,mid+1,hi);
        
        //fix M[node]
        int left=M[2*node];
        int right=M[2*node+1];
        int max_lr=max(left,right);
        int tmp=R[2*node]+L[2*node+1];
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
}*/

int SegmentTree::query(int i,int j){
    int *a=query(1,i,j,0,n-1);
    
    return a[0];
}

int *SegmentTree::query(int node,int i,int j,int lo,int hi){
    //cout<<lo<<' '<<hi<<endl;
    if(i>hi || j<lo) return NULL;
    
    // 0-max 1-left 2-right 3-total
    int *temp=new int[4];
    if(i<=lo && j>=hi) {
        temp[0]=M[node], temp[1]=L[node], temp[2]=R[node], temp[3]=T[node];
        //cout<<temp[0]<<endl;;
        return temp;
    }
    int *left=query(node*2,i,j,lo,(hi+lo)/2);
    int *right=query(node*2+1,i,j,(hi+lo)/2+1,hi);
    if(left==NULL){temp[0]=right[0],temp[1]=right[1],temp[2]=right[2],temp[3]=right[3]; return temp;}
    if(right==NULL){temp[0]=left[0],temp[1]=left[1],temp[2]=left[2],temp[3]=left[3]; return temp;}
    
    //fix max
    int max_lr=max(left[0],right[0]);
    //cout<<lo<<"---"<<hi<<endl;
    //cout<<M[node*2]<<' '<<M[node*2+1]<<endl;
    int tmp1=left[2]+right[1];
    temp[0]=max(max_lr,tmp1);
    
    // fix left
    int tmp2=left[3]+right[1];
    temp[1]=max(tmp2,left[1]);
    
    //fix right
    int tmp3=left[2]+right[3];
    temp[2]=max(tmp3,right[2]);
    
    //fix total
    int tmp4=left[3]+right[3];
    temp[3]=tmp4;
    
    delete left;
    delete right;
    
    return temp;
}

void SegmentTree::printM(){
    for(int i=1;i<(n<<2);i++) cout<<M[i]<<'\t'<<L[i]<<'\t'<<R[i]<<'\t'<<T[i]<<endl;
}

SegmentTree::~SegmentTree(){
    delete L;delete R;delete T;delete M;
}

SegmentTree::SegmentTree(int *A,int n){
    this->A=A;
    this->n=n;
    M=new int[n<<2], L=new int[n<<2], R=new int[n<<2], T=new int[n<<2];
}

void SegmentTree::preprocess(int node,int lo,int hi){
    //cout<<lo<<' '<<hi<<' '<<node<<endl;
    if(hi==lo) M[node]=A[hi], L[node]=A[hi], R[node]=A[hi], T[node]=A[hi];
    else{
        preprocess(node*2,lo,(hi+lo)/2);
        preprocess(node*2+1,(hi+lo)/2+1,hi);
        
        //fix M[node]
        int left=M[2*node];
        int right=M[2*node+1];
        int max_lr=max(left,right);
        int mid=R[2*node]+L[2*node+1];
        M[node]=max(max_lr,mid);
        
        //fix L[node]
        int tmp=T[node*2]+L[2*node+1];
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
    int n;
    scanf("%d",&n);
    int *a=new int[n];
    for(int i=0;i<n;i++){ scanf("%d",&a[i]);}
    SegmentTree *seg_tree=new SegmentTree(a,n);
    seg_tree->preprocess();
    
    int m;
    scanf("%d",&m);
    while(m--){
        int i,j;
        scanf("%d %d",&i,&j);
        printf("%d\n",seg_tree->query(i-1,j-1));
    }
    delete seg_tree;
    delete a;
    return 0;
}
