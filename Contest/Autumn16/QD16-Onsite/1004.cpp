#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;
LL l,r;
int main(){
#ifdef SNOWYJUNE
	freopen("input","r",stdin);
#endif
	while(scanf("%lld%lld",&l,&r) == 2){
		if(r<=2){
			if(r<=1){
				puts("0");
			}
			else{
				puts("1");
			}
		}
		else{
			if(l==0)l=1;
			//printf("L=%lld, R=%lld\n",l,r);
			printf("%lld\n",2+max(0LL,(r-l-2)/2));
		}
	}
#ifdef SNOWYJUNE
	fclose(stdin);
#endif
	return 0;
}
