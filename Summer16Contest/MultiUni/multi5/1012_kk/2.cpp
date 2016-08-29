#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define fst first
#define sec second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
#define pi pair < int ,int >
#define MP make_pair

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=5E4+7;
int a[N];
int t[N];
int ref[N];
int n;
LL ni[N],zheng[N];
int lowbit( int x)
{
    return x&(-x);
}
void update( int x,int delta)
{
    for ( int i = x ; i <= n ; i+=lowbit(i))
      t[i]+=delta;
}
int Sum( int x)
{
    int res = 0;
    for ( int i = x; i  >=1 ; i-=lowbit(i))
    {
    res+=t[i];
    }
    return res;
}
struct Q
{
    int val;
    int id;

    bool operator < (Q b)const
    {
    return val<b.val;
    }
}q[N];
int main()
{
    #ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
  #endif

    while (~scanf("%d",&n))
    {
        ms(ref,0);
        ms(t,0);
        ms(zheng,0);
        ms(ni,0);
        q[0].val = -1;
        for ( int i = 1 ; i <= n ; i++) scanf("%d",&q[i].val),q[i].id = i ;
        if (n<4)
        {
        puts("0");
        continue;
        }
        sort(q+1,q+n+1);
        for ( int i = 1 ; i <= n ; i++)
        {
        if (q[i].val!=q[i-1].val)
            ref[q[i].id] = i ;
        
        else
        {
            ref[q[i].id] = ref[q[i-1].id];
        }
        }
      //  for ( int i = 1;  i <= n ; i++) cout<<"ref[i]:"<<ref[i]<<endl;
        LL numz = 0LL;
        LL numn = 0LL;
        LL total = 1LL*n*(n-1)/2LL;
        for ( int i = 1 ; i <= n ; i++)
        {
        update(ref[i],1);
        LL tmp = ref[i]-Sum(ref[i]);
    //    cout<<"real ni:"<<tmp<<endl;
    //    tmp = max(tmp,0LL);
        numn = numn + tmp;
        ni[i] = tmp+(tmp+i-ref[i]);
        zheng[i] = n-1-ni[i];
        }
    //    for ( int i = 1 ; i <= n ; i++) cout<<"ni[i]:"<<ni[i]<<" zheng[i]:"<<zheng[i]<<endl;
        numz =total-numn;
        if (numz==0LL||numn==0LL)
        {
        puts("0");
        continue;
        }
     //   cout<<"zheng:"<<numz<<" ni:"<<numn<<endl;
        LL ans = numz*numn;
        for ( int i = 1 ; i <= n ; i++)
        {
        ans -=zheng[i]*ni[i];
        }
        ans = max(ans,0LL);
        printf("%lld\n",ans);
    }

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}

