/*************************************************************************
  > File Name: D.cpp
  > Author: SnowyJune
  > Mail: SnowyJune 
  > Created Time: 2016年08月08日 星期一 18时03分15秒
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
char s[10010][80];
int f[10010];
int n,m;
bool eqRow(int x,int y){
	for(int i = 1; i <= m; i++){
		if(s[x][i] != s[y][i])return false;
	}
	return true;
}
bool eqColumn(int x,int y){
	for(int i = 1; i <= n; i++){
		if(s[i][x] != s[i][y])return false;
	}
	return true;
}
int workRow(){
	f[0] = -1;
	f[1] = 0;
	for(int i = 2; i <= n; i++){
		if(eqRow(f[i-1]+1,i))f[i] = f[i-1] + 1;
		else{
			int k = f[i-1];
			while(!eqRow(f[k]+1,i) && k>0)k=f[k];
			f[i] = f[k]+1;
		}
	}
	/*	for(int i = 1; i <= n; i++){
		printf("F[%d] = %d\n",i,f[i]);
		}*/
	return n-f[n];
}
int workColumn(){
	f[0] = -1;
	f[1] = 0;
	for(int i = 2; i <= m; i++){
		if(eqColumn(f[i-1]+1,i))f[i] = f[i-1] + 1;
		else{
			int k = f[i-1];
			while(!eqColumn(f[k]+1,i) && k>0)k=f[k];
			f[i] = f[k]+1;
		}
	}
	/*	for(int i = 1; i <= m; i++){
		printf("F[%d] = %d\n",i,f[i]);
		}*/
	return m-f[m];
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	scanf("%d%d\n",&n,&m);
	for(int i = 1; i <= n; i++){
		scanf("%s",s[i]+1);
		//printf("S %d = *%s*\n",i,s[i]+1);
	}
	printf("%d\n",workRow()*workColumn());
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
