#pragma GCC optimize("3,Ofast,inline")
#include<bits/stdc++.h>
#define LL long long
#define int LL
#define P pair<int,int>
#define fi first
#define se second
const LL N=1e6+10;
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
int n,a[N];
int p[N],cnt,vis[N],pp[N],num;
void init()
{
	for(int i=2;i<N;i++)
	{
		if(!vis[i]) p[++cnt]=i;
		for(int j=1;j<=cnt;j++)
		{
			if(p[j]*i<N) vis[p[j]*i]=1;
			if(i%p[j]==0||p[j]*i>N) break;
		}
	}
}
signed main()
{
	init(); read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=cnt;i++)
		if(a[1]%p[i]==0)
			pp[++num]=p[i];
	if(a[1]!=1) pp[++num]=a[1];
	for(int i=1;i<=n;i++)
	{
		int x=__gcd(a[i],a[1]),tag=0;
		for(int j=1;j<=num;j++)
		{
			if(x%pp[j]==0)
			{
				tag=1;
				printf("%lld\n",x/pp[j]);
				break;
			}
		}
		if(!tag) puts("-1");
	}
	return 0;
}
