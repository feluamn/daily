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

signed main()
{
    puts("input n\ninput m\na = 0\nb = 1\nu = a + b\nv = a + b\nw = u - v\nif w goto 5\np = u % m\nq = u % m\nw = p - q\nif w goto 9\na = b\nb = p\nu = n - 1\nv = n - 1\nw = u - v\nif w goto 15\nn = u\nif n goto 5\noutput a");
	return 0;
}
