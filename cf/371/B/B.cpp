#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
typedef long long LL;
const int maxn = 1e5+10;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
using namespace std;
set<int> S;
int main(){
#ifndef ONLINE_JUDGE
	freopen("input","r",stdin);
#endif
	int n,x;
	S.clear();
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&x);
		if(S.find(x)==S.end())S.insert(x);
	}
	if(S.size()>3){
		puts("NO");
	}
	if(S.size()<3){
		puts("YES");
	}
	if(S.size()==3){
		int a[3],t=0;
		for(set<int>::iterator it = S.begin(); it != S.end(); it++){
			a[t++] = *it;
		}
		if(a[1]*2==a[0]+a[2]){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
#ifndef ONLINE_JUDGEd
	fclose(stdin);
#endif
	return 0;
}
