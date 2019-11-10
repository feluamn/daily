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
double p,ans[55][55],k[55][55];
bool vis[55][55];
int n,T,a[55];
void dfs(int now,int las)
{
	if (vis[now][las]) return ; vis[now][las] = 1;
	double x = 0.0,y = 0.0;
	for (int i = 1; i <= las; i++)
	{
		if (a[i] + now > T) break; dfs(a[i] + now,i);
		x += ans[now + a[i]][i], y += k[now+a[i]][i];
	}
	double sum = (now == 0)?1.00 / (1.0* las):(1.00-p) / (1.0*las);
	k[now][las] = p / (1.0 - sum * y);
	ans[now][las] = (sum * x+1.00) /(1.0 - sum * y);
}
signed main()
{
	while (scanf("%lf",&p) != EOF)
	{
		read(T),read(n);
		memset(vis,0,sizeof(vis));
		for (int i = 1; i <= n; i++) read(a[i]);
		sort(a+1,a+n+1); dfs(0,n);
		printf("%.3lf\n",ans[0][n]);
	}
	return 0;
}
