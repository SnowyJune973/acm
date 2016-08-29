#include<set>
#include<map>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<bitset>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#define rep(i,j,k) for (int i = j; i <= k; i++)
#define per(i,j,k) for (int i = j; i >= k; i--)
#define lson x << 1, l, mid
#define rson x << 1 | 1, mid + 1, r
using namespace std;
typedef long long LL;
const int low(int x) { return x&-x; }
const double eps = 1e-8;
const int INF = 0x7FFFFFFF;
const int mod = 1e9 + 7;
const int N = 20;
int T, h, n, m;
int a[N], cas = 0;

struct point
{
    LL x, y;
    point(int x = 0, int y = 0) :x(x), y(y) {}
}ans;

struct status
{
    int x, y, z;
    status(int x = 0, int y = 0, int z = 0) :x(x), y(y), z(z) {};
    bool operator<(const status&a) const
    {
        return x == a.x ? y == a.y ? z < a.z : y < a.y : x < a.x;
    }
};

map<status, point> M;

LL gcd(LL x, LL y)
{
    return x%y ? gcd(y, x%y) : y;
}

point operator*(point a, point b)
{
    LL x = a.x*b.x;
    LL y = a.y*b.y;
    return point(x / gcd(x, y), y / gcd(x, y));
}

point operator+(point a, point b)
{
    LL x = a.x*b.y + a.y*b.x;
    LL y = a.y*b.y;
    return point(x / gcd(x, y), y / gcd(x, y));
}

int main(int argc,char* argv[])
{
    freopen(argv[1],"r",stdin);
    freopen("stan","w",stdout);
    scanf("%d", &T);
    while (T--)
    {
        ans = point(0, 1);    M.clear();
        scanf("%d%d%d", &h, &n, &m);
        rep(i, 0, m - 1) scanf("%d", &a[i]);
        queue<status> p; 
        if (n) {
            M[status(1, 1, 0)] = point(n, m + n);
            p.push(status(1, 1, 0));
        }
        rep(i, 0, m - 1)
        {
            M[status(1, 0, 1 << i)] = point(1, m + n);
            p.push(status(1, 0, 1 << i));
        }
        while (!p.empty())
        {
            status q = p.front(); p.pop();
            int res = 0, cnt = 0;
            rep(i, 0, m - 1) res += (q.z & (1 << i)) ? (cnt++, a[i]) : 0;
            if (res >= h) 
            {
                ans = ans + M[q]; continue;
            }
            if (q.x == n + m || !q.y) continue;
            if (q.x == n + m - 1)
            {
                status r = status(q.x + 1, q.y - 1, (1 << m) - 1);
                if (!M.count(r)) { p.push(r); M[r] = point(0, 1); }
                M[r] = M[r] + M[q];
            }
            else
            {
                if (n - q.x + cnt >= 2)
                {
                    point w = point((n - q.x + cnt)*(n - q.x + cnt - 1), (n + m - q.x)*(n + m - q.x - 1));
                    status r = status(q.x + 2, q.y + 1, q.z);
                    if (!M.count(r)) { p.push(r); M[r] = point(0, 1); }
                    M[r] = M[r] + M[q] * w;
                }
                if (m - cnt >= 2)
                {
                    rep(i, 0, m - 1)
                    {
                        if (q.z & (1 << i)) continue;
                        rep(j, i + 1, m - 1)
                        {
                            if (q.z & (1 << j)) continue;
                            point w = point(2, (n + m - q.x)*(n + m - q.x - 1));
                            status r = status(q.x + 2, q.y - 1, q.z ^ (1 << i) ^ (1 << j));
                            if (!M.count(r)) { p.push(r); M[r] = point(0, 1); }
                            M[r] = M[r] + M[q] * w;
                        }
                    }
                }
                if (n - q.x + cnt >= 1 && m - cnt >= 1)
                {
                    rep(i, 0, m - 1)
                    {
                        if (q.z & (1 << i)) continue;
                        point w = point(2*(n - q.x + cnt), (n + m - q.x)*(n + m - q.x - 1));
                        status r = status(q.x + 2, q.y , q.z ^ (1 << i));
                        if (!M.count(r)) { p.push(r); M[r] = point(0, 1); }
                        M[r] = M[r] + M[q] * w;
                    }
                }
            }
        }
        printf("%lld/%lld\n", ans.x, ans.y);
    }
    return 0;
}
