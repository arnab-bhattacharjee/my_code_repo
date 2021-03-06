/*
 	C++ Template
	Pradeep George Mathias
 */

/* Solution: Convert nodes into dfs-visit times. 
 * Then, a single node's subtree includes all the visit times in contiguous order: begin[] to end[]
 * Querying is then just a segment query, and node update
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
using namespace std;

#define s(T) scanf("%d", &T)
#define sl(T) scanf("%lld", &T)
#define fill(a, val) memset(a, val, sizeof(a))
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define DREP(x) sort(all(x)); x.erase(unique(all(x)), x.end())
#define INDEX(a, val) (lower_bound(all(a), val) - a.begin())

const int maxn = 100000;
const int maxm = 100000;
const int maxs = 20000;

int totalCases, testNum;
int N, M;

int skill[maxn+1];
vector<int> adjl[maxn+1];

int dfsno[maxn+1];
int begin[maxn+1];
int end[maxn+1];
int visited;

struct BIT 
{
	int val[1<<17];
	void init()
	{
		fill(val, 0);
	}
	
	int query(int pos)
	{
		int sum = 0;
		for(; pos > 0; pos -= pos & -pos)
			sum += val[pos];
		return sum;
	}
	
	void update(int pos, int incr)
	{
		for(; pos < 1<<17; pos += pos & -pos)
			val[pos] += incr;
	}
} B;

void preprocess()
{
	
}

bool input()
{
	s(N); s(M);
	assert(1 <= N && N <= maxn);
	assert(1 <= M && M <= maxm);
	
	for(int i = 1; i <= N; i++)
	{	
		s(skill[i]);
		assert(0 <= skill[i] && skill[i] <= maxs);
	}
	for(int i = 0; i < N-1; i++)
	{
		int u, v;
		s(u); s(v);
		assert(1 <= u && u <= N);
		assert(1 <= v && v <= N);
		assert(u != v);
		adjl[u].push_back(v);
		adjl[v].push_back(u);
	}
	return true;
}

void dfs(int u, int p)
{
	assert(dfsno[u] == 0);			//anti cycle check
	dfsno[u] = ++visited;
	for(int i = 0; i < adjl[u].size(); i++)
		if(adjl[u][i] != p)
			dfs(adjl[u][i], u);
	begin[u] = dfsno[u];
	end[u] = visited;
}

void solve()
{
	fill(dfsno, 0);
	dfs(1, 1);
	assert(visited == N);			//connected check
	
	B.init();
	for(int i = 1; i <= N; i++)
		B.update(dfsno[i], skill[i]);
	
	string type;
	int S, x;
	for(int i = 0; i < M; i++)
	{
		cin >> type; assert(type.length() == 1 && (type[0] == 'U' || type[0] == 'Q'));
		s(S); assert(1 <= S && S <= N);
		
		if(type[0] == 'U')
		{
			s(x); assert(0 <= x && x <= maxs);
			B.update(dfsno[S], x-skill[S]);
			skill[S] = x;
		}
		else 
			printf("%d\n", B.query(end[S]) - B.query(begin[S]-1));
	}
}

int main()
{
	preprocess();
	//s(totalCases);
	totalCases = 1;
	for(testNum = 1; testNum <= totalCases; testNum++)
	{
		if( !input())
			break;
		solve();
	}
}
