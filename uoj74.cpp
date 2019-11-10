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
int n,q=1,p,h[N],ans[N];
int KSM(int a,int b,int ret=1)
{
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}

void solve1()
{
	int tag = *h;
	for(int i = 0; i < n; ++i) ans[i] = tag % 26, tag /= 26;
	reverse(ans, ans + n);
}
void solve2()
{
	for(int i=0;i<n;i++)
	{
		int tag=(( h[i] * 26 % p - h[(i+1)%n])%p + p) % p;
		for(int j=0;j<26;j++)
			if(tag==j*(q-1)%p)
			{
				ans[i]=j;
				break;
			}
	}
}
signed main()
{
	read(n),read(p);
	for(int i=0;i<n;i++)
	{
		read(h[i]);
		q=q*26%p;
	}
	if(q==1) solve1();
	else solve2();
	for(int i=0;i<n;i++) printf("%c",(char)ans[i]+'a');
	puts("");
	return 0;
}
