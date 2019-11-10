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
int n,m,len[N],ans;
vector<int> son[N];
void dfs(int now)
{
	int max1=0,max2=0;
	for(auto v:son[now])
	{
		dfs(v);
		max2=max(max2,len[v]+1);
		if(max2>max1) swap(max1,max2);
	}
	len[now]=max1, ans=max(ans,max1+max2);
}
signed main()
{
	read(n),read(m);
	for(int i=2,x;i<=n;i++) read(x),son[x].push_back(i);
	dfs(1); 
	printf("%lld\n",1LL*(len[1]+1)*2*(m-1)+ans+1);
	return 0;
}
