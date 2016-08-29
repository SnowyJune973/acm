#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
LL a[300005];
int main(){
	LL sum = 0, suml = 0;
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	printf("%lld\n",a[(n+1)/2]);
	return 0;
}
