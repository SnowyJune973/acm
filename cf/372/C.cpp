#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn = 1e5+10;
const int inf = 0x3f3f3f3f;
const long long linf = 1LL<<60;
typedef long long LL;
int main(){
#ifndef ONLINE_JUDGE
	freopen("input","r",stdin);
#endif
	int n;
	scanf("%d",&n);
	for(LL i = 1; i <= n; i++){
		if(i==1LL){
			printf("%lld\n",2);
		}
		else{
			printf("%lld\n",i*i*i+2LL*i*i+1);
		}
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
