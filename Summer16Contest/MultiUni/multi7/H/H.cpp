/*************************************************************************
    > File Name: H.cpp
    > Author: SnowyJune
    > Mail: SnowyJune 
    > Created Time: 2016年08月09日 星期二 16时48分14秒
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
LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}
struct frac{
	LL q,p;
	void reduce(){
		int GCD = gcd(q,p);
		q /= GCD, p /= GCD;
	}
	frac(int _q = 0, int _p = 1){
		q = _q, p = _p;
	}
};
frac operator + (frac a,frac b){
	frac tmp(a.q*b.p+a.p*b.q,a.p*b.p);
	tmp.reduce();
	return tmp;
}
frac operator * (frac a,frac b){
	frac tmp(a.q*b.q,a.p*b.p);
	tmp.reduce();
	return tmp;
}
double dp[1200000];
int P,N,M,TotCard[1200000];
int arr[25];
void work(){
	char s[29];
	int two[23];
	two[0] = 0;
	for(int i = 1; i <= 20; i++)two[i] = two[i-1] * 2;
	scanf("%d%d%d",&P,&N,&M);
	for(int i = 0; i < (1 << (N+M)); i++)dp[i] = frac(0,1);
	dp[(1 << (N+M)) - 1] = frac(1,1);
	for(int i = (1 << (N+M) - 1); i >= 0; i--){
		int tmp = i, Acard=0, Bcard=0;
		for(int j = 0; j < N+M; j++){
			s[j] = tmp&1;
			tmp>>=1;
			if(j < N)Acard++;
			else Bcard++;
		}
		TotCard[i] = Acard+Bcard;
		for(int j = 0; j < N; j++){
			if(s[j] == 1){
				int prev;
				if(Bcard == 0){
					dp[i-two[j]] += frac(1,TotCard[i]) * dp[i];
				}
				else if(Bcard == 1){
					
				}
				for(int k = N; k < M+N; k++){
					for(int l = k+1; l < M+N; l++){
						if(s[k] == 1 && s[l] == 1){
							int prev = i-two[j]-two[k]-two[l];
						}
					}
				}
			}
		}
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T--){
		work();
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
