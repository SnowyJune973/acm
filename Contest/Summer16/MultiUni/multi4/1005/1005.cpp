/*************************************************************************
  > File Name: 1005.cpp
  > Author: SnowyJune
  > Mail: SnowyJune 
  > Created Time: 2016年07月28日 星期四 16时41分30秒
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
#define lowbit(x) (x&(-x))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x3f3f3f3f;
const LL linf = 0x3f3f3f3f3f3f3f3fLL;
LL fast_mul(LL a,LL b,LL md){
	LL res = 0;
	while(b){
		if(b&1)res = (res+a)%md;
		a = (a*2LL) %md;
		b >>= 1;
	}
	return res;
}
LL extended_euclid(LL a,LL b,LL &x,LL &y){
	LL d;
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	d = extended_euclid(b,a%b,y,x);
	y -= a/b*x;
	return d;
}
pair<LL,LL> chinese_remainder(LL b[],LL w[],int len){
	LL d,x,y,m,n,ret;
	ret = 0;
	n = 1;
	for(int i = 0; i < len; i++)n *= w[i];
	for(int i = 0; i < len; i++){
		m = n / w[i];
		d = extended_euclid(w[i],m,x,y);
		ret = (ret + fast_mul(y,fast_mul(m,b[i],n),n))%n;
	}
	return make_pair((n + ret % n) % n,n);
}
LL counter1(LL y,LL p,LL a){
	return (y+(p-a)%p)/p;
}
LL counter(LL l,LL r,LL p,LL a){
	return counter1(r,p,a) - counter1(l-1,p,a);
}
LL pi[20],ai[20],l,r;
LL crpi[40000],crai[40000];
int lasttwo[40000],lastlogtwo[40000];
int n;
void run(int cases){
	LL wi[10],bi[10];
	LL ans = 0LL;
	pair<LL,LL> res;
	scanf("%d%llu%llu",&n,&l,&r);
	for(int i = 1; i <= n; i++){
		scanf("%llu%llu",&pi[i],&ai[i]);
		if(pi[i] == 7){
			if(ai[i] == 0){
				printf("Case #%d: 0\n",cases);
			}
			else{
				i--,n--;
			}
		}
	}
	//puts("A Bullshit");
	crpi[0] = 7, crai[0] = 0;
	for(int i = 1; i < (1 << n); i++){
		int prev = i ^ lasttwo[i];
		//printf("Prev = %d\n",prev);
		wi[0] = crpi[prev], bi[0] = crai[prev];
		wi[1] = pi[lastlogtwo[i]+1], bi[1] = ai[lastlogtwo[i]+1];
		//printf("I = %d\n",i);
		res = chinese_remainder(bi,wi,2);
		//printf("II = %d\n",i);
		crai[i] = res.first, crpi[i] = res.second;
		//printf("Crpi %d is %lld , Crai %d is %lld\n",i,crpi[i],i,crai[i]);
	}
	//puts("Two Bullshits");
	for(int i = 0; i < (1 << n); i++){
		int one_cnt = 0,tmp = i;
		while(tmp){
			one_cnt+=(tmp&1);
			tmp>>=1;
		}
		//printf("For i = %d , (%lld,%lld) : Cnt = %lld\n",i,crpi[i],crai[i],counter(l,r,crpi[i],crai[i]));
		if(one_cnt&1)ans -= counter(l,r,crpi[i],crai[i]);
		else ans += counter(l,r,crpi[i],crai[i]);
	}
	printf("Case #%d: %lld\n",cases,ans);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	int T,j,k;
	j = lasttwo[1] = 1;
	k = 0;
	for(int i = 2; i <= 32768; i++){
		if(i >= j * 2){
			j <<= 1;
			k ++;
		}
		lasttwo[i] = j;
		lastlogtwo[i] = k;
	}
	scanf("%d",&T);
	for(int i = 1; i <= T; i++){
		run(i);
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
