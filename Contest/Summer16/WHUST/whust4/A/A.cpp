#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
const int maxn = 5005, maxm = 20005;
int vis[maxn],f[maxn],cd[maxn],rd[maxn],a,b,e,p;
vector<int> E[maxn],F[maxn];
void bfs(int rd[],vector<int> E[]){
	queue<int> Q;
	while(!Q.empty())Q.pop();
	for(int i = 0; i < e; i++){
		if(rd[i] == 0){
			vis[i] = 1;
			f[i] = 1;
			Q.push(i);
		}
	}
	while(!Q.empty()){
		int fr = Q.front();
		f[fr] -= (vis[fr]-1);
		printf("F %d = %d\n",fr,f[fr]);
		Q.pop();
		for(vector<int>::iterator it = E[fr].begin(); it != E[fr].end(); it++){
			f[*it] += (f[fr] + 1);
			vis[*it] ++;
			printf("Vis %d = %d, F %d = %d\n",*it,vis[*it],*it,f[*it]);
			if(vis[*it] == rd[*it])Q.push(*it);
		}
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	while(scanf("%d%d%d%d",&a,&b,&e,&p) == 4){
		for(int i = 0; i < e; i++)E[i].clear();
		int t1,t2;
		ms(rd,0);
		ms(cd,0);
		for(int i = 1; i <= p; i++){
			scanf("%d%d",&t1,&t2);
			E[t1].push_back(t2);
			F[t2].push_back(t1);
			cd[t1]++;
			rd[t2]++;
		}
		ms(vis,0);
		ms(f,0);
		bfs(rd,E);
		int oka=0,okb=0,notok=0;
		for(int i = 0; i < e; i++){
			printf("F[%d] = %d\n",i,f[i]);
			if(f[i] > b){
				notok ++;
			}
		}
		ms(vis,0);
		ms(f,0);
		bfs(cd,F);
		for(int i = 0; i < e; i++){
			printf("G[%d] = %d\n",i,f[i]);
			if(f[i] > e-a){
				oka ++;
			}
			if(f[i] > e-b){
				okb ++;
			}
		}
		printf("%d\n%d\n%d\n",oka,okb,notok);
	}
	return 0;
}
		

