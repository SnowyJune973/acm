/*************************************************************************
    > File Name: A.cpp
    > Author: SnowyJune
    > Mail: SnowyJune 
    > Created Time: 2016年08月08日 星期一 11时12分55秒
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
char W[10005],T[1000010];
int next[10005],cnt = 0;
void run(){
	cnt = 0;
	scanf("%s",W+1);
	scanf("%s",T+1);
	int lenW = strlen(W+1), lenT = strlen(T+1);
	W[++lenW] = '$';
	next[1] = 0;
	for(int i = 2; i <= lenW; i++){
		if(W[next[i-1]] == W[i-1]){
			next[i] = next[i-1] + 1;
		}
		else{
			int k = i-1;
			while(W[next[k]] != W[i-1] && k > 0)k = next[k];
			next[i] = (k?(next[k]+1):1);
		}
	}
	lenW--;
/*	for(int i = 1; i <= lenW; i++){
		printf("%d ",next[i]);
	}
	puts("");*/
	int i = 1,j = 1;
	while(lenW-j <= lenT-i && i <= lenT && j <= lenW){
//		puts("*********************************");
//		printf("I = %d , J = %d\n",i,j);
		if(T[i] == W[j]){
			i ++,j ++;
			if(j == lenW+1){
				cnt ++;
//				printf("Match at %d\n",i-j+1);
				j = next[j];
			}
		}
		else{
			j = next[j];
			if(j == 0){
				i++,j++;
			}
		}
//		printf("I = %d, J = %d\n",i,j);
//		puts("********************************");
	}
	printf("%d\n",cnt);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T--){
		run();
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
