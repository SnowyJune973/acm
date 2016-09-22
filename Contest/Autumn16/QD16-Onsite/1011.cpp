#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int NV=1005;
const int NE=10005;
const int inf = 0x3f3f3f3f;
vector<int> ee[NV];
int he[NV],ecnt;
int src,sink,n,m;
struct edge
{
    int v,next,f;
} E[2*NE];
void adde(int u,int v,int c)
{
    E[++ecnt].v=v;
    E[ecnt].f=c;
    E[ecnt].next=he[u];
    he[u]=ecnt;
    E[++ecnt].v=u;
    E[ecnt].f=0;
    E[ecnt].next=he[v];
    he[v]=ecnt;
}
void init()
{
    ecnt=0;
    memset(he,-1,sizeof(he));
	for(int i = 1; i <= n; i++)ee[i].clear();
}
queue<int> que;
bool vis[NV];
int dis[NV];
void bfs()
{
    memset(dis,0,sizeof(dis));
    while(!que.empty()) que.pop();
    vis[src]=1;
    que.push(src);
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        for (int i=he[u]; i!=-1; i=E[i].next)
            if (E[i].f&&!vis[E[i].v])
            {
                que.push(E[i].v);
                dis[E[i].v]=dis[u]+1;
                vis[E[i].v]=1;
            }
    }
}
int dfs(int u,int delta)
{
    if (u==sink)
        return delta;
    else
    {
        int ret=0;
        for (int i=he[u]; delta&&i!=-1; i=E[i].next)
            if (E[i].f&&dis[E[i].v]==dis[u]+1)
            {
                int dd=dfs(E[i].v,min(E[i].f,delta));
                E[i].f-=dd;
                E[(i+1)^1-1].f+=dd;
                delta-=dd;
                ret+=dd;
            }
        return ret;
    }
}
int maxflow()
{
    int ret=0;
    while(1)
    {
        memset(vis,0,sizeof(vis));
        bfs();
        if (!vis[sink]) return ret;
        ret+=dfs(src,inf);
    }
	return ret;
}
void work(){
	init();
	scanf("%d%d",&n,&m);
	src = 1, sink = n;
	int pa1,pa2,pa3;
	for(int i = 1; i <= m; i++){
	   scanf("%d%d%d",&pa1,&pa2,&pa3);
	   adde(pa1,pa2,pa3);
	   adde(pa2,pa1,pa3);
	}
	
	printf("%d\n",maxflow());
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
