#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1005;
int sheng[maxn],shenghui[maxn],stack[maxn],uben,N,B,tot;
bool vis[maxn];
vector<int> e[maxn];
void init(){
	for(int i = 1; i <= 1000; i++)e[i].clear();
	memset(sheng,-1,sizeof(sheng));
	memset(shenghui,-1,sizeof(shenghui));
	memset(vis,0,sizeof(vis));
	uben = tot = 0;
}
int dfs(int x){
	int zishu = 1;
	int unter = uben;
	vis[x] = true;
	for(vector<int>::iterator it = e[x].begin(); it != e[x].end(); it++){
		if(vis[*it])continue;
		int nxt = *it;
		zishu += dfs(nxt);
		vis[nxt] = true;
		if(zishu > B){
			tot++;
			shenghui[tot] = x;
			while(uben > unter){
				sheng[stack[uben--]] = tot;
			}
			zishu = 1;
		}
	}
	stack[++uben] = x;
	return zishu;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input","r",stdin);
#endif
	scanf("%d%d",&N,&B);
	int tmp1,tmp2;
	init();
	for(int i = 1; i <= N-1; i++){
		scanf("%d%d",&tmp1,&tmp2);
		e[tmp1].push_back(tmp2);
		e[tmp2].push_back(tmp1);
	}
	if(B > N){
		printf("0\n");
	}
	else{
		dfs(1);
		if(tot==0){
			tot++;
			shenghui[tot] = 1;
		}
		for(int i = 1; i <= N; i++){
			if(sheng[i] == -1){
				sheng[i] = tot;
			}
		}
		printf("%d\n",tot);
		for(int i = 1; i <= N; i++){
			printf("%d%c",sheng[i],(i==N)?'\n':' ');
		}
		for(int i = 1; i <= tot; i++){
			printf("%d%c",shenghui[i],(i==tot)?'\n':' ');
		}
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
