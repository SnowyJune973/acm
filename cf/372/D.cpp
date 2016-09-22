#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1e3+10, maxm = 1e4+10;
const int inf = 0x3f3f3f3f;
const long long linf = 1LL<<60;
typedef long long LL;
vector<int> e[maxn];
LL w[maxn][maxn];
LL dist[maxn], td[maxn],L;
int s,t,n,m,prev[maxn],route[maxn];
LL spfa(int s,int t,LL d[],bool tup,bool tup2){
	bool inqueue[maxn];
	if(tup2)for(int i = 0; i < n; i++)d[i]=linf;
	memset(inqueue,0,sizeof(inqueue));
	queue<int> Q;
	while(!Q.empty())Q.pop();
	Q.push(s);
	inqueue[s]=true;
	while(!Q.empty()){
		int fr = Q.front();
		Q.pop();
		inqueue[fr]=false;
		for(vector<int>::iterator it = e[fr].begin(); it != e[fr].end(); it++){
			if(d[*it] > d[fr] + el){
				if(el!=0)d[*it] = d[fr]+el;
				else {
					if(tup)d[*it]=d[fr]+1;
					else continue;
				}
				prev[*it] =fr;
				if(!inqueue[*it])Q.push(*it);
			}
		}
	}
	return d[t];
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input","r",stdin);
#endif
	scanf("%d%d%lld%d%d",&n,&m,&L,&s,&t);
	for(int i = 0; i < n; i++)e[i].clear();
	memset(w,0,sizeof(w));
	for(int i = 1; i <= m; i++){
		int pa1,pa2;
		LL pa3;
		scanf("%d%d%lld",&pa1,&pa2,&pa3);
		e[pa1].push_back(pa2);
		e[pa2].push_back(pa1);
		w[pa1][pa2] = w[pa2][pa1] = pa3;
	}
	if(spfa(s,t,dist,true,true) > L){
		puts("NO");
		return 0;
	}
	spfa(s,t,dist,false,true);
	int k=0,jj=t;
	while(jj!=s){
		route[++k]=jj;
		jj=prev[jj];
	}
	route[++k]=s;
	for(int i=1,j=k;i<j;i++,j--)swap(route[i],route[j]);
	for(int i=2;i<=k;i++){
		if(w[route[i-1]][route[i]]==0){
			w[route[i-1]][route[i]]=1;
			spfa(s,t,dist,false,false);
			if(dist[t] <= 
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
