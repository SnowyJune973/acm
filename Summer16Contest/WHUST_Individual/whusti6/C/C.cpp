/*************************************************************************
  > File Name: C.cpp
  > Author: SnowyJune
  > Mail: SnowyJune 
  > Created Time: 2016年07月31日 星期日 00时07分05秒
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
//#define lld I64d
#define ms(x,y) memset(x,y,sizeof(x))
#define lson(x) (x<<1)
#define rson(x) ((x<<1)|1)
using namespace std;
#define lowbit(x) (x&(-x))
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x3f3f3f3f;
const LL linf = 0x3f3f3f3f3f3f3f3fLL;
const LL impossible = -12345678912345678LL;
const int maxn = 1e5+10;
LL fib[90] = {1,1};
int max_fib = 79;
struct Segment_Tree{
	LL sum,fibsum,l,r;
	bool setmark;
}T[maxn << 2];

void refresh_from_down(int pos);
void build(int pos, LL l, LL r){
	T[pos].l = l;
	T[pos].r = r;
	if(l == r){
		T[pos].sum = 0;
		T[pos].fibsum = 1;
		T[pos].setmark = false;
		return;
	}
	int mid = (l+r)>>1;
	build(lson(pos),l,mid);
	build(rson(pos),mid+1,r);
	refresh_from_down(pos);
}

void pushDown(int pos){
	/*if(T[pos].addmark != 0){
	  T[lson(pos)].addmark += T[pos].addmark;
	  T[rson(pos)].addmark += T[pos].addmark;
	  T[lson(pos)].sum += T[pos].addmark * (T[lson(pos)].r - T[lson(pos)].l + 1);
	  T[rson(pos)].sum += T[pos].addmark * (T[rson(pos)].r - T[rson(pos)].l + 1);
	  T[pos].addmark = 0;
	  }*/
	if(T[pos].setmark){
		T[lson(pos)].setmark = true;
		T[rson(pos)].setmark = true;
		T[lson(pos)].sum = T[lson(pos)].fibsum;
		T[rson(pos)].sum = T[rson(pos)].fibsum;
		T[pos].setmark = false;
	}
}

void refresh_from_down(int pos){
	T[pos].sum = T[lson(pos)].sum + T[rson(pos)].sum;
	T[pos].fibsum = T[lson(pos)].fibsum + T[rson(pos)].fibsum;
}

void push_up(int pos){
	int fa;
	while(pos!=1){
		fa = pos>>1;
		T[fa].sum = T[pos].sum + T[pos^1].sum;
		T[fa].fibsum = T[pos].fibsum + T[pos^1].fibsum;
		pos >>= 1;
	}
}


void add2(int pos,int k,LL delta){

	if(k < T[pos].l || k > T[pos].r) return ;  
	if(T[pos].l == T[pos].r){
//		printf("Pos = %d\n",pos);
		if(T[pos].setmark){
			T[pos].sum = delta + T[pos].fibsum;
			T[pos].setmark = false;
		}  
		else T[pos].sum += delta;
//		printf("Sum = %lld\n",T[pos].sum);
		if(T[pos].sum <= 0)T[pos].fibsum = 1;
		else{
			for(int i = 0; i < max_fib; i++){
//				puts("**************************");
//				printf("I = %d\n",i);
//				puts("**************************");
				if(T[pos].sum >= fib[i] && T[pos].sum <= fib[i+1]){
					if(T[pos].sum - fib[i] <= fib[i+1] - T[pos].sum){
						T[pos].fibsum = fib[i];
					}
					else{
						T[pos].fibsum = fib[i+1];
					}
					break;
				}
			}
		}
		return;
	}  
	pushDown(pos); 
	int mid = (T[pos].l + T[pos].r) >> 1;
	if(k<=mid)add2(lson(pos),k,delta);
	else add2(rson(pos),k,delta);
	refresh_from_down(pos);  
}  

void update_fibonacci(int pos,int L,int R){
	if(T[pos].r < L || T[pos].l > R){
		return;
	}
	if(T[pos].l >= L && T[pos].r <= R){
		T[pos].setmark = true;
		T[pos].sum = T[pos].fibsum;
		return;
	}
	pushDown(pos);
	int mid = (T[pos].l + T[pos].r) >> 1;
	if(L<=mid)update_fibonacci(lson(pos),L,R);
	if(R>mid)update_fibonacci(rson(pos),L,R);
	refresh_from_down(pos);
}

LL query(int pos,int L,int R){
	if(T[pos].r < L || T[pos].l > R){
		return 0;
	}
	if(T[pos].l >= L && T[pos].r <= R){
		return T[pos].sum;
	}
	pushDown(pos);
	LL res = 0;
	int mid = (T[pos].l + T[pos].r) >> 1;
	if(L<=mid)res += query(lson(pos),L,R);
	if(R>mid)res += query(rson(pos),L,R);
	return res;
}

void showtree(int pos){
	printf("Pos = %d: L = %lld, R = %lld.\n",pos,T[pos].l,T[pos].r);
	printf("Sum = %lld, Fibsum = %lld, Setmark = %d.\n",T[pos].sum,T[pos].fibsum,T[pos].setmark);
	puts("");
	puts("");
	if(T[pos].l == T[pos].r)return;
	showtree(lson(pos));
	showtree(rson(pos));
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("data","r",stdin);
	freopen("user","w",stdout);
#endif
	int n,q,l,r,k,tp;
	LL d;
//	printf("Fib 0 = %lld, Fib 1 = %lld\n",fib[0],fib[1]);
	for(int i = 2; i <= max_fib; i++){
		fib[i] = fib[i-1] + fib[i-2];
//		printf("Fib %d = %lld\n",i,fib[i]);
	}
	while(scanf("%d%d",&n,&q) == 2){
		//ms(T,0);
		build(1,1,n*1LL);
//		showtree(1);
		for(int i = 1; i <= q; i++){
			scanf("%d",&tp);
			if(tp == 1){
				scanf("%d%lld",&k,&d);

				add2(1,k,d);
			}
			if(tp == 2){
				scanf("%d%d",&l,&r);
				printf("%lld\n",query(1,l,r));
			}
			if(tp == 3){
				scanf("%d%d",&l,&r);
				update_fibonacci(1,l,r);
			}
//				showtree(1);
		}
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
