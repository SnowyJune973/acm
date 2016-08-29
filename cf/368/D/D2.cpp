#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1005, maxq = 1e5+10;
int book[maxn][maxn];
int head[maxq],res[maxq],n,m,q,tot;
struct Edge{
	int u,v,type,val1,val2;
	Edge(int para5 = 0,int para1 = 0,int para2 = 0,int para3 = 0,int para4 = 0):
		u(para5),v(para1),type(para2),val1(para3),val2(para4){}
};
Edge e[maxq*2];
bool cmp(Edge a,Edge b){
	return a.u<b.u;
}

void dfs(int p){
	int nxt,type,qi,qj;
	bool flag = false;
	for(int i = head[p]; i < head[p+1]; i++){
		nxt = e[i].v;
		type = e[i].type;
		qi = e[i].val1;
		qj = e[i].val2;

		res[nxt] = res[p];
		if(type == 1)
			if(!book[qi][qj])res[nxt]++,book[qi][qj] = flag = true;
		if(type == 2)
			if(book[qi][qj])res[nxt]--,book[qi][qj] = false,flag = true;
		if(type == 3)
			for(int j = 1; j <= m; j++){
				if(book[qi][j])res[nxt]--;
				else res[nxt] ++;
				book[qi][j] ^= 1;
			}
		dfs(nxt);
		if(type == 1)
			if(flag)book[qi][qj] = false;
		if(type == 2)
			if(flag)book[qi][qj] = true;
		if(type == 3)
			for(int j = 1; j <= m; j++){
				book[qi][j] ^= 1;
			}
	}
}

void work(){
	int qt,qi,qj,qk;
	scanf("%d%d%d",&n,&m,&q);
	ms(book,0);
	ms(res,0);
	ms(e,0);
	ms(head,0);
	tot=0;
	for(int i = 1; i <= q; i++){
		scanf("%d",&qt);
		if(qt < 4){
			scanf("%d",&qi);
			if(qt < 3){
				scanf("%d",&qj);
				e[++tot] = Edge(i-1,i,qt,qi,qj);
			}
			else{
				e[++tot] = Edge(i-1,i,qt,qi);
			}
		}
		else{
			scanf("%d",&qk);
			e[++tot] = Edge(qk,i,qt);
		}
	}
	sort(e+1,e+tot+1,cmp);
	
	for(int i = 1; i <= tot; i++){
		printf("Edge %d: U = %d , V = %d , Type = %d , Var1 = %d , Var2 = %d\n",i,e[i].u,e[i].v,e[i].type,e[i].val1,e[i].val2);
		if(i == 1 || e[i].u != e[i-1].u){
			head[e[i].u] = i;
		}
	}
	head[q+1] = tot+1;
	for(int i = q; i >= 1; i--){
		if(!head[i])head[i] = head[i+1];
	}
	for(int i = 0; i <= q; i++){
//		printf("Head %d = %d\n",i,head[i]);
	}
	dfs(0);
	for(int i = 1; i <= q; i++){
		printf("%d\n",res[i]);
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	work();
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
