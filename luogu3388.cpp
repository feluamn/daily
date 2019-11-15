#include<bits/stdc++.h>
#define LL long long
#define P pair<int,int>
#define fi first
#define se second
const LL N=2e5+10;
const LL mod=1e9+7;
const LL inf=0x3f3f3f;
const double eps=1e-9;
using namespace std;
template<typename tp> inline void read(tp &x)
{
    x=0;char c=getchar();
    bool f=0; for(; c<'0'||c>'9'; f|=(c=='-'),c = getchar());
    for(; c>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0',c = getchar());
    if(f) x=-x;
}
vector<int> GD;
int n,m,vis[N];
struct Edge{int next,to;} edge[N<<1];
int head[N],cnt,dfn[N],low[N],dfns;
void add(int from,int to) { edge[++cnt]={head[from],to}; head[from]=cnt;}
void insert(int from,int to) { add(from,to); add(to,from);}
void dfs(int now,int fa)
{
	vis[now]=1;
	dfn[now]=low[now]=++dfns;
	int son=0;
	for(int i=head[now];i;i=edge[i].next)
	{
		int to=edge[i].to;
		if(to==fa) continue;
		if(!vis[to])
		{
			dfs(to,now);
			low[now]=min(low[now],low[to]);
			if(low[to]>dfn[now]) son++;
		}
		else low[now]=min(low[now],dfn[to]);
	}
	if(son>=2||(son&&fa))
		GD.push_back(now);
}
void tarjan()
{
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs(i,0);
}
signed main()
{
	read(n),read(m);
	for(int i=1,u,v;i<=m;i++) read(u),read(v),insert(u,v);
	tarjan();
	sort(GD.begin(),GD.end());
	printf("%d\n",GD.size());
	for(int i=0;i<GD.size();i++)
		printf("%d ",GD[i]); puts("");
	return 0;
}
