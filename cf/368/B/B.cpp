#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxm = 1e5+10, maxn = 1e5+10;
struct Edge{
	int u,v,l;
	bool operator < (const Edge &b){
		return l < b.l;
	}
}e[maxm<<1];
bool has[maxn];
int n,m,k;
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	int x;
	memset(has,0,sizeof(has));
	memset(e,0,sizeof(e));
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1; i <= m; i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].l);
	}
	sort(e+1,e+m+1);
	for(int i = 1; i <= k; i++){
		scanf("%d",&x);
		has[x] = true;
	}
	for(int i = 1; i <= m; i++){
		if(has[e[i].u]^has[e[i].v]){
			printf("%d\n",e[i].l);
			return 0;
		}
	}
	puts("-1");
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
	
