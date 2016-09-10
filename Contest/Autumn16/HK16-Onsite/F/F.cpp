#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn = 1e5+10;
typedef long long LL;
LL c[maxn],t[maxn];
int n;
LL Division (LL a,LL b){
	return (a%b==0)?(a/b):(a/b+1);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input","r",stdin);
#endif
	while(scanf("%d",&n) == 1){
		for(int i = 1; i < n; i++)scanf("%lld",&c[i]);
		for(int i = 1; i <= n; i++)scanf("%lld",&t[i]);
		LL Time = 0, Cost = 0;
		for(int i = 2; i <= n; i++){
			Time ++;
			Cost += c[i-1];
			if(Time < t[i]){
				int rounds = Division(t[i]-Time, 2LL);
				LL sum = 0, min = 1e15;
				for(int j = 1; j <= rounds; j++){
					sum = sum + c[i-j];
					
		}
		printf("%lld\n",Cost);
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
		
