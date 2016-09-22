#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn = 1e5+10;
const int inf = 0x3f3f3f3f;
const long long linf = 1LL<<60;
typedef long long LL;
int t[maxn],n,c;
int main(){
#ifndef ONLINE_JUDGE
	freopen("input","r",stdin);
#endif
	scanf("%d%d",&n,&c);
	for(int i = 1; i <= n; i++){
		scanf("%d",&t[i]);
	}
	int cnt = 1;
	for(int i = 2; i <= n; i++){
		if(t[i]-t[i-1]>c){
			cnt=1;
		}
		else cnt++;
	}
	printf("%d\n",cnt);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
