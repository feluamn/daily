#include<bits/stdc++.h>
#define LL long long
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
namespace seq
{
	int cnt=0;
	int tree[N*20],ch[N*20][2];
	void updata(int &x,int y,int l,int r,int pos,int k)
	{
		if(!x) x=++cnt;
		if(l==r)
		{
			tree[x]=k;
			return ;
		}
		int mid=(l+r)>>1;
		if(pos<=mid)
		{
			updata(ch[x][0],ch[y][0],l,mid,pos,k);
			ch[x][1]=ch[y][1];
		}
		else 
		{
			updata(ch[x][1],ch[y][1],mid+1,r,pos,k);
			ch[x][0]=ch[y][0];
		}
	}
	int query(int now,int l,int r,int pos)
	{
		if(!now) return 0;
		if(l==r) return tree[now];
		int mid=(l+r)>>1;
		if(pos<=mid)
			return query(ch[now][0],l,mid,pos);
		else return query(ch[now][1],mid+1,r,pos);
	}
};
using namespace seq;
int n,now,dis[N],nxt[N],fa[N],son[N],a[N],rt[N];
char c;
signed main()
{
	read(n);
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&c);
		a[i]=c-'a'+1; 
		fa[i]=now;
		son[now]=i;
		dis[i]=dis[now]+1;
		nxt[i]=query(rt[now],1,26,a[i]);
		updata(rt[i],rt[nxt[i]],1,26,a[son[nxt[i]]],son[nxt[i]]);
		now=i;
	}
	printf("%d\n",dis[now]-dis[nxt[now]]);
	return 0;
}
