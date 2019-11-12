#include<bits/stdc++.h>
#define LL long long
#define P pair<int,int>
#define fi first
#define se second
const LL N=2e3+10;
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
int n,m,k,ans;
struct Edge{int next,to;} edge[260000];
int head[N],cnt,fa[N],vis[N],anss[N];
void add(int from,int to) { edge[++cnt]={head[from],to}; head[from]=cnt;}
bool find(int now)
{
	if(!fa[now]) return true;
	vis[now]=1;
	for(int i=head[fa[now]];i;i=edge[i].next)
	{
		int to=edge[i].to;
		if(vis[to]) continue;
		if(find(to))
		{
			fa[to]=fa[now];
			return true;
		}
	}
	return false;
}
signed main()
{
	read(n),read(m),read(k);
	for(int i=1,u,v;i<=k;i++) read(u),read(v),add(u,v+n);
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=head[i];j;j=edge[j].next)
		{
			int to=edge[j].to;
			if(find(to))
			{
				fa[to]=i; 
				ans++;
				break;
			}
		}
	}
	for(int i=n+1;i<=m+n;i++) anss[fa[i]]=i-n;
	printf("%d\n",ans);
	for(int i=1;i<=n;i++) printf("%d ",anss[i]); puts("");
	return 0;
}
