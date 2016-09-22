#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e5+10;
int mul = 1;
struct graph{
	vector<int> e[maxn];
	int n,m,fa[maxn],deg[maxn],self[maxn],ci[maxn];
	void input(){
		scanf("%d%d",&n,&m);
		for(int i = 1; i <= n; i++)e[i].clear();
		for(int i = 1; i <= n; i++)fa[i] = i;
		for(int i = 1; i <= n; i++)scanf("%d",&ci[i]);
		memset(deg,0,sizeof(deg));
		memset(self,0,sizeof(self));
		for(int i = 1; i <= m; i++){
			int pa1,pa2;
			scanf("%d%d",&pa1,&pa2);
			if(pa1 != pa2){
				e[pa1].push_back(pa2);
				e[pa2].push_back(pa1);
				deg[pa1]++,deg[pa2]++;
			}
			else{
				self[pa1]++;
			}
		}
	}
	int Getfather(int x){
		return (fa[x]==x)?x:(fa[x]=Getfather(fa[x]));
	}
	void Merge(int x,int y){
		int fx = Getfather(x), fy = Getfather(y);
		fa[fx]=fy;
	}
	bool JudgeConnect(){
		for(int i = 1; i <= n; i++){
			for(vector<int>::iterator it = e[i].begin(); it != e[i].end(); it++){
//				printf("Edge %d <-> %d\n",i,*it);
				if(Getfather(i) != Getfather(*it)){
					Merge(i,*it);
				}
			}
		}
		for(int i = 2; i <= n; i++){
			if(Getfather(i) != Getfather(1))return false;
		}
		return true;
	}
}G;
void work(){
	int res=0;
	mul=1;
	G.input();
	if(!G.JudgeConnect()){
		puts("Impossible");
		return;
	}
	vector<int> TMP;
	TMP.clear();
	for(int i = 1; i <= G.n; i++){
		if(G.deg[i]&1){
			TMP.push_back(i);
		}
	}
	if(TMP.size() != 0 && TMP.size() != 2){
		puts("Impossible");
		return;
	}
	for(int i = 1; i <= G.n; i++){
		if(G.deg[i]%2==0 && (G.deg[i]/2)&1)res^=G.ci[i];
		if(G.self[i]&1)res^=G.ci[i];
	}
	if(TMP.size()==0){
		int a = res;
		res = -1;
		for(int i = 1; i <= G.n; i++){
			res = max(res,a^G.ci[i]);
		}
	}
	else{
		for(int i = 0; i < 2; i++){
			res^=G.ci[TMP[i]];
		}
	}
	printf("%d\n",res);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T--)work();
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
