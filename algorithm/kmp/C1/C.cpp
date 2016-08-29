/*************************************************************************
    > File Name: C.cpp
    > Author: SnowyJune
    > Mail: SnowyJune 
    > Created Time: 2016年08月08日 星期一 14时27分32秒
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
char s[1000010];
int next[1000010];
void run(){
	int len = strlen(s+1),res = 1;
	s[len+1] = '$';
	next[1] = 0;
	for(int i = 2; i <= len+1; i++){
		if(s[next[i-1]+1] == s[i]){
			next[i] = next[i-1] + 1;
		}
		else{
			int k = next[i-1];
			while(s[next[k]+1] != s[i] && k>0)k=next[k];
			next[i] = (k?(next[k]+1):0);
		}
	}
	if(len%(len-next[len]) != 0)res = 1;
	else res = len/(len-next[len]);
	printf("%d\n",res);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	while(1){
		scanf("%s",s+1);
		if(s[1] == '.')break;
		run();
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
