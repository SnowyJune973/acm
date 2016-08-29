/*************************************************************************
    > File Name: 1004.cpp
    > Author: SnowyJune
    > Mail: SnowyJune 
    > Created Time: 2016年08月04日 星期四 01时03分48秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#define ms(x,y) memset(x,y,sizeof(x))
#define lson(x) (x<<1)
#define rson(x) ((x<<1)|1)
using namespace std;
#define lowbit(x) (x&(-x))
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x3f3f3f3f;
const LL linf = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 2005;
int n;
LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}
LL labs(LL a){
	return (a>0)?a:(-a);
}
struct Point{
	LL x,y;
	void reduce(){
		LL GCD = gcd(labs(x),labs(y));
		x/=GCD, y/=GCD;
	}
	Point(LL _x = 0, LL _y = 0):
		x(_x),y(_y){}

}pn[maxn],vec[maxn];

LL operator ^ (Point a,Point b){
	return a.x*b.x + a.y*b.y;
}
LL operator * (Point a,Point b){
	return a.x*b.y-a.y*b.x;
}
Point operator - (Point a,Point b){
	return Point(a.x-b.x,a.y-b.y);
}
int quad(Point a){
	if(a.x > 0 && a.y >= 0)return 1;
	if(a.x <= 0 && a.y > 0)return 2;
	if(a.x < 0 && a.y <= 0)return 3;
	if(a.x >= 0 && a.y < 0)return 4;
}
bool cmp_xx(Point a,Point b){
	int qa = quad(a),qb = quad(b);
	if(qa == qb){
		return a*b > 0 || (a*b == 0 && a.x>b.x);
	}
	else return qa < qb;
}
void run(){
	int k;
	for(int i = 1; i <= n; i++){
		scanf("%lld%lld",&pn[i].x,&pn[i].y);
	}
	/* Following is main program */
	for(int i = 1; i <= n; i++){
		k = 0;
		for(int j = 1; j <= n; j++){
			if(i == j)continue;
			k ++;
			vec[k] = pn[j] - pn[i];
			vec[k].reduce();
		}
		sort(vec+1,vec+n,cmp_xx);
		/* Next is two pointer*/

		/* Upward is two pointer*/
	}
	/* Upward is main program */
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	while(scanf("%d",&n) == 1){
		run();
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
