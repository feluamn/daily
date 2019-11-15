#include<bits/stdc++.h>
#define LL long long 
#define fi first
#define se second
#define P pair<int,int>
#define db double
const LL N=3e3+10;
const LL mod=998244353;
const LL inf=0x3f3f3f3f;
const db eps=1e-9;
using namespace std;
template <typename tp> inline void read(tp &x)
{
	x=0; bool f=0; char c=getchar();
	for(;c<'0'||c>'9';f|=(c=='-'),c=getchar());
	for(;c>='0'&&c<='9';x=(x<<1)+(x<<3)+c-'0',c=getchar());
	if(f) x=-x;
} 
int n,m,a[N],sum[N],dp[N],tmp[N];
double calc(int x,int y)
{
	return (double)(1.0*dp[x]+1.0*sum[x]*sum[x]-dp[y]-1.0*sum[y]*sum[y])/(double)(sum[x]-sum[y]);
}
deque<int> de;
int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	memset(dp,63,sizeof(dp)); dp[0]=0;
	for(int i=1;i<=m;i++)
	{
		de.clear(); de.push_back(0);
		for(int j=1;j<=n;j++)
		{
			while(de.size()>=2&&calc(de[0],de[1])<=2.0*sum[j]) de.pop_front();
			tmp[j]=dp[de.front()]+pow(sum[j]-sum[de.front()],2);
			while(de.size()>=2&&calc(de[de.size()-2],de[de.size()-1])>calc(de[de.size()-1],j)) de.pop_back();
			de.push_back(j);
		}
		for(int j=1;j<=n;j++) dp[j]=tmp[j];
	}
	printf("%d\n",dp[n]*m-sum[n]*sum[n]);
	return 0;
}
