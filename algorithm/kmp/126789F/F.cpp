/*************************************************************************
    > File Name: F.cpp
    > Author: SnowyJune
    > Mail: SnowyJune 
    > Created Time: 2016年08月08日 星期一 21时26分14秒
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
const int maxn = 1e6+20;
char str1[maxn],str2[maxn];
int f[maxn];
int super(char s1[],char s2[]){
	int len1 = strlen(s1+1), len2 = strlen(s2+1);
//	printf("%s with %s\n",s1+1,s2+1);
	f[0] = -1;
	f[1] = 0;
	for(int i = 2; i <= len1; i++){
		if(f[i-1] < len2 && s2[f[i-1]+1] == s1[i]){
			f[i] = f[i-1] + 1;
		}
		else{
			int k = f[i-1];
			while(s2[f[k]+1] != s1[i] && k)k = f[k];
			f[i] = f[k] + 1;
		}
		//printf("F %d = %d\n",i,f[i]);
	}
	return len1+len2-f[len1];
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	int T;
	scanf("%d\n",&T);
	while(T--){
		scanf("%s",str1+2);
		scanf("%s",str2+2);
		str1[1] = str2[1] = '$';
		printf("%d\n",min(super(str1,str2+1),super(str2,str1+1))-1);
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
