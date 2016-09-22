#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 305;
bool coprime[maxn][maxn]; // if key[i] coprimes with key[i+1]
LL sum[maxn],key[maxn],val[maxn],dp[maxn][maxn];
int n;
LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}
void init(){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			coprime[i][j] = gcd(key[i],key[j])==1;
	sum[0] = 0;
	for(int i = 1; i <= n; i++)sum[i]=sum[i-1]+val[i];
	memset(dp,-1,sizeof(dp));
}
LL calc(int l,int r){
	if(l>=r)return 0;
	if(dp[l][r]!=-1)return dp[l][r];
	dp[l][r] = calc(l+1,r);
	if(!coprime[l][l+1])dp[l][r] = max(dp[l][r],val[l]+val[l+1]+calc(l+2,r));
	for(int i = l+2; i <= r; i++){
		if(!coprime[l][i]){
			if(calc(l+1,i-1) == sum[i-1] - sum[l]){
				dp[l][r] = max(dp[l][r],dp[l+1][i-1] + calc(i+1,r)+val[l]+val[i]);
			}
		}
	}
//	printf("DP %d %d = %lld\n",l,r,dp[l][r]);
	return dp[l][r];
}
void work(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)scanf("%lld",&key[i]);
	for(int i = 1; i <= n; i++)scanf("%lld",&val[i]);
	init();
	printf("%lld\n",max(calc(1,n),0LL));
}
int main(){
#ifdef SNOWYJUNE
	freopen("input","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T--)work();
#ifdef SNOWYJUNE
	fclose(stdin);
#endif
	return 0;
}
