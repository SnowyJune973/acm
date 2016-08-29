#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxk = 5e4+10, maxn = 5e4+10;
int cnt[maxk], a[maxn], blc[maxn];
int n,m,k;
LL tmp;
struct query{
	int l,r,id;
	LL ans;
}q[maxn];
bool cmp (query a,query b){
	return (blc[a.l]==blc[b.l])?(a.r<b.r):(blc[a.l]<blc[b.l]);
}
bool cmpid (query a,query b){
	return a.id<b.id;
}
void calc(){
	int sqk,blk_cnt,l,r;
	scanf("%d%d%d",&n,&k,&m);
	for(int i = 1; i <= n; i++)scanf("%d",&a[i]);
	for(sqk=1;sqk*sqk<=n;sqk++);
	sqk--;
	for(int i = 1; i <= n; i++){
		blc[i] = (i-1)/sqk+1;
//		printf("BLOCK %d = %d\n",i,blc[i]);
	}
	blk_cnt = (n+sqk-1)/sqk;
	for(int i = 1; i <= k; i++){
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id = i;
	}
	sort(q+1,q+k+1,cmp);
	r = tmp = 0;
	l = 1;
	memset(cnt,0,sizeof(cnt));
	for(int i = 1; i <= k; i++){
//		printf("I = %d\n",i);
		while(r>q[i].r){
			tmp = tmp - (2*cnt[a[r]]-1);
			cnt[a[r--]] --;

//			printf("L = %d, R = %d, cnt[a[r]] = %d, tmp = %lld\n",l,r,cnt[a[r]],tmp);
		}
		while(r<q[i].r){
			cnt[a[++r]] ++;
			tmp = tmp + (2*cnt[a[r]]-1);
//			printf("L = %d, R = %d, cnt[a[r]] = %d, tmp = %lld\n",l,r,cnt[a[r]],tmp);
		}
		while(l<q[i].l){
			tmp = tmp - (2*cnt[a[l]]-1);
			cnt[a[l++]] --;
			
//			printf("L = %d, R = %d, cnt[a[l]] = %d, tmp = %lld\n",l,r,cnt[a[l]],tmp);
		}
		while(l>q[i].l){
			cnt[a[--l]] ++;
			tmp = tmp + (2*cnt[a[l]]-1);
//			printf("L = %d, R = %d, cnt[a[l]] = %d, tmp = %lld\n",l,r,cnt[a[l]],tmp);
		}
		q[i].ans = tmp;
	}
	sort(q+1,q+k+1,cmpid);
	for(int i = 1; i <= k; i++){
		printf("%lld\n",q[i].ans);
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input","r",stdin);
#endif
	calc();
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
		
	
