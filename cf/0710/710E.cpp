#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
LL dp[20000008];
int main(){
#ifndef ONLINE_JUDGE
	freopen("input","r",stdin);
#endif
	int n,x,y;
	cin >> n >> x >> y;
	memset(dp,0x3f,sizeof(dp));
	dp[0] = 0;
	for(int i = 0; i < n; i++){
	//	cout << "DP " << i << " = " << dp[i] << endl;
		dp[i+1] = min(dp[i+1],dp[i]+x);
		dp[2*i] = min(dp[2*i],dp[i]+y);
		if(i>0)dp[2*i-1] = min(dp[2*i-1],dp[i]+x+y);
	}
	cout << dp[n] << endl;
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
