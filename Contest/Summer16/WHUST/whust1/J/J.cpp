/*************************************************************************
    > File Name: J.cpp
    > Author: SnowyJune
    > Mail: SnowyJune 
    > Created Time: 2016年08月07日 星期日 17时29分29秒
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
const int maxn = 1005;
struct lion{
	int id,able;
}o[maxn],r[maxn];
int reso[maxn],resr[maxn];
bool cmp_ability(lion a,lion b){
	return a.able < b.able;
}
int n;
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	scanf("%d",&n);
	int i,delta=0;
	for(i = 1; i <= n; i++){
		o[i].id = i;
		scanf("%d",&o[i].able);
		delta+=o[i].able;
	}
	for(i = 1; i <= n; i++){
		r[i].id = i;
		scanf("%d",&r[i].able);
		delta-=r[i].able;
	}
	sort(o+1,o+n+1,cmp_ability);
	sort(r+1,r+n+1,cmp_ability);
	int ofr=1,oen=n,rfr=1,ren=n;
	//delta = 0;
	for(i = n; i >= 1; i--){
		if(delta>=0){
			delta -= o[oen].able - r[rfr].able;
			reso[i] = o[oen--].id;
			resr[i] = r[rfr++].id;
		}
		else{
			delta -= o[ofr].able - r[ren].able;
			reso[i] = o[ofr++].id;
			resr[i] = r[ren--].id;
//			printf("%d %d\n",o[oen--].id,r[rfr++].id);
		}
		//printf("Delta = %d\n",delta);
	}
	for(int i = 1; i <= n; i++){
		printf("%d %d\n",reso[i],resr[i]);
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
