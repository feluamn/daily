#include<bits/stdc++.h>
#define LL long long
#define P pair<int,int>
#define fi first
#define se second
const LL N=1e5+10;
const LL mod=998244353;
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

LL ans, tag = 1, n, opt, And = 1;
int main() 
{
	for (scanf("%d", &n); --n; )
	{
		scanf("%s",&opt);
		if (opt & 2) ++And;
		else 
		{
			ans += tag;
			tag = tag * And % mod;
			And = 1;
		}
	}
	ans = (ans + tag + tag * And) % mod;
	printf("%lld\n", ans);
	return 0;
}
