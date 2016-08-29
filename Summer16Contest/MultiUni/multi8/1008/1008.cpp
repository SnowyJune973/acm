#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define lson(x) (x<<1)
#define rson(x) ((x<<1)|1)
using namespace std;
const int maxn = 1e5+18;
const int inf = 0x3f3f3f3f;
typedef long long LL;
LL a[maxn];
struct SegmentTree{
	LL min,max,sum,lazy;
	int slazy;
}seg[maxn<<2];
int n,q;
void showtree(int root,int l,int r){
	printf("Node %d: L = %d , R = %d\n",root,l,r);
	printf("Sum = %lld, Min = %lld, Max = %lld\n",seg[root].sum,seg[root].min,seg[root].max);
	printf("Lazy = %lld, Slazy = %d\n",seg[root].lazy,seg[root].slazy);
	if(l==r)return;
	int mid = (l+r) >> 1;
	showtree(lson(root),l,mid);
	showtree(rson(root),mid+1,r);
}
void refresh(int root){
	seg[root].min = min(seg[lson(root)].min,seg[rson(root)].min);
	seg[root].max = max(seg[lson(root)].max,seg[rson(root)].max);
	seg[root].sum = seg[lson(root)].sum + seg[rson(root)].sum;
}
void pushDown(int root,int l,int r){
//	printf("PUSHDOWN : Root = %d, L = %d , R = %d\n",root,l,r);
	while(seg[root].slazy){
		int mid = (l+r) >> 1;
		seg[root].slazy --;
		seg[lson(root)].slazy ++, seg[rson(root)].slazy ++;
		if(seg[lson(root)].max > 1){
		if(seg[lson(root)].max == seg[lson(root)].min + 1){
			LL bcnt = seg[lson(root)].sum - seg[lson(root)].min * (mid-l+1);
			LL acnt = (mid-l+1) - bcnt;
			LL nx0 = 1LL*int(sqrt(seg[lson(root)].min)), nx1 = 1LL*int(sqrt(seg[lson(root)].max));
			seg[lson(root)].min = nx0, seg[lson(root)].max = nx1;
			seg[lson(root)].sum = nx0 * acnt + nx1 * bcnt;
		}
		else{
			LL nx = 1LL*int(sqrt(seg[lson(root)].min));
			seg[lson(root)].min = seg[lson(root)].max = nx;
			seg[lson(root)].sum = nx * (mid-l+1);
		}
		}
		if(seg[rson(root)].max>1){
		if(seg[rson(root)].max == seg[rson(root)].min + 1){
			LL bcnt = seg[rson(root)].sum - seg[rson(root)].min * (r-mid);
			LL acnt = (r-mid) - bcnt;
			LL nx0 = 1LL*int(sqrt(seg[rson(root)].min)), nx1 = 1LL*int(sqrt(seg[rson(root)].max));
			seg[rson(root)].min = nx0, seg[rson(root)].max = nx1;
			seg[rson(root)].sum = nx0 * acnt + nx1 * bcnt;
		}
		else{
			LL nx = 1LL*int(sqrt(seg[rson(root)].min));
			seg[rson(root)].min = seg[rson(root)].max = nx;
			seg[rson(root)].sum = nx * (r-mid);
		}
		}
	}		
	if(seg[root].lazy != 0){
		int mid = (l+r) >> 1;
		LL lz = seg[root].lazy;
		seg[root].lazy = 0;
		seg[lson(root)].lazy += lz, seg[rson(root)].lazy += lz;
		seg[lson(root)].sum += (mid-l+1) * lz, seg[rson(root)].sum += (r-mid) * lz;
		seg[lson(root)].min += lz, seg[rson(root)].min += lz;
		seg[lson(root)].max += lz, seg[rson(root)].max += lz;
	}
	seg[root].slazy = 0;
	seg[root].lazy = 0;
}

void build(int root,int l,int r){
	if(l==r){
		seg[root].min = seg[root].max = seg[root].sum = a[l];
		seg[root].lazy = 0;
		seg[root].slazy = 0;
		return;
	}
	int mid = (l+r)>>1;
	build(lson(root),l,mid);
	build(rson(root),mid+1,r);
	refresh(root);
}

void add(int root,int l,int r,int L,int R,LL d){
	if(l < r)pushDown(root,l,r);
	else{
		seg[root].lazy = 0;
		seg[root].slazy = 0;
	}
	if(L <= l && R >= r){
		pushDown(root,l,r);
		seg[root].sum += (r-l+1) * d;
		seg[root].min += d;
		seg[root].max += d;
		seg[root].lazy += d;
		return;
	}
//	pushDown(root,l,r);
	int mid = (l+r) >> 1;
	if(mid >= L)add(lson(root),l,mid,L,R,d);
	if(R > mid)add(rson(root),mid+1,r,L,R,d);
	refresh(root);
}

void setSqrt(int root,int l,int r,int L,int R){
	if(l < r)pushDown(root,l,r);
	if(l == r){
//		printf("Sum = %lld\n",seg[root].sum);
		seg[root].sum = 1LL*int(sqrt(seg[root].sum));
//		printf("Sum = %lld\n",seg[root].sum);
		seg[root].min = seg[root].max = seg[root].sum;
		seg[root].lazy = 0;
		seg[root].slazy = 0;
		//pushDown(root,l,r);
		return;
	}
	if(L <= l && R >= r){
		if(seg[root].min == seg[root].max){
//			printf("Min = %lld\n",seg[root].min);
			LL nx = 1LL*int(sqrt(seg[root].min));
//			printf("Nxt = %lld\n",nx);
			seg[root].sum = (r-l+1) * nx;
			seg[root].min = seg[root].max = nx;
			seg[root].slazy ++;
//			pushDown(root,l,r);
			return;
		}
		if(seg[root].min + 1 == seg[root].max){
			LL bcnt = seg[root].sum - (r-l+1) * seg[root].min;
			LL acnt = (r-l+1) - bcnt;
			LL nx0 = LL(sqrt(seg[root].min)), nx1 = LL(sqrt(seg[root].max));
			seg[root].min = nx0, seg[root].max = nx1;
			seg[root].sum = nx0 * acnt + nx1 * bcnt;
			seg[root].slazy ++;
//			pushDown(root,l,r);
			return;
		}
	}
//	pushDown(root,l,r);
	int mid = (l+r) >> 1;
	if(mid >= L)setSqrt(lson(root),l,mid,L,R);
	if(R > mid)setSqrt(rson(root),mid+1,r,L,R);
	refresh(root);
}	
	
LL Query(int root,int l,int r,int L,int R){
	if(l < r)pushDown(root,l,r);
	else{
		seg[root].lazy = 0;
		seg[root].slazy = 0;
	}
	LL res = 0;
	if(L <= l && R >= r){
		return seg[root].sum;
	}
//	pushDown(root,l,r);
	int mid = (l+r) >> 1;
	if(mid >= L)res += Query(lson(root),l,mid,L,R);
	if(R > mid)res += Query(rson(root),mid+1,r,L,R);
	return res;
}
int input(){
	char ch=getchar();
	while(!(ch>='0' && ch<='9'))ch=getchar();
	int res = 0;
	while(ch>='0'&&ch<='9'){
		res=res*10+ch-48;
		ch=getchar();
	}
	return res;
}
void work(){
	//scanf("%d%d",&n,&q);
	n=input();
	q=input();
	int type,l,r;
	LL d;
	for(int i = 1; i <= n; i++){
		a[i] = input();
	}
	build(1,1,n);
//	showtree(1,1,n);
//	puts("*************************");
	for(int i = 1; i <= q; i++){
		type=input();
		l=input();
		r=input();
		if(type == 1){
			d=input();
			add(1,1,n,l,r,d);
		}
		if(type == 2){
			setSqrt(1,1,n,l,r);
		}
		if(type == 3){
			printf("%lld\n",Query(1,1,n,l,r));
		}
//		showtree(1,1,n);
//		puts("*********************************");
	}
}
int main(){
#ifndef ONLINE_JUDGE
	//freopen("/home/snowyjune/code/input","r",stdin);
	freopen("data","r",stdin);
	freopen("user","w",stdout);
#endif
	int T;
	scanf("%d",&T);
	while(T--){
		work();
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
