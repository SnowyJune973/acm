#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
int n,k,a,b;
LL dp[5005][5005],sum[5005][5005];
int main(){
#ifndef ONLINE_JUDGE
	freopen("input","r",stdin);
#endif
	cin >> n >> k >> a >> b;
	memset(dp,0,sizeof(dp));
	memset(sum,0,sizeof(sum));
	dp[0][a] = 1;
	for(int i = a; i <= n; i++)sum[0][i]=1;
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= n; j++){
			if(j==b)continue;
			int dist = abs(j-b)-1,high,low;
			if(j>b){
				high=min(j+dist,n);
				low=max(b+1,j-dist);
			}
			else{
				high=min(j+dist,b-1);
				low=max(1,j-dist);
			}
			dp[i][j] = (sum[i-1][high]-sum[i-1][low-1]) - dp[i-1][j] + mod*3;
			sum[i][j] = (sum[i][j-1]+dp[i][j])%mod;
		}
	}
	LL res = 0;
	for(int i = 1; i <= n; i++)res=(res+dp[k][i])%mod;
	cout << res << endl;
	return 0;
}
