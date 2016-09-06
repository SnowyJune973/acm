/*************************************************************************
  > File Name: 1011.cpp
  > Author: SnowyJune
  > Mail: SnowyJune 
  > Created Time: 2016年08月02日 星期二 15时47分36秒
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
#define lson(x) (x>>1)
#define rson(x) ((x>>1)|1)
using namespace std;
#define lowbit(x) (x&(-x))
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x3f3f3f3f;
const LL linf = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 1010, maxl = maxn*1001+maxn;
const LL mod = 1e9+7;
LL c[maxn][maxn];
int a[maxn],b[maxn];
int ml,n,m;
void update(int x,int y,LL d){
	int tmpy = y;
	while(x<=n){
		y = tmpy;
		while(y<=m){
			c[x][y] = (c[x][y] + d + mod) % mod;
			//printf("C[%d][%d] = %lld\n",x,y,c[x][y]);
			y += lowbit(y);
		}
		x += lowbit(x);
	}
}

LL Sum(int x,int y){
	LL res = 0;
	int tmpy = y;
	while(x){
		y = tmpy;
		while(y){
			res = (res + c[x][y]) % mod;
			//printf("Res + C[%d][%d], res = %lld\n",x,y,res);
			y -= lowbit(y);
		}
		x -= lowbit(x);
	}
	return res;
}

void run(){
	for(int i = 1; i <= n; i++)scanf("%d",&a[i]);
	for(int i = 1; i <= m; i++)scanf("%d",&b[i]);
	ms(c,0);
	LL dp;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i] == b[j]){
				dp = 1 + Sum(i-1,j-1);
				//printf("I = %d , J = %d , Dp = %lld\n",i,j,dp);
				update(i,j,dp);
			}
		}
	}
	printf("%lld\n",Sum(n,m));
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	while(scanf("%d%d",&n,&m) == 2){
		ml = n * 1001 + m;
		run();
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
