#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,k,cnt[200];
char s[200];
int main(){
#ifdef SNOWYJUNE
	freopen("input","r",stdin);
#endif
	scanf("%d%d",&n,&k);
	memset(cnt,0,sizeof(cnt));
	for(int i = 1; i <= n; i++){
		scanf("%s",s);
		cnt[strlen(s)]++;
	}
	scanf("%s",s);
	int worse,best=0,len=strlen(s);
	for(int i = 1; i < len; i++)best+=cnt[i];
	worse=best+cnt[len]-1;
	printf("%d %d\n",best+best/k*5+1,worse+worse/k*5+1);
#ifdef SNOWYJUNE
	fclose(stdin);
#endif
	return 0;
}
