/*=============================================================================
	Author: SnowyJune - me@snowyjune.top
	QQ: 896512060
	Last modified: 2016-10-07 19:10
	Filename: E.cpp
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>
#define hash __12345
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int maxn = 1e5+19;
map<ULL,int> M;
ULL mod = 2305843009213693951ULL, base = 6597069766657ULL;
unsigned int mod2 = 10000019, base2 = 211;
vector<int> e[maxn];
bool vis[maxn];
int n,fa[maxn],tot;
struct rec{
	int dfsid,id;
}arr[maxn];
ULL hash[maxn];
ULL Mul(ULL a,ULL b){
	ULL res = 0;
	while(a){
		if(a&1)res=(res+b)%mod;
		b=(b+b)%mod;
		a>>=1;
	}
	return res;
}
int Mul2(int a,int b){
	int res = 0;
	while(a){
		if(a&1)res=(res+b)%mod2;
		b=(b+b)%mod2;
		a>>=1;
	}
	return res;
}
void input(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)e[i].clear();
	memset(vis,false,sizeof(vis));
	memset(fa,-1,sizeof(fa));
	int t1,t2;
	for(int i = 1; i <= n-1; i++){
		scanf("%d%d",&t1,&t2);
		e[t1].push_back(t2);
		e[t2].push_back(t1);
	}
	for(int i = 1; i <= n; i++)arr[i].id=i;
	M.clear();
	tot=0;
}
/*unsigned int dfs(int x){
	unsigned int res = 1;
	vis[x] = true;
	//printf("X = %d\n",x);
	for(vector<int>::iterator it2 = e[x].begin(); it2 != e[x].end(); it2++){
		int nx = *it2;
		if(vis[nx])continue;
		res += dfs(nx)*base2 % mod2;
		res %= mod2;
	}	
	if(M.find(res)==M.end())M[res]=1;
	else M[res]++;
	vis[x] = false;
	return res;
}*/
void dfs(int x){
	for(vector<int>::iterator it = e[x].begin(); it != e[x].end(); it++){
		int nx = *it;
		if(nx==fa[x])continue;
		fa[nx] = x;
		dfs(nx);
	}
	arr[x].dfsid = (++tot);
	//printf("%d's dfsid = %d\n",x,arr[x].dfsid);
};
bool cmpdfsid(rec a,rec b){
	return a.dfsid<b.dfsid;
}
bool cmpid(rec a,rec b){
	return a.id<b.id;
}
int main(){
#ifdef SNOWYJUNE
	freopen("input","r",stdin);
#endif
	input();
	dfs(1);
	sort(arr+1,arr+n+1,cmpdfsid);
	for(int i = 1; i <= n; i++){
		hash[arr[i].id] = 1;
		for(vector<int>::iterator it = e[arr[i].id].begin(); it != e[arr[i].id].end(); it++){
			if(fa[arr[i].id] == *it)continue;
			hash[arr[i].id] += Mul(hash[*it],base);
			hash[arr[i].id] %= mod;
		}
		if(M.find(hash[arr[i].id])==M.end())M[hash[arr[i].id]] = 1;
		else M[hash[arr[i].id]]++;
//		printf("%d's hash = %llu, M[hash] = %d\n",arr[i].id,hash[arr[i].id],M[hash[arr[i].id]]);
	}
	LL ans = 0;
	for(map<ULL,int>::iterator it = M.begin(); it != M.end(); it++){
		ans += 1LL*(it->second)*((it->second)-1)/2;
	}
	printf("%lld\n",ans);
#ifdef SNOWYJUNE
	fclose(stdin);
#endif
	return 0;
}

