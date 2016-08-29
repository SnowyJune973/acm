/*************************************************************************
    > File Name: 5769.cpp
    > Author: SnowyJune
    > Mail: SnowyJune 
    > Created Time: 2016年08月06日 星期六 00时43分03秒
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
const int maxn = 1e5+10;
char str1[maxn],str2[maxn],ch;
struct SuffixArray{
	int A[maxn],C[maxn],sa[maxn],rank[maxn],height[maxn],n;
	struct RadixElement{
		int id,x[2];
		RadixElement(int _a = 0,int _b = 0,int _c = 0){
			id = _a;
			x[0] = _b;
			x[1] = _c;
		}
	}RE[maxn],RT[maxn];
	void calcA(char s[],int len){
		int C2[26],mp[26],k = 0;
		ms(C2,0);
		n = len;
		for(int i = 0; i < len; i++)C2[s[i]-'a']++;
		for(int i = 0; i <= 25; i++){
			if(C2[i]){
				mp[i] = ++k;
			}
		}
		for(int i = 0; i < len; i++){
			A[i] = mp[s[i]-'a'];
			
		}
	}
	void RadixSort(){
		for(int p = 1; p >= 0; p--){
			ms(C,0);
			for(int i = 0; i < n; i++)C[RE[i].x[p]]++;
			for(int i = 1; i <= n; i++)C[i] += C[i-1];
			for(int i = n-1; i >= 0; i--){
				RT[C[RE[i].x[p]]-1] = RE[i];
				C[RE[i].x[p]] --;
			}
			for(int i = 0; i < n; i++)RE[i] = RT[i];
		}
		rank[RE[0].id] = 1;
		for(int i = 1; i < n; i++){
			rank[RE[i].id] = rank[RE[i-1].id];
			if(RE[i].x[0] != RE[i-1].x[0] || RE[i].x[1] != RE[i-1].x[1]){
				rank[RE[i].id] ++;
			}
		}
	}
	void calcSA(){
		for(int i = 0; i < n; i++)RE[i] = RadixElement(i,A[i],0);
		RadixSort();
		for(int j = 1; j < n; j <<= 1){
			for(int i = 0; i < n; i++){
				RE[i].id = i;
				RE[i].x[0] = rank[i];
				RE[i].x[1] = (i+j>=n)?0:(rank[i+j]);
			}
			RadixSort();
		}
		for(int i = 0; i < n; i++)sa[rank[i]] = i;
	}
	void calcHeight(){
		int h=0;
		for(int i = 0; i < n; i++){
			if(rank[i] == 1)h = 0;
			else{
				int j = sa[rank[i]-1];
				if(--h<0)h=0;
				while(A[i+h] == A[j+h]){
					h++;
				}
			}
			height[rank[i]] = h;
		}
	}
	void init(){
		ms(C,0);
	}
}SA;
int e[maxn];
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	int T,nch;
	LL res;
	scanf("%d",&T);
	SA.init();
	for(int t = 1; t <= T; t++){
		scanf("%s %s",str1,str2);
		ch = str1[0];
		int len = strlen(str2);
		nch = res = 0;
		SA.calcA(str2,len);
		SA.calcSA();
		SA.calcHeight();
		for(int i = 0; i < len; i++){
			if(str2[i] == ch){
				nch ++;
				e[nch] = i;	
			}
		}
		e[nch+1] = inf;
		for(int i = 1; i <= nch+1; i++){
		}
		res = 0;
		int nxt = inf;
		for(int i = len-1; i >= 0; i--){
			if(str2[i] == ch){
				nxt = i;
			}
			e[i] = nxt;
		}
		for(int i = 1; i <= len; i++){
			if(e[SA.sa[i]] == inf)continue;
			res = res + len-e[SA.sa[i]] - max(SA.height[i]+SA.sa[i]-e[SA.sa[i]],0);
		}
		printf("Case #%d: %lld\n",t,res);
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
