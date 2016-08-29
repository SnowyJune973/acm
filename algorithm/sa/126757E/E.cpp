/*************************************************************************
    > File Name: E.cpp
    > Author: SnowyJune
    > Mail: SnowyJune 
    > Created Time: 2016年08月09日 星期二 00时46分58秒
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
const int maxn = 1000;
char s[maxn];
int belong[maxn],m;
struct SuffixArray{
	int A[maxn],C[maxn],rank[maxn],sa[maxn],height[maxn],n;
	void init(){
		ms(C,0);
	}
	void calcA(char s[],int len){
		n = len;
		for(int i = 0; i < len; i++){
			switch(s[i]){
				case '$': A[i] = 1;break;
				case 'A': A[i] = 2;break;
				case 'C': A[i] = 3;break;
				case 'G': A[i] = 4;break;
				case 'T': A[i] = 5;break;
				default: A[i] = 6;break;
			}
		}
	}
	struct RadixElement{
		int id,x[2];
		void Set(int _a = 0,int _b = 0,int _c = 0){
			id = _a;
			x[0] = _b;
			x[1] = _c;
		}
	}RE[maxn],RT[maxn];
	void RadixSort(){
		for(int y = 1; y >= 0; y--){
			ms(C,0);
			for(int i = 0; i < n; i++)C[RE[i].x[y]]++;
			for(int i = 1; i <= n; i++)C[i] += C[i-1];
			for(int i = n-1; i >= 0; i--)RT[--C[RE[i].x[y]]] = RE[i];
			for(int i = 0; i < n; i++)RE[i] = RT[i];
		}
		rank[RE[0].id] = 1;
		for(int i = 1; i < n; i++){
			rank[RE[i].id] = rank[RE[i-1].id];
			if(RE[i].x[0] != RE[i-1].x[0] || RE[i].x[1] != RE[i-1].x[1])rank[RE[i].id] ++;
		}
	}
	void calcSA(){
		for(int i = 0; i < n; i++)RE[i].Set(i,A[i],0);
		RadixSort();
		for(int j = 1; j < n; j<<=1){
			for(int i = 0; i < n; i++){
				RE[i].Set(i,rank[i],(i+j<n)?rank[i+j]:0);
			}
			RadixSort();
		}
		for(int i = 0; i < n; i++)sa[rank[i]] = i;
	}
	void calcHeight(){
		int h = 0;
		for(int i = 0; i < n; i++){
			if(rank[i] == 1)h=0;
			else{
				int prev = sa[rank[i]-1];
				if(--h<0)h=0;
				while(A[i+h] == A[prev+h])h++;
			}
			height[rank[i]] = h;
		}
	}
}SA;

int ok(int k){
//	printf("Try K = %d\n",k);
	bool vis[maxn];
	int cnt = 0,res = -1;
	for(int i = 2; i <= SA.n; i++){
		if(SA.height[i] < k){
			ms(vis,0);
			cnt = 0;
		}
		else{
			if(belong[SA.sa[i-1]] != -1 && !vis[belong[SA.sa[i-1]]]){
				vis[belong[SA.sa[i-1]]] = true;
				cnt ++;
			}
			if(belong[SA.sa[i]] != -1 && !vis[belong[SA.sa[i]]]){
				vis[belong[SA.sa[i]]] = true;
				cnt ++;
			}
			if(cnt == m){
				//printf("OK at %d.\n",SA.sa[i]);
				//printf("OK String = ");
				//for(int j = SA.sa[i]; j < SA.sa[i] + k; j ++){
				//	putchar(s[j]);
				//}
				//puts("");
				return SA.sa[i];
			}
		}
	}
	return -1;
}

pair<int,int> binary_answer(int l,int r){
	if(l == r)return make_pair(ok(l),l);
	int mid = ((l+r) >> 1) + 1;
	if(ok(mid) != -1)return binary_answer(mid,r);
	else return binary_answer(l,mid-1);
}

void work(){
	char tmp[80];
	int offset = 0;
	SA.init();
	scanf("%d",&m);
	ms(s,0);
	for(int i = 1; i <= m; i++){
		scanf("%s",tmp);
		memcpy(s+offset,tmp,60*sizeof(char));
		offset += 60;
		if(i != m)s[offset++] = '$';
	}
	SA.calcA(s,offset);
	SA.calcSA();
	SA.calcHeight();
	int k = 1;
	for(int i = 0; i < offset; i++){
		if(s[i] == '$'){
			belong[i] = -1;
			k ++;
		}
		else belong[i] = k;
	}
	pair<int,int> P = binary_answer(0,60);
	int pf = P.first, ps = P.second;
	if(ps < 3)puts("no significant commonalities");
	else{
		for(int i = pf; i < pf + ps; i++)putchar(s[i]);
		puts("");
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T--){
		work();
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
