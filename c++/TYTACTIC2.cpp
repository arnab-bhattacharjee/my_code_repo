#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std ;
 
 
const int MAXN = 100000;
 
vector<vector<int> > G;
int arr[MAXN+5];
int n,qs;
 
int bit[MAXN+5];
int dfsNum[MAXN+5];
int sz[MAXN+5];
int tim;
 
void dfs(int u,int p)
{
dfsNum[u]=tim++;
sz[u] = 0;
for (int c=0;c<G[u].size();c++){
int v=G[u][c];
if (v == p)continue;
dfs(v,u);
sz[u]+=sz[v]+1;
}
return ;
}
void update(int i,int val)
{
for (i++;i<=n;i+=i&-i)
bit[i]+=val;
return;
}
int query(int i)
{
if (i<0)return 0;
int ret=0;
for (i++;i>0;i-=i&-i)
ret+=bit[i];
return ret;
}
 
 
int main()
{
int c,c2;
scanf("%d%d",&n,&qs);
for (c=0;c<n;c++)
scanf("%d",&arr[c]);
G.resize(n);
for (c=0;c+1<n;c++){
int from,to;
scanf("%d%d",&from,&to);
from --;to --;
G[from].push_back(to);
G[to].push_back(from);
}
tim=0;
dfs(0,-1);
for (c=0;c<n;c++)
update(dfsNum[c],arr[c]);
for (c=0;c<qs;c++){
char ch;
int node,val;
scanf(" %c%d",&ch,&node);
node --;
if (ch == 'Q')
printf("%d\n",query(dfsNum[node]+sz[node])-query(dfsNum[node]-1));
else {
scanf("%d",&val);
val-=arr[node];
arr[node]+=val;
update(dfsNum[node],val);
}
}
return 0;
}