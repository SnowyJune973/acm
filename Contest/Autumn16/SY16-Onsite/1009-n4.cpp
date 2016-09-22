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
	for(int i = l; i < r; i++){
		for(int j = i+1; j <= r; j++){
			if(!coprime[i][j]){
				if(calc(i+1,j-1) == sum[j-1] - sum[i]){
					dp[l][r] = max(dp[l][r],calc(l,i-1) + calc(i+1,j-1) + calc(j+1,r) + val[i] + val[j]);
				}
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
