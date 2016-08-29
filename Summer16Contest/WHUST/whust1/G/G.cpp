/*************************************************************************
    > File Name: G.cpp
    > Author: SnowyJune
    > Mail: SnowyJune 
    > Created Time: 2016年08月07日 星期日 15时29分41秒
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
const int maxn = 50005, maxab = 305;
int mod = 1e9+7;
int dp1[maxab],dp2[maxab];
void calc(int n,int a,int b){
	int sta,stb;
	ms(dp1,0);
	ms(dp2,0);
	dp1[1] = dp2[1] = 1;
	for(int i = 2; i <= n; i++){
		int sa=0,sb=0;
		for(int j = 1; j <= a; j++){
			sa=(sa+dp1[j])%mod;
		}
		for(int j = 1; j <= b; j++){
			sb=(sb+dp2[j])%mod;
		}
		for(int j = a; j >= 2; j--){
			dp1[j] = dp1[j-1];
		}
		for(int j = b; j >= 2; j--){
			dp2[j] = dp2[j-1];
		}
		dp1[1] = sb;
		dp2[1] = sa;
	}
	int res = 0;
	for(int i = 1; i <= a; i++)res = (res+dp1[i])%mod;
	for(int i = 1; i <= b; i++)res = (res+dp2[i])%mod;
	cout << res << endl;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	int n,a,b;
	cin >> n >> a >> b;
	calc(n,a,b);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
