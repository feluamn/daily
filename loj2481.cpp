#include<bits/stdc++.h>
#define LL long long
#define P pair<int,int>
#define db long double 
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
int n,wei;
db a[N],b[N],tag,ans,sum;
bool cmp(db a,db b) { return a>b;}
signed main()
{
	read(n);
	for(int i=1;i<=n;i++) scanf("%Lf",&a[i]), scanf("%Lf",&b[i]);
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		tag+=a[i]-1;
		sum-=1;
		while(tag>sum&&wei+1<=n)
			sum+=b[++wei]-1,tag-=1;
		if(tag>sum) break;
		ans=max(ans,tag);
	}
	tag=sum=wei=0;
	for(int i=1;i<=n;i++)
	{
		tag+=b[i]-1;
		sum-=1;
		while(tag>sum&&wei+1<=n)
			sum+=a[++wei]-1,tag-=1;
		if(tag>sum) break;
		ans=max(ans,tag);
	}
	printf("%.4Lf\n",ans);
	return 0;
}
