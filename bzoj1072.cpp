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
int T,d,n,num[11];
char s[100];
int dp[1<<11][1010];
signed main()
{
	read(T);
	while(T--)
	{
		scanf("%s",s+1); read(d);
		n=strlen(s+1);
		memset(dp,0,sizeof(dp));
		memset(num,0,sizeof(num));
		dp[0][0]=1;
		for(int i=0;i<(1<<n);i++)
		{
			for(int k=0;k<d;k++)
				for(int j=1;j<=n;j++)
					if(i&(1<<j-1))
						dp[i][(k*10+s[j]-'0')%d]+=dp[i^(1<<j-1)][k];
		}
		int ans=dp[(1<<n)-1][0];
		for(int i=1;i<=n;i++)
			num[s[i]-'0']++;
		for(int i=0;i<=9;i++)
			for(int j=2;j<=num[i];j++)
				ans/=j;
		printf("%d\n",ans);
	}
	return 0;
}
