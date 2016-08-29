#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn = 1e5+10;
int x[maxn];
int n,a;
int cal(int p,int xi,int xj){
	if(p <= xi)return xj - p;
	if(p >= xj)return p - xi;
	else return min(2*(p-xi)+(xj-p),2*(xj-p)+(p-xi));
}
int main(){
	scanf("%d%d",&n,&a);
	for(int i = 1; i <= n; i++){
		scanf("%d",&x[i]);
	}
	if(n==1){
		puts("0");
		return 0;
	}
	sort(x+1,x+n+1);
	printf("%d\n",min(cal(a,x[1],x[n-1]),cal(a,x[2],x[n])));
	return 0;
}
