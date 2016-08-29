#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;
const int maxn = 1e5+10;
priority_queue<LL,vector<LL>,greater<LL> > Q;
LL a[maxn];
int main(){
#ifndef ONLINE_JUDGE
	freopen("12.in","r",stdin);
	freopen("user","w",stdout);
#endif
	int T,n;
	LL res = 0;
	scanf("%d",&T);
	while(T--){
		res = 0;
		scanf("%d",&n);
		for(int i = 1; i <= n; i++)scanf("%lld",&a[i]);
		while(!Q.empty())Q.pop();
		for(int i = 1; i <= n; i++)Q.push(a[i]);
		while(!Q.empty()){
			LL x1 = Q.top();
			Q.pop();
			if(Q.empty())break;
			LL x2 = Q.top();
			Q.pop();
			res += x1 + x2;
			Q.push(x1+x2);
		}
		printf("%lld\n",res);
	}
	return 0;
}
