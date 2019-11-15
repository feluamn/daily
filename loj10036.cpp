#include<bits/stdc++.h>
#define LL long long
#define P pair<int,int>
#define fi first
#define se second
const LL N=4e5+10;
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
int len,nxt[N];
char s[N];
void getnxt(char *s,int *nxt,int len)
{
	int i=1,j=0;
	nxt[0]=-1; nxt[1]=0;
	while(i<len)
	{
		if(j==-1||s[i]==s[j])
			nxt[++i]=++j;
		else j=nxt[j];
	}
}
vector<int> vec;
signed main()
{
	while(~scanf("%s",s))
	{
		vec.clear();
		len=strlen(s);
		getnxt(s,nxt,len);
		int now=len;
		while(nxt[now])
		{
			vec.push_back(nxt[now]);
			now=nxt[now];
		}
		vec.push_back(len);
		sort(vec.begin(),vec.end());
		for(int i=0;i<vec.size();i++)
			printf("%d ",vec[i]); puts("");
	}
	return 0;
}
