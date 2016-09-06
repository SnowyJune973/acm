#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;
typedef unsigned long long ULL;
ULL two[65];
ULL ulinf = ULL(-1);
ULL S[1000000];
int sz;
void work(int N,int M){
	ULL t = 0, xhj1 = two[N+M] - two[M], xhj2 = two[N] - 1;
//	printf("N = %d , M = %d , xhj1 = %llu, xhj2 = %llu\n",N,M,xhj1,xhj2);
	int k = 0;
	do{
		t = t * two[N+M] + xhj1;
		k += N+M;
//		printf("T = %llu, K = %d\n",t,k);
		if(k <= 63)S[++sz]=t;
//		printf("SZ = %d\n",sz);
	}while(k <= 63);
	t = two[N] - 1, k = N;
	//if(k <= 63)S[++sz] = t;
	do{
		t = t * two[N+M] + xhj2;
		k += N+M;
//		printf("T = %llu, K = %d\n",t,k);
		if(k <= 63)S[++sz]=t;
//		printf("SZ = %d\n",sz);
	}while(k <= 63);
}	
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
	//freopen("user","w",stdout);
#endif
	two[0] = 1;
	sz = 0;
	for(int i = 1; i <= 64; i++)two[i]=two[i-1]*2;
	memset(S,0,sizeof(S));
	for(int i = 1; i <= 63; i++){
		for(int j = 1; i+j <= 63; j++){
		   work(i,j);
		}
	}
	for(int i = 1; i <= 63; i++)S[++sz] = two[i]-1;
	S[++sz] = (1ULL)<<63;
	S[++sz] = ulinf;
	sort(S+1,S+sz+1);
	//for(int i = sz-10; i <= sz; i++){
	//	printf("Foul %d =  %llu\n",i,S[i]);
	//}
	//puts("");
	ULL *it1, *it2;
	ULL x,y;
	while(scanf("%llu%llu",&x,&y) == 2){
		it1 = lower_bound(S+1,S+sz+1,x);
		it2 = upper_bound(S+1,S+sz+1,y);
		printf("%d\n",it2-it1);
	}
	return 0;
}
