#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define ms(x,y) memset(x,y,sizeof(x))
int maxn = 1030;
bool mat[maxn][maxn],mat2[33][33];
int ml[maxn],mr[maxn],prev[maxn],check[maxn],Q[maxn];
int n,m,k;
void Hungarian(int nl,int nr){
	int qfr=1,qre=2,ans;
	ms(ml,-1);
	ms(mr,-1);
	ms(check,-1);
	ms(Q,0);
	for(int i = 1; i <= nl; i++){
		if(ml[i] == -1){
			bool flag = false;
			qfr = 1;
			qre = 1;
			Q[qre++] = i;
			prev[i] = -1;
			while(qfr < qre && !flag){
				int fr = Q[qfr];
				qfr++;
				for(int j = 1; j <= nr && !flag; j++){
					if(mat[i][j] && check[j] != i){
						check[j] = i;
						Q[qre++] = mr[j];
						if(match[j] != -1)prev[mr[j]] = u;
						else{
							int d = fr,e = j;
							flag = true;
							while(d != -1){
								int tmp = ml[d];
								ml[d] = e;
								mr[e] = d;
								d = prev[d];
								e = tmp;
							}
						}
					}
				}
			}
		}
	}
	ans = 0;
	for(int i = 1; i <= nl; i++){
		if(ml[i] != -1)ans++;
	}
	return ans;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&k);
	int id0[33][33],id1[33][33],cnt0=0,cnt1=0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(j>1)mat2[i][j-1] = true;
			if(j<m)mat2[i][j+1] = true;
			if(i>1)mat2[i-1][j] = true;
			if(i<n)mat2[i+1][j] = true;
		}
	}
	int xx,yy;
	for(int i = 1; i <= k; i++){
		scanf("%d%d",&xx,&yy);
		if(yy>1)mat2[xx][yy-1] = false;
		if(yy<m)mat2[xx][yy+1] = false;
		if(xx>1)mat2[xx-1][yy] = false;
		if(xx<n)mat2[xx+1][yy] = false;
	}
	if((n*m-k)&1){
		puts("NO");
		return 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(
	
								

					
	
