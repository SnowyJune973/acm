/*************************************************************************
    > File Name: C.cpp
    > Author: SnowyJune
    > Mail: SnowyJune 
    > Created Time: 2016年08月07日 星期日 20时07分17秒
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
const int maxn = 1e5+20;
int n,fr,re,know_last;

struct letter{
	int d,M,h,m,id,rank;
	LL val;
	void input(int x){
		scanf("%lld %d.%d %d:%d",&val,&d,&M,&h,&m);
		id = x;
	}
	bool operator < (letter &b){
		if(M==b.M){
			if(d==b.d){
				return h*60+m<b.h*60+b.m;
			}
			else return d<b.d;
		}
		else return M<b.M;
	}
}lt[maxn];

bool cmp_id(letter a,letter b){
	return a.id < b.id;
}
LL c[maxn];
void Update(int x,LL delta){
	while(x<=n){
		c[x] += delta;
		x += lowbit(x);
	}
}
LL Sum(int x){
	LL res = 0;
	while(x){
		res += c[x];
		x -= lowbit(x);
	}
	return res;
}

struct credit{
	int id;
	LL val;
	void Set(int _id,int _val){
		id = _id;
		val = _val;
	}
	credit(int _id = 0,int _val = 0):
		id(_id),val(_val){}
}cr[maxn];

int upbound_id(int l,int r,int xid){
	while(l<r){
		int mid = (l+r)>>1;
		if(cr[mid].id <= xid)l=mid+1;
		else r=mid;
	}
	return l;
}
int lowbound_id(int l,int r,int xid){
	while(l<r){
		int mid = (l+r)>>1;
		if(cr[mid].id < xid)l=mid+1;
		else r=mid;
	}
	return l;
}
int upbound_val(int l,int r,LL xval){
	while(l<r){
		int mid = (l+r)>>1;
		if(Sum(cr[mid].id) <= xval)l=mid+1;
		else r=mid;
	}
	return l;
}

LL Query(int pres_tm){
	int k = upbound_id(fr,re,pres_tm)-1;
	return -1LL*Sum(cr[k].id);
}
void Pay(int pres_tm,LL amount){
//	puts("");
//	printf("Pay At %d by %lld\n",pres_tm,amount);
	int k0 = upbound_id(fr,re,pres_tm);
	int k = upbound_val(fr,re,amount+cr[k0-1].val);
//	printf("K0 = %d\n",k0);
//	printf("K = %d\n",k);
	LL prev_sum = Sum(cr[k-1].id) - Sum(cr[k0-1].id);
//	printf("Prev_sum = %lld\n",prev_sum);
	for(int i = k0; i < k; i++){
		Update(cr[i].id,-cr[i].val);
		cr[i].val = 0;
	}
	Update(cr[k].id,prev_sum-amount);
	cr[k].val += prev_sum-amount;
	while(cr[fr].val == 0)fr++;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	scanf("%d",&n);
	ms(c,0);
	know_last = 0;
	for(int i = 1; i <= n; i++)lt[i].input(i);
	sort(lt+1,lt+n+1);
	for(int i = 1; i <= n; i++)lt[i].rank = i;
	cr[0].id = 0;
	cr[0].val = 0;
	fr = 1,re = 0;
	for(int i = 1; i <= n; i++){
		if(lt[i].val < 0){
			re ++;
			cr[re].id = i;
			cr[re].val = -lt[i].val;
			Update(cr[re].id,cr[re].val);
		}
	}
	re++;
	cr[re].id = cr[re].val = inf;
	sort(lt+1,lt+n+1,cmp_id);
	for(int i = 1; i <= n; i++){
		if(lt[i].val < 0)know_last = max(know_last,lt[i].rank);
		//printf("Rk = %d\n",lt[i].rank);
		//printf("Knowlast = %d\n",know_last);
		if(lt[i].val > 0){
			if(lt[i].rank < cr[re-1].id)Pay(lt[i].rank,lt[i].val);
		}
		printf("%lld\n",-Sum(know_last));
	}
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
