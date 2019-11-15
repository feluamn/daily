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
int n,k,sum[N],ans[N],tag[N];
vector<int> vec[310],sol[310];
bool cmp(int a,int b) { return a>b;}
int calc(int tp,int x,int y)
{
	return ans[sol[tp][x]]+sum[y-x];
}
void solve(int tp,int l,int r,int x,int y)
{
	if(l>r) return ;
	int mid=(l+r)>>1,wei=0;
	for(int i=x;i<=min(mid,y);i++)
		if(calc(tp,i,mid)>calc(tp,wei,mid)) 
			wei=i;
	tag[sol[tp][mid]]=calc(tp,wei,mid);
	solve(tp,l,mid-1,x,wei);
	solve(tp,mid+1,r,wei,y);
}
signed main()
{
	read(n),read(k);
	for(int i=1,x,y;i<=n;i++) read(x),read(y),vec[x].push_back(y);
	for(int i=1;i<=300;i++) sort(vec[i].begin(),vec[i].end(),cmp);
	for(int i=1;i<=300;i++)
	{
		if(vec[i].empty()) continue;
		for(int j=0;j<=i;j++) sol[j].clear();
		for(int j=0;j<=k;j++)
			sol[j%i].push_back(j);
		for(int j=1;j<=vec[i].size();j++)
			sum[j]=sum[j-1]+vec[i][j-1];
		for(int j=0;j<i;j++)
			solve(j,0,sol[j].size()-1,0,sol[j].size()-1);
		for(int j=1;j<=k;j++)
			ans[j]=max(ans[j-1],tag[j]);
		for(int j=1;j<=vec[i].size();j++)
			sum[j]=0;
	}
	for(int i=1;i<=k;i++) printf("%lld ",ans[i]); puts("");
	return 0;
}
