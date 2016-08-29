/*************************************************************************
    > File Name: 1743.cpp
    > Author: SnowyJune
    > Mail: SnowyJune 
    > Created Time: 2016年08月05日 星期五 20时05分39秒
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
const int maxn = 2e4+10;
int seq[maxn];
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
	void calcA(int s[],int len){
		int tmp[maxn];
		memcpy(tmp,s,len*sizeof(int));
		n = len;
		sort(s,s+len);
		map<int,int> M;
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
	bool ok(int);
}SA;
int n;
bool SuffixArray::ok(int k){
//	printf("Test %d\n",k);
	int m = SA.n, maximum = m-sa[1], minimum = m-sa[1];
	for(int i = 1; i <= m-1; i++){
//		printf("I+1 = %d\n",i+1);
		if(SA.height[i+1] < k){
			if(maximum - minimum > k)return true;
			maximum = minimum = m-sa[i+1];
//			printf("Max = %d , Min = %d\n",maximum,minimum);
		}
		else{
			maximum = max(maximum,m-sa[i+1]);
			minimum = min(minimum,m-sa[i+1]);
//			printf("Max = %d , Min = %d\n",maximum,minimum);
		}
	}
	return maximum - minimum > k;
}
int BinaryAnswer(int l,int r){
//	printf("L = %d , R = %d\n",l,r);
	if(l == r)return l;
	int mid = ((l+r) >> 1) + 1;
	if(SA.ok(mid))return BinaryAnswer(mid,r);
	else return BinaryAnswer(l,mid-1);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	while(scanf("%d",&n) == 1){
		if(n == 0)break;
		for(int i = 0; i < n; i++){
			scanf("%d",&seq[i]);
		}
		for(int i = 0; i < n-1; i++){
			seq[i] = seq[i+1] - seq[i] + 90;
		}
		seq[n-1] = inf;
/*		for(int i = 0; i < n-1; i++){
			printf("%3d ",seq[i]);
		}
		puts("");*/
		SA.init();
		SA.calcA(seq,n-1);
/*		for(int i = 0; i < n-1; i++){
			printf("%3d ",SA.A[i]);
		}*/
		SA.calcSA();
		SA.calcHeight();
/*		puts("");
		for(int i = 1; i <= n-1; i++)printf("SA %d = %d\n",i,SA.sa[i]);
		for(int i = 0; i < n-1; i++)printf("Rank %d = %d\n",i,SA.rank[i]);
		for(int i = 1; i <= n-1; i++){
			printf("Height %d = %d\n",i,SA.height[i]);
		}*/
		int res = BinaryAnswer(0,n-1) + 1;
		if(res < 5){
			printf("0\n",res);
		}
		else printf("%d\n",res);
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
