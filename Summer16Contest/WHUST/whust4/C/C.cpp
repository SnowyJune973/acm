#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5+19;
LL a[maxn],sum[maxn],two[20];
int n;
void init(){
	two[0] = 1;
	for(int i = 1; i <= 19; i++)two[i]=two[i-1]*2;
//	sum[0] = 0;
//	for(int i = 1; i <= n; i++)sum[i] = sum[i-1] + a[i];
}
int lg2(LL x){
	int res = 0;
	while(x){
		res++;
		x>>=1;
	}
	return res;
}
/*LL work(){
	if(l>r)return 0;
	for(int i = 0; i <= 19; i++){
		if(two[i] <= r-l+1 && two[i+1] > r-l+1){
			if(two[i] < r-l+1){
				return sum[r]-sum[l-1] + i*(sum[l+two[i]-1] - sum[l-1]) + work(l+two[i],r);
			}
			else{
				return i*(sum[r]-sum[l-1]);
			}
		}
	}
}*/
struct dt{
	LL k,val;
}RE[maxn];
bool cmp(LL a,LL b){
	return a>b;
}
bool cmp2(dt a,dt b){
	return a.k < b.k;
}
int main(){
#ifndef ONLINE_JUDGE
//	freopen("/home/snowyjune/code/input","r",stdin);
	freopen("1.in","r",stdin);
	freopen("user","w",stdout);
#endif
	int T;
	LL res = 0;
	scanf("%d",&T);
	init();
	while(T--){
		res = 0;
		scanf("%d",&n);
		for(int i = 1; i <= n; i++)scanf("%lld",&a[i]);
		if(n == 1){
			printf("%lld\n",a[1]);
			continue;
		}
		sort(a+1,a+n+1,cmp);
		int tmp = n, t = 0, k = 0;
		//init();
		while(tmp){
			for(int i = 0; i <= 19; i++){
				if(two[i] <= tmp && two[i+1] > tmp){
					if(two[i] < tmp)k++;
					for(int j = 1; j <= two[i]; j++){
						RE[++t].k = i+k;
					}
					tmp -= two[i];
					break;
				}
			}
		}
		sort(RE+1,RE+n+1,cmp2);
		for(int i = 1; i <= n; i++){
			//printf("RE %d's k = %lld\n",i,RE[i].k);
			res += RE[i].k * a[i];
		}
		printf("%lld\n",res);
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
