/*************************************************************************
    > File Name: 2774.cpp
    > Author: SnowyJune
    > Mail: SnowyJune 
    > Created Time: 2016年08月05日 星期五 18时05分39秒
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
const int maxn = 2e5+10;
char str1[maxn],str2[maxn];
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
		char tmp[maxn];
		memcpy(tmp,s,len*sizeof(char));
		n = len;
		sort(s,s+len);
		map<char,int> M;
		M.clear();
		int k = 0;
		for(int i = 0; i < len; i++){
			if(i == 0 || s[i] != s[i-1]){
				k ++;
				M[s[i]] = k;
			}
		}
		for(int i = 0; i < len; i++){
			A[i] = M[tmp[i]];
			//printf("A %d = %d\n",i,A[i]);
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
		int h;
		for(int i = 0; i < n; i++){
			if(rank[i] == 1)h = 0;
			else{
				int j = sa[rank[i]-1];
				if(--h<0)h=0;
				while(A[i+h] == A[j+h])h++;
			}
			height[rank[i]] = h;
		}
	}
	void init(){
		ms(C,0);
	}
}SA;
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	scanf("%s %s",str1,str2);
	int len1 = strlen(str1);
	strcat(str1,"$");
	strcat(str1,str2);
	int len = strlen(str1);
	SA.init();
	SA.calcA(str1,len);
	SA.calcSA();
	SA.calcHeight();
/*	for(int i = 0; i < len; i++){
		printf("Rank %d = %d\n",i,SA.rank[i]);
	}
	for(int i = 1; i <= len; i++){
		printf("SA %d = %d\n",i,SA.sa[i]);
	}
	for(int i = 1; i <= len; i++){
		printf("Height %d = %d\n",i,SA.height[i]);
	}
*/	int res = 0;
	for(int i = 2; i <= len; i++){
		if(1LL * (SA.sa[i]-len1) * (SA.sa[i-1]-len1) < 0)res = max(res,SA.height[i]);
	}
	printf("%d\n",res);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
