#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define pos(x,y) (x*n+y)
using namespace std;
const int MAXN = 420;
const double eps = 1e-8;
int n,m,s1,s2,fa[MAXN],deg[MAXN];
bool graph[25][25];
 double p,dp[40000][20][20];
 double calc_E(int t){
		for(int j = 0; j < n; j++){
			p += t*dp[t][j][j];
		}
	//printf("At Iteration %d: Expectation = %f\n",t,p);
}
int getfather(int x){
	return (fa[x]==x)?x:(fa[x]=getfather(fa[x]));
}
void Merge(int x,int y){
	int fx = getfather(x),fy = getfather(y);
	fa[fx] = fy;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	memset(graph,0,sizeof(graph));
	int pa1,pa2;
	memset(deg,0,sizeof(deg));
	for(int i = 0; i < n; i++)fa[i] = i;
	for(int i = 1; i <= m; i++){
		scanf("%d%d",&pa1,&pa2);
		graph[pa1][pa2] = graph[pa2][pa1] = true;
		deg[pa1]++, deg[pa2]++;
		Merge(pa1,pa2);
	}
	scanf("%d%d",&s1,&s2);
	if(s1 == s2){
		puts("0");
		return 0;
	}
	if(getfather(s1) != getfather(s2)){
		puts("never meet");
		return 0;
	}
	int blk = getfather(s1);
	memset(dp,0,sizeof(dp));
	dp[0][s1][s2] = 1;
	double prev;
	p=0;
	for(int t = 0; t < 39999; t++){
//		printf("T = %d\n",t);
		for(int i = 0; i < n; i++){
			if(getfather(i) != blk)continue;
			for(int j = 0; j < n; j++){
				if(deg[i] * deg[j] == 0)continue;
				if(getfather(j) != blk)continue;
				if(i==j)continue;
				if(dp[t][i][j] < 1e-12)continue;
				for(int k = 0; k < n; k++){
					if(!graph[i][k])continue;
					for(int l = 0; l < n; l++){
						if(!graph[j][l])continue;
						dp[t+1][k][l] += dp[t][i][j] / (deg[i]*deg[j]);
	//					printf("DP %d %d %d = %.14Lf\n",t+1,k,l,dp[t+1][k][l]);
					}
				}
			}
		}
		calc_E(t+1);
		//printf("P = %.14f\n",p);
		if(t>n*n && fabs(p-prev)<1e-8)break;
		prev=p;
	//	getchar();
	}
	//printf("TEST: %.14f\n",p);
	if(p>eps)printf("%.14f\n",p);
	else puts("never meet");
#ifndef ONLINE_JUDGE
//	fclose(stdin);
#endif
	return 0;
}


