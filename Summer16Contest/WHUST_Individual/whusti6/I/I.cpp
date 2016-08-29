/*************************************************************************
    > File Name: I.cpp
    > Author: SnowyJune
    > Mail: SnowyJune 
    > Created Time: 2016年07月30日 星期六 22时40分49秒
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
bool ok(LL h,LL a,LL b,LL k){
	if(a >= h)return true;
	if(a > b && k*a-(k-1)*b >= h)return true;
	if(k*a - (k+1)*b > 0)return true;
	return false;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	LL h,a,b,k;
	int cs = 0;
	while(1){
		cs ++;
		scanf("%lld%lld%lld%lld",&h,&a,&b,&k);
		if(!h && !a && !b && !k)break;
		printf("Case #%d: %s\n",cs,ok(h,a,b,k)?"YES":"NO");
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
