#include<bits/stdc++.h>
#define LL long long
#define int LL
#define P pair<int,int>
#define fi first
#define se second
const LL N=2e6+10;
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
int KSM(int a,int b,int ret=1)
{
	if(b<0) b+=mod-1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
int n,m,a,b,c,d,n1,m1;
int x,y;
char s[N],t[N];
signed main()
{
	scanf("%s%s",s+1,t+1); n=strlen(s+1),m=strlen(t+1);
	read(a),read(b),read(c),read(d);
	int tag=0,tag1=0;
	for(int i=1;i<=n;i++) 
	{
		tag=tag*10+s[i]-'0';
		tag1=tag1*10+s[i]-'0';
		tag%=(mod-1);
		tag1%=mod;
	}
	n = tag, n1 = tag1;
	tag = tag1 = 0;
	for(int i=1;i<=m;i++) 
	{
		tag=tag*10+t[i]-'0';
		tag1=tag1*10+t[i]-'0';
		tag%=(mod-1);
		tag1%=mod;
	}
	m = tag, m1 = tag1;
	if(a == 1) b = (m1 - 1LL) * b % mod;
	else b = ((KSM(a, m - 1LL) - 1LL) % mod + mod) % mod * KSM(((a - 1LL) % mod + mod) % mod, mod - 2LL) % mod * b % mod;
	a = KSM(a, m-1LL) % mod;
	if(n == 1) { printf("%lld\n", ((a + b) % mod + mod) % mod); return 0;}
	x = a * c % mod;
	y = (b * c % mod + d) % mod;
	if(x == 1) y = ((n1 - 1LL) % mod + mod) % mod * y % mod;
	else y = ((KSM(x, n - 1LL) - 1LL) % mod + mod) % mod * KSM(((x - 1LL) % mod + mod) % mod, mod - 2LL) % mod * y % mod;
	x = KSM(x, n - 1LL) % mod;
	x = ((x + y) % mod * a + b) % mod;
	printf("%lld\n", (x % mod + mod) % mod);
	return 0;
}
