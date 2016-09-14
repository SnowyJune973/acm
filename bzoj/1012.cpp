#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define lson(x) (x<<1)
#define rson(x) ((x<<1)|1)
using namespace std;
typedef long long LL;
const LL inf = (1LL<<60);
const int maxn = 2e5+20;
struct Segment{
	LL max,lazy;
}T[maxn<<2];
void build(int id,int l,int r){
	T[id].lazy = 0;
	T[id].max = 0;
	if(l<r){
		int mid = (l+r)>>1;
		build(lson(id),l,mid);
		build(rson(id),mid+1,r);
	}
}
void pushDown(int id,int l,int r){
//	printf("pushdown %d %d %d\n",id,l,r);
	if(T[id].lazy != 0){
		T[lson(id)].lazy += T[id].lazy;
		T[rson(id)].lazy += T[id].lazy;
		int mid = (l+r)>>1;
		T[lson(id)].max += T[id].lazy;
		T[rson(id)].max += T[id].lazy;
		T[id].lazy = 0;
	}
}
void update(int id,int l,int r,int L,int R,LL d){
	if(l>R || r<L){
		return;
	}
	if(l>=L && r<=R){
		T[id].max += d;
		T[id].lazy += d;
		return;
	}
//	printf("Update %d %d %d %d %d %lld\n",id,l,r,L,R,d);
	pushDown(id,l,r);
	int mid = (l+r)>>1;
	update(lson(id),l,mid,L,R,d);
	update(rson(id),mid+1,r,L,R,d);
	T[id].max = max(T[lson(id)].max,T[rson(id)].max);
}
LL query(int id,int l,int r,int L,int R){
	if(l>R || r<L){
		return -inf;
	}
	if(l>=L && r<=R){
		return T[id].max;
	}
//	printf("Query %d %d %d %d %d\n",id,l,r,L,R);
	pushDown(id,l,r);
	int mid = (l+r)>>1;
	return max(query(lson(id),l,mid,L,R),query(rson(id),mid+1,r,L,R));
}
int m;
LL D;
int main(){
#ifndef ONLINE_JUDGE
	freopen("input","r",stdin);
#endif
	scanf("%d%lld",&m,&D);
	build(1,1,m);
	char s[3];
	LL para,t=0;
	int tot = 0;
	for(int i = 1; i <= m; i++){
		scanf("%s %lld\n",&s,&para);
		if(s[0] == 'A'){
			update(1,1,m,tot+1,tot+1,(t+para)%D);
			tot++;
		}
		else{
			t = query(1,1,m,tot-para+1,tot);
			printf("%lld\n",t);
		}
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
