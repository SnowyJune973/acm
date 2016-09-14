#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
LL dp[12][10];
void cal(){
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	for(int i = 0; i < 10; i++)dp[1][i] = 1;
	for(int i = 2; i <= 10; i++){
		for(int j = 0; j <= 9; j++){
			for(int k = 0; k <= 9; k++){
				if(abs(j-k)<2)continue;
				dp[i][j] += dp[i-1][k];
			}
//			printf("Dp %d %d = %lld\n",i,j,dp[i][j]);
		}
	}
}
LL Count(LL x){
	int dig[15],c=0;
	LL res = 0;
	while(x){
		dig[++c] = x%10;
		x/=10;
	}
	for(int i=1,j=c;i<j;i++,j--){
		swap(dig[i],dig[j]);
	}
	for(int i=1; i<c; i++)
		for(int j=1; j<10; j++)
			res += dp[i][j];
	dig[0] = -100;
	for(int i = 1; i <= c; i++){
	   for(int j = 0; j < dig[i]; j++){
		   if(i==1&&j==0)continue;
		   if(abs(dig[i-1]-j)<2)continue;
		   res += dp[c-i+1][j];
	   }
	   if(abs(dig[i]-dig[i-1])<=1)break;
	}	   
	return res;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input","r",stdin);
#endif
	LL a,b;
	cal();
	while(cin >> a >> b)cout << Count(b+1)-Count(a) << endl;
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
