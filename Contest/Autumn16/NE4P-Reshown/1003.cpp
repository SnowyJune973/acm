#include <cstdio>
#include <cstdlib>
typedef long long LL;
int main(){
#ifdef SNOWYJUNE
	freopen("input","r",stdin);
#endif
	int T;
	LL a,b;
	scanf("%d",&T);
	for(int i = 1; i <= T; i++){
		scanf("%lld%lld",&a,&b);
		printf("Case #%d:\n",i);
		if(a==b){
			printf("1\n%lld %lld\n",a,b);
		}
		else{
			printf("2\n%lld %lld\n%lld %lld\n",a,b,b,a);
		}
	}
#ifdef SNOWYJUNE
	fclose(stdin);
#endif
	return 0;
}
