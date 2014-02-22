#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
#define MAXHEALTH 1000000000
vector<vector<int> > g;
vector<int> a;
int *s,*s_inv;
int *f,*f_inv;
int t=0;
void dfs(int u,int v){
    s[u]=t; t++;
    for(int i=0;i<g[u].size();i++){
        dfs(g[u][i],u);
    }
    f[u]=t;
}

class SegTreeNode{
    public:
    int count;
    int flag;
    int min;
    SegTreeNode(){
        count=0; flag=0; min=MAXHEALTH+1;
    }
};

class SegTree{
    private:
    SegTreeNode M[300000];
    int n;
    void update(int node,int lo,int hi,int i,int j,int X);
    int query(int node,int lo,int hi,int i,int j);
    void preprocess(int node,int lo,int hi);
    void upgrade(int node,int lo,int hi);
    public:
    SegTree(int n){this->n=n; preprocess(1,0,n-1);}
    void update(int i,int j,int X);
    int query(int i,int j);
    void print();
};

void SegTree::print(){
    for(int i=1;i<(n<<2);i++)
        cout<<i<<"   "<<"count:"<<M[i].count<<" flag:"<<M[i].flag<<" min:"<<M[i].min<<endl;
}

void SegTree::preprocess(int node,int lo,int hi){
    //cout<<lo<<'\t'<<hi<<endl;
    if(lo==hi){ M[node].count++; M[node].min=a[s_inv[lo]]; return;}
    
    int mid=(lo+hi)>>1;
    preprocess(node*2,lo,mid);
    preprocess(node*2+1,mid+1,hi);
    
    M[node].count=M[2*node].count+M[2*node+1].count;
    M[node].min=min(M[2*node].min,M[2*node+1].min);
}

void SegTree::update(int i,int j,int X){
    update(1,0,n-1,i,j,X);
}

void SegTree::update(int node,int lo,int hi,int i,int j,int X){
    //cout<<lo<<'\t'<<hi<<endl;
    if(hi<i || lo>j) return;
    int mid=(lo+hi)>>1;
    if(lo>=i && hi<=j){
      if(M[node].count==0) return;
      if(lo!=hi) M[node].flag+=X;
      M[node].min-=X;
      while(M[node].min<=0) upgrade(node,lo,hi);
    } else{
      if(M[node].count==0) return;
      if(M[node].flag){
        if(mid!=lo){M[node*2].flag+=M[node].flag;}
    	if(mid+1!=hi){M[node*2+1].flag+=M[node].flag;}
    	M[node*2].min-=M[node].flag;
    	M[node*2+1].min-=M[node].flag;
    	M[node].flag=0;
      }
      update(node*2,lo,mid,i,j,X);
      update(node*2+1,mid+1,hi,i,j,X);
      M[node].min=min(M[2*node].min,M[2*node+1].min);
      M[node].count=M[node*2].count+M[node*2+1].count;
    }
}

void SegTree::upgrade(int node,int lo,int hi){
    //cout<<"upgrade"<<lo<<'\t'<<hi<<endl;
  if(lo==hi){/*cout<<lo<<endl;*/ M[node].count=0, M[node].min=MAXHEALTH+1; return;}
  int mid=(lo+hi)/2;
  if(lo!=mid) M[2*node].flag+=M[node].flag;
  if(mid+1!=hi) M[2*node+1].flag+=M[node].flag;
  M[2*node].min-=M[node].flag;
  M[2*node+1].min-=M[node].flag;
  if(M[2*node].min==M[node].min) upgrade(2*node,lo,mid);
  else upgrade(2*node+1,mid+1,hi);
  M[node].flag=0; M[node].count=M[2*node].count+M[2*node+1].count;
  M[node].min=min(M[2*node].min,M[2*node+1].min);
}

int SegTree::query(int node,int lo,int hi,int i,int j){
    if(hi<i || lo>j) return 0;
    if(lo>=i && hi<=j) return M[node].count;
    int mid=(lo+hi)>>1;
    int leftCount=query(node*2,lo,mid,i,j);
    int rightCount=query(node*2+1,mid+1,hi,i,j);
    return leftCount+rightCount;
}

int SegTree::query(int i,int j){
    return query(1,0,n-1,i,j);
}

int main(){
    ios_base::sync_with_stdio(false);
    stringstream ss;
    int N;
    cin>>N;
    s=new int[N+1]; f=new int[N+1]; s_inv=new int[N+1];
    s[0]=0;
    g.resize(N+1);
    a.resize(N+1);
    a[0]=MAXHEALTH+1;
    for(int i=0;i<N;i++){
        int h,s;
        cin>>h>>s;
        g[s].push_back(i+1);
        a[i+1]=h;
    }
    dfs(0,-1);
    for(int i=0;i<N+1;i++) s_inv[s[i]]=i;
    
    SegTree seg_tree(N+1);
    int Q;
    cin>>Q;
    while(Q--){
        int q_type;
        cin>>q_type;
        int a,x;
        if(q_type==1){
            cin>>a>>x;
            //cout<<s[a]+1<<'\t'<<f[a]-1<<endl;
	    if((s[a]+1)==f[a]) continue;
            seg_tree.update(s[a]+1,f[a]-1,x);
            //seg_tree.print(); cout<<endl<<endl;
        }
        else{
	  cin>>a;
	  if(s[a]+1==f[a]){ss<<"0"<<'\n'; continue;}
	  ss<<seg_tree.query(s[a]+1,f[a]-1)<<'\n';}
    }
    //cout<<"here"<<endl;
    cout<<ss.str();
    return 0;
}