#include<bits/stdc++.h>
#define LL long long
#define int LL
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
LL n,m,tag,sb;
signed main()
{
	read(n),read(m); tag=sb=1;
	for(int i=1;i<=n;i++) tag=tag*i;
	for(int i=1;i<=n;i++)
	{
		sb*=i; int flag=tag/sb;
		if(m>=(tag/sb))
			printf("%lld\n",1ll * m / flag * flag);
		m=m%(tag/sb);
	}
	return 0;
}
