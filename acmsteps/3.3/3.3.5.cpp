#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL linf = 0x3f3f3f3f3f3f3f3f;
LL dp[105][105], A[105][105];
int n,m;
void work(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%lld",&A[i][j]);
		}
	}
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++){
		dp[i][0] = 0;
		for(int j = 1; j <= m; j++){
			dp[i][j] = -linf;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j] = dp[i-1][j];
			for(int k = 1; k <= j; k++){
				dp[i][j] = max(dp[i][j],dp[i-1][j-k] + A[i][k]);
			}
		}
	}
	printf("%lld\n",dp[n][m]);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	while(scanf("%d%d",&n,&m) == 2){
		if(!n && !m)break;
		work();
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}

