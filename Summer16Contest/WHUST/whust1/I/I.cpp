/*************************************************************************
    > File Name: I.cpp
    > Author: SnowyJune
    > Mail: SnowyJune 
    > Created Time: 2016年08月07日 星期日 17时00分46秒
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
char flow1[1005],flow2[1005];
int len1,len2;
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	scanf("%s %s",flow1+1,flow2+1);
	len1 = strlen(flow1+1);
	len2 = strlen(flow2+1);
	int i = 1,j = 1,t = 0;
	while(i <= len1 || j <= len2){
		t ++;
		if(i <= len1 && j <= len2){
			if(flow1[i] != 'L' && flow2[j] != 'L'){
				i++,j++;
			}
			else if(flow1[i] == 'L' && flow2[j] == 'L'){
				i++,j++;
			}
			else{
				if(flow1[i] == 'L'){
					j++;
				}
				else i++;
			}
		}
		else{
			if(i <= len1){
				i++;
			}
			else j++;
		}
	}
	printf("%d\n",t);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
