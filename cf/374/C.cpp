#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#define prev __1234567
using namespace std;
typedef long long LL;
const int maxn = 5005;
const int inf = 0x3f3f3f3f;
int dp[maxn][maxn];
vector<pair<int,int> > e[maxn];
int n,m,prev[maxn][maxn];
void init(){
	for(int i = 1; i <= n; i++){
		e[i].clear();
	}
	memset(prev,-1,sizeof(prev));
	memset(dp,0x3f,sizeof(dp));
}
void addedge(int u,int v,int w){
	e[u].push_back(make_pair(v,w));
}
void relax(int u,int v,int w){
	for(int i = 1; i < n; i++){
		if(dp[u][i] + w < dp[v][i+1]){
			dp[v][i+1] = dp[u][i] + w;
			prev[v][i+1] = u;
		}
	}
}
void spfa(){
	queue<int> Q;
	while(!Q.empty())Q.pop();
	bool inqueue[maxn];
	memset(inqueue,false,sizeof(inqueue));
	Q.push(1);
	inqueue[1] = true;
	dp[1][1] = 0;
	while(!Q.empty()){
		int fr = Q.front();
		Q.pop();
		inqueue[fr] = false;
		for(vector<pair<int,int> >::iterator it = e[fr].begin(); it != e[fr].end(); it++){
			int nx=it->first, ww=it->second;
			relax(fr,nx,ww);
			if(!inqueue[nx]){
				Q.push(nx);
				inqueue[nx] = true;
			}
		}
	}
}
int main(){
#ifdef SNOWYJUNE
	freopen("input","r",stdin);
#endif
	int k,ww;
	int uu,vv,ans,I,J;
	init();
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1; i <= m; i++){
		scanf("%d%d%d",&uu,&vv,&ww);
		addedge(uu,vv,ww);
	}
	spfa();
	for(int i = n; i >= 1; i--){
//		printf("DP %d %d = %lld\n",n,i,dp[n][i]);
		if(dp[n][i] <= k){
			ans = i;
			break;
		}
	}
	printf("%d\n",ans);
	J = ans, I = n;
	int res[maxn];
	res[J] = I;
	while(prev[I][J] != -1){
		res[J-1] = prev[I][J];
		I = prev[I][J], J--;
	}
	for(int i = 1; i <= ans; i++){
		printf("%d%c",res[i],(i==ans)?'\n':' ');
	}
#ifdef SNOWYJUNE
	fclose(stdin);
#endif
	return 0;
}
