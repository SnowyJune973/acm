/*************************************************************************
    > File Name: B.cpp
    > Author: SnowyJune
    > Mail: SnowyJune 
    > Created Time: 2016年08月08日 星期一 12时06分11秒
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
char s[400010];
int next[400010],res[400010];
void getNext(){
	int len = strlen(s+1),top = 0;
	s[len+1] = '$';
	next[1] = 0;
	for(int i = 2; i <= len+1; i++){
		if(s[next[i-1]+1] == s[i]){
			next[i] = next[i-1] + 1;
		}
		else{
			int k = next[i-1];
			while(s[next[k]+1] != s[i] && k > 0)k = next[k];
			next[i] = (k?(next[k]+1):0);
		}
	}
	/*for(int i = 1; i <= len; i++){
		printf("Next %d = %d\n",i,next[i]);
	}*/
	int k = len;
	while(k){
		res[++top] = k;
		k = next[k];
	}
	//if(s[1] == s[len])res[++top] = 1;
	while(top){
		printf("%d",res[top--]);
		if(top)putchar(' ');
	}
	puts("");
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	while(scanf("%s",s+1) == 1){
		getNext();
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
