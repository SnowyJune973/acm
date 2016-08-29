/*************************************************************************
    > File Name: test_fib_qj.cpp
    > Author: SnowyJune
    > Mail: SnowyJune 
    > Created Time: 2016年07月31日 星期日 00时07分20秒
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
const int intmax = 2147483647;
const LL linf = 0x3f3f3f3f3f3f3f3fLL;
LL fib[50];
LL fibl[50],fibr[50];
int n;
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
	freopen("Fib","w",stdout);
#endif
	fib[0] = 0, fib[1] = 1;
	for(int i = 2;; i++){
		fib[i] = fib[i-1] + fib[i-2];
		//printf("Fib %d = %lld\n",i,fib[i]);
		if(fib[i] > intmax){
			n = i;
			break;
		}
	}
	for(int i = 0; i <= 46; i++){
		printf("%lld,",fib[i]);
	}
	return 0;
	printf("%d\n",n);
	FILE* fout = fopen("Fib","w");
	for(int i = 0; i <= n; i++)fibl[i] = fibr[i] = fib[i];
	for(LL i = 2; i <= intmax; i++){
		if(i%1000000 == 0){
			printf("I = %d Million\n",i);
		}
		for(int j = 3; j <= n-1; j++){
			if(i >= fib[j] && i <= fib[j+1]){
				if(i-fib[j] <= fib[j+1]-i){
					fibl[j] = min(fibl[j],1LL*i);
					fibr[j] = max(fibr[j],1LL*i);
				}
				else{
					fibl[j+1] = min(fibl[j+1],1LL*i);
					fibr[j+1] = max(fibr[j+1],1LL*i);
				}
				break;
			}
		}
	}
	for(int i = 0; i <= n; i++){
		fprintf(fout,"%lld,",fibl[i]);
	}
	puts("");
	puts("***************************************");
	for(int i = 0; i <= n; i++){
		fprintf(fout,"%lld,",fibr[i]);
	}
	puts("");
	fclose(fout);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
