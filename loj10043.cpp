#include<bits/stdc++.h>
#define LL long long
#define P pair<int,int>
#define fi first
#define se second
const LL N=1e3+10;
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
int nex[N],n,m;
char s[N],t[N],ans;
void get_next()
{
	int i=1,j=0;
	nex[1]=0; nex[0]=-1;
	while(i<n)
	{
		if(j==-1||t[i]==t[j]) 
			nex[++i]=++j;
		else j=nex[j];
	}
}
void kmp()
{
	int i=0,j=0;
	while(i<m)
	{
		if(j==-1||s[i]==t[j])
		{
			i++;j++;
			if(j==n)
			{
				ans++;
				j=0;
			}
		}
		else j=nex[j];
	}
	if(j==n) ans++;
}
signed main()
{
	while(~scanf("%s",s))
	{
		ans=0;
		if(s[0]=='#'&&s[1]=='\0') break;
		scanf("%s",t);
		n=strlen(t); 
		m=strlen(s);
		get_next();
		kmp();
		printf("%d\n",ans);
	}
	return 0;
}
