#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn = 1e5+10;
int a[maxn];
int main(){
	int n,b,d,buffer=0,cnt=0;
	scanf("%d%d%d",&n,&b,&d);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
		if(a[i]<=b)buffer+=a[i];
		if(buffer>d)buffer=0,cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}

