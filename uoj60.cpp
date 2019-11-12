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
LL n,ans=4;
signed main()
{
	read(n);
	for(int i=2;i<=n;i++) ans=ans*3%mod;
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++) puts("A 0 0 0 0");
	return 0;
}
