#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;
set<int> S;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
void work(){
	int n,a[600];
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
	}
	S.clear();
	for(int i = 1; i < n; i++){
		for(int j = i+1; j <= n; j++){
			S.insert(gcd(a[i],a[j]));
		}
	}
	for(set<int>::iterator it = S.begin(); it != S.end(); it++){
		if(it != S.begin())putchar(' ');
		printf("%d",*it);
	}
	puts("");
}
int main(){
#ifdef SNOWYJUNE
	freopen("input","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T--)work();
#ifdef SNOWYJUNE
	fclose(stdin);
#endif
	return 0;
}
	
