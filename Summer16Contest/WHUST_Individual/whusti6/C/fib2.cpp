/*************************************************************************
    > File Name: fib2.cpp
    > Author: SnowyJune
    > Mail: SnowyJune 
    > Created Time: 2016年08月01日 星期一 19时06分29秒
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
const LL lmax = 0x7fffffffffffffffLL;
ULL fib[100];
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	fib[0] = fib[1] = 1;
	for(int i = 2;; i++){
		fib[i] = fib[i-1] + fib[i-2];
		if(fib[i] > 2147483648000000){
			printf("%d\n",i);
			break;
		}
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
