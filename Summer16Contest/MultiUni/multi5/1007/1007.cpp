/*************************************************************************
    > File Name: 1007.cpp
    > Author: SnowyJune
    > Mail: SnowyJune 
    > Created Time: 2016年08月02日 星期二 16时28分53秒
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
#define lson(x) (x<<1)
#define rson(x) ((x<<1)|1)
using namespace std;
#define lowbit(x) (x&(-x))
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x3f3f3f3f;
const LL linf = 0x3f3f3f3f3f3f3f3fLL;
bool isdigit[10000][10];
bool isok[100000];
LL ten[6] = {
	1,10,100,1000,10000,100000
};
LL dp[20][100000][10],dpsum[20][100000];
int L,R,K;
//dp[i][j][1]: pres first digit is not 0
//dp[i][j][0]: pres first digit is 0
void init(){
	ms(isdigit,0);
	ms(isok,1);
	for(int i = 0; i < 10000; i++){
		int tmp = i;
		for(int j = 1; j <= 5; j++){
			if(isdigit[tmp][tmp%10])isok[tmp][j] = false;
			isdigit[tmp][tmp%10] = true;
			tmp/=10;
		}
	}
}
void cal(){
	ms(dp,0);
	ms(dpsum,0);
	dp[0][0][0] = 1;
	for(int i = 0; i <= 17; i++){
		for(int j = 0; j < ten[K]; j++){
			int base = (i>=K)?(j/10):j;
			if(!isok[base][min(i,K-1)])continue;
			dp[i+1][base][0] += (dp[i][j][0] + dp[i][j][1]);
			for(int k = 1; k <= 9; k++){
				int nxt = base+k*ten[min(i,K-1)];
				if(isok[nxt])dp[i+1][nxt][k] += (dp[i][j][0] + dp[i][j][1]);
			}
		}
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif

#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
