#include<bits/stdc++.h>
#define LL long long
#define P pair<int,int>
#define fi first
#define se second
const LL N=1e5+10;
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
int p[N],num,vis[N];
int n,head[N],cnt;
LL ans,sb=1;
map<LL,LL> Map,anss;
struct Edge{int next,to,cost;} edge[N<<1];
void add(int from,int to,int cost) { edge[++cnt]={head[from],to,cost}; head[from]=cnt;}
void insert(int from,int to,int cost) { add(from,to,cost); add(to,from,cost);}
void init()
{
	for(int i=2;i<10000;i++)
	{
		if(!vis[i]) p[++num]=i;
		for(int j=1;j<=num;j++)
		{
			if(p[j]*i>10000) break;
			vis[p[j]*i]=1;
			if(i%p[j]==0) break;
		}
	}
}
void dfs(int now,int fa,LL cost)
{
	anss[cost]++;
	for(int i=head[now];i;i=edge[i].next)
	{
		int to=edge[i].to;
		if(to==fa) continue;
		dfs(to,now,cost^edge[i].cost);
	}
}
signed main()
{
	init(); read(n);
	for(int i=2,u,v,w;i<=n;i++)
	{
		read(u),read(v),read(w);
		if(u!=v-1) sb=0;
		LL tag=0;
		for(int j=1;j<=num;j++)
			if(w%p[j]==0)
			{
				int siz=0;
				while(w%p[j]==0)
					siz++,w/=p[j];
				if(siz%2)
				{
					if(!Map[p[j]]) Map[p[j]]=1ll*rand()*rand();
					tag^=Map[p[j]];	
				}
			}
		if(w>1)
		{
			if(!Map[w]) Map[w]=1ll*rand()*rand();
			tag^=Map[w];	
		}	
		insert(u,v,tag);
	}
	if(sb) return 0*puts("0");
	dfs(1,1,0);
	for(auto v:anss) ans+=v.se*(v.se-1);
	printf("%lld\n",ans);
	return 0;
}




