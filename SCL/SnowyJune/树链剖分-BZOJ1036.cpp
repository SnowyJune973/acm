#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define lson(x) (x<<1)
#define rson(x) ((x<<1)|1)
#define QMAX 0
#define QSUM 1
using namespace std;
typedef long long LL;
const int maxn = 3e4+10, maxq = 2e5+20;
const LL inf = 1LL<<60;
int siz[maxn],dep[maxn],top[maxn],fa[maxn],son[maxn],w[maxn],totw;
bool vis[maxn];
int n,q;
LL c[maxn],c0[maxn];
vector<int> e[maxn];
struct Segment{
	LL sum,max,lazy;
}T[maxn<<2];
void build(int id,int l,int r){
	T[id].sum = c[l];
	T[id].max = c[l];
	T[id].lazy = 0;
	if(l<r){
		int mid = (l+r)>>1;
		build(lson(id),l,mid);
		build(rson(id),mid+1,r);
		T[id].sum = T[lson(id)].sum + T[rson(id)].sum;
		T[id].max = max(T[lson(id)].max, T[rson(id)].max);
	}
}
void pushDown(int id,int l,int r){
	if(T[id].lazy != 0){
		T[lson(id)].lazy += T[id].lazy;
		T[rson(id)].lazy += T[id].lazy;
		int mid = (l+r)>>1;
		T[lson(id)].sum += T[id].lazy * (mid-l+1);
		T[rson(id)].sum += T[id].lazy * (r-mid);
		T[lson(id)].max += T[id].lazy;
		T[rson(id)].max += T[id].lazy;
		T[id].lazy = 0;
	}
}
void update(int id,int l,int r,int L,int R,int d){
	if(l>R || r<L){
		return;
	}
	if(l>=L && r<=R){
		T[id].sum += d*(r-l+1);
		T[id].max += d;
		T[id].lazy += d;
		return;
	}
	pushDown(id,l,r);
	int mid = (l+r)>>1;
	update(lson(id),l,mid,L,R,d);
	update(rson(id),mid+1,r,L,R,d);
	T[id].sum = T[lson(id)].sum + T[rson(id)].sum;
	T[id].max = max(T[lson(id)].max,T[rson(id)].max);
}
LL querySum(int id,int l,int r,int L,int R){
	if(l>R || r<L){
		return 0;
	}
	if(l>=L && r<=R){
		return T[id].sum;
	}
	pushDown(id,l,r);
	int mid = (l+r)>>1;
	return querySum(lson(id),l,mid,L,R) + querySum(rson(id),mid+1,r,L,R);
}
LL queryMax(int id,int l,int r,int L,int R){
	if(l>R || r<L){
		return -inf;
	}
	if(l>=L && r<=R){
		return T[id].max;
	}
	pushDown(id,l,r);
	int mid = (l+r)>>1;
	LL tmp = max(queryMax(lson(id),l,mid,L,R),queryMax(rson(id),mid+1,r,L,R));
	return tmp;
}

int dfs1(int x){
	vis[x] = true;
	int sonsize = -1;
	for(vector<int>::iterator it = e[x].begin(); it != e[x].end(); it++){
		if(!vis[*it]){
			fa[*it] = x;
			dep[*it] = dep[x] + 1;
			siz[x] += dfs1(*it);
			if(siz[*it] > sonsize){
				sonsize = siz[*it];
				son[x] = *it;
			}
		}
	}
	siz[x]++;
	vis[x] = false;
	return siz[x];
}
void dfs2(int x){
	vis[x] = true;
	top[son[x]] = top[x];
	if(son[x] != -1){
		w[son[x]] = ++totw;
		dfs2(son[x]);
	}
	for(vector<int>::iterator it = e[x].begin(); it != e[x].end(); it++){
		if(*it!=son[x] && !vis[*it]){
			top[*it]=*it;
			w[*it] = ++totw;
			dfs2(*it);
		}
	}
	vis[x] = false;
}
void init(){
	for(int i = 1; i <= n; i++)e[i].clear();
	memset(fa,-1,sizeof(fa));
	memset(siz,0,sizeof(siz));
	memset(son,-1,sizeof(son));
	memset(vis,false,sizeof(vis));
	fa[1] = 1;
	dep[1] = 1;
	top[1] = 1;
	w[1] = 1;
	totw = 1;
}
void TreeUpdate(int u,LL d){
	update(1,1,siz[1],w[u],w[u],d-querySum(1,1,siz[1],w[u],w[u]));
}		
LL TreeQuerySumToRoot(int u,int v){
	int f1 = top[u], f2 = top[v];
	LL res = 0;
	while(f1 != f2){
		if(dep[f1] < dep[f2]){
			swap(f1,f2);
			swap(u,v);
		}
		res += querySum(1,1,siz[1],w[f1],w[u]);
		u = fa[f1];
		f1 = top[u];
	}
	if(dep[u] > dep[v])swap(u,v);
	res += querySum(1,1,siz[1],w[u],w[v]);
	return res;
}
LL TreeQueryMaxToRoot(int u,int v){
	int f1 = top[u], f2 = top[v];
	LL res = -inf;
	while(f1 != f2){
		if(dep[f1] < dep[f2]){
			swap(f1,f2);
			swap(u,v);
		}
		res = max(res, queryMax(1,1,siz[1],w[f1],w[u]));
		u = fa[f1];
		f1 = top[u];
	}
	if(dep[u] > dep[v])swap(u,v);
	res = max(res, queryMax(1,1,siz[1],w[u],w[v]));
	return res;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input","r",stdin);
#endif
	int pa1,pa2;
	char str[10];
	scanf("%d",&n);	
	init();
	for(int i = 1; i < n; i++){
		scanf("%d%d",&pa1,&pa2);
		e[pa1].push_back(pa2);
		e[pa2].push_back(pa1);
	}
	for(int i = 1; i <= n; i++)scanf("%lld",&c0[i]);
	dfs1(1);
	dfs2(1);
	for(int i = 1; i <= n; i++){
		c[w[i]] = c0[i];
	}
	build(1,1,n);
	scanf("%d",&q);
	for(int i = 1; i <= q; i++){
		scanf("%s %d %d\n",str,&pa1,&pa2);
		if(str[1] == 'M'){
			printf("%lld\n",TreeQueryMaxToRoot(pa1,pa2));
		}
		if(str[1] == 'S'){
			printf("%lld\n",TreeQuerySumToRoot(pa1,pa2));
		}
		if(str[1] == 'H'){
			TreeUpdate(pa1,pa2*1LL);
		}
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}	
	
	
