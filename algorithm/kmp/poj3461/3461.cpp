/*************************************************************************
    > File Name: 3461.cpp
    > Author: SnowyJune
    > Mail: SnowyJune 
    > Created Time: 2016年08月07日 星期日 00时21分26秒
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
char W[10100],T[1000100];
int next[10100],f[10100];
void calcNext(char* W,int* next,int* f,int n){
	// The index starts from 1.
	next[1] = f[1] = 0;
	for(int i = 2; i <= n; i++){
		if(W[f[i-1]+1] == W[i]){
			f[i] = f[i-1]+1;
		}
		else{
			int k = f[i-1];
			while(W[k+1] != W[i])k = f[k];
		}
		
		int k = i;
		while(W[f[k]+1] == W[k+1])k = f[k];
		next[i] = k;
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
