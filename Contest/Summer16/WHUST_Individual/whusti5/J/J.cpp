/*************************************************************************
  > File Name: J.cpp
  > Author: SnowyJune
  > Mail: SnowyJune 
  > Created Time: 2016年07月29日 星期五 23时51分02秒
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
const int maxn = 1e6+19;
char s[maxn];
int dp[maxn],qm[maxn],lb,rb,cnt;
bool lok[maxn],rok[maxn];
int judge(){
	lb = rb = cnt = 0;
	int len = strlen(s),totl=0,totr=0;
	if(len&1)return 0;
	for(int i = 0; i < len; i++){
		if(s[i] == '(')totl++;
		if(s[i] == ')')totr++;
	}
	for(int i = 0; i < len; i++){
		//Case (
		if(s[i] == '(')lb++;
		if(s[i] == ')')rb++;
		if(s[i] == '?'){
			if(totl < len/2)lok[i] = true;
			if(lb>rb && totr < len/2)rok[i] = true;
			if(!lok[i] && !rok[i])return 0;
		}
	}
	lb = rb = 0;
	for(int i = len-1; i >= 0; i--){
		if(s[i] == '(')lb++;
		if(s[i] == ')')rb++;
		if(s[i] == '?'){
			rok[i] = rok[i] && (totr < len/2);
			lok[i] = lok[i] && (rb>lb && totl < len/2);
			if(!lok[i] && !rok[i])return 0;
			if(lok[i] && rok[i])return 2;
			if(lok[i]){
				lb++;
				totl++;
			}
			if(rok[i]){
				rb++;
				totr++;
			}
		}
	}
	return 1;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	int lb,rb;
	while(scanf("%s",s) == 1){
		switch(judge()){
			case 0:puts("None");break;
			case 1:puts("Unique");break;
			case 2:puts("Many");break;
			default:break;
		}
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
