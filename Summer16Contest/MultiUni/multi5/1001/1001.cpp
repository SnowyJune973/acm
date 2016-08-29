/*************************************************************************
    > File Name: 1001.cpp
    > Author: SnowyJune
    > Mail: SnowyJune 
    > Created Time: 2016年08月02日 星期二 15时01分43秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#define ms(x,y) memset(x,y,sizeof(x))
#define lson(x) (x>>1)
#define rson(x) ((x>>1)|1)
using namespace std;
#define lowbit(x) (x&(-x))
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x3f3f3f3f;
const LL linf = 0x3f3f3f3f3f3f3f3fLL;
const double dinf = 1e20;
double dp[2100][2100];
int two[15] = {
	1,2,4,8,16,32,64,128,256,512,1024,2048
};
int suitable[2100];
void init(){
	for(int i = 1; i <= 2000; i++){
		for(int j = 1; j <= 12; j++){
			if(two[j]-1>i){
				suitable[i] = j;
				break;
			}
		}
	}
}
void run(int K,int W){
//	printf("K = %d , W = %d\n",K,W);
	W = min(W,suitable[K]);
	ms(dp,0);
	dp[1][0] = dinf;
	for(int i = 1; i <= W; i++)dp[1][i] = 1;
	for(int i = 2; i <= K; i++){
//		printf("I = %d\n",i);
		dp[i][0] = dinf;
		dp[i][1] = (double)(1LL*i*(i+3)/2)/(i+1);
//		printf("Dp(%d,1) = %.6lf\n",i,dp[i][1]);
		for(int j = 2; j <= W; j++){
//			printf("J = %d\n",j);
			dp[i][j] = dinf;
			for(int k = 1; k <= i; k++){
				dp[i][j] = min(dp[i][j],(dp[k-1][j-1] * k + dp[i-k][j] * (i-k+1))/(i+1)+1);
			}
		//	if(dp[i][j] == dp[i][j-1] && dp[i][j-1] != dp[i][j-2]){
		//		printf("I = %d Ends at J = %d\n",i,j-1);
				
		//	}
//			printf("Dp(%d,%d) = %.6lf\n",i,j,dp[i][j]);
		}
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	int k,w;
	init();
	run(2000,2000);
	while(scanf("%d%d",&k,&w) == 2){
		w = min(w,suitable[k]);
		printf("%.6lf\n",dp[k][w]);
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
