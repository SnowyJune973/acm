#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define pos(x,y) (id[x][y])
using namespace std;
const int MAXN = 420;
const double eps = 1e-8;
double mat[MAXN][MAXN],vec[MAXN];
int n,m,s1,s2,deg[25];
bool graph[25][25];
int fa[MAXN],id[25][25];
double dp[MAXN][25][25];
int getfather(int x){
	return (fa[x]==x)?x:(fa[x]=getfather(fa[x]));
}
void Merge(int x,int y){
	int fx = getfather(x), fy = getfather(y);
	fa[fx] = fy;
}
void init(){
	memset(mat,0,sizeof(mat));
	memset(vec,0,sizeof(vec));
	memset(graph,0,sizeof(graph));
	memset(deg,0,sizeof(deg));
	memset(dp,0,sizeof(dp));
	for(int i = 0; i < n; i++)fa[i] = i;
	int tot = 0;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			id[j][i] = id[i][j] = tot;
			tot++;
		}
	}	
}
int gauss_tpivot(int n,double a[][MAXN],double b[]){
		int i,j,k,row,col,index[MAXN];
			double maxp,t;
				for (i=0;i<n;i++)
							index[i]=i;
					for (k=0;k<n;k++){
						        for (maxp=0,i=k;i<n;i++)
												for (j=k;j<n;j++)
																	if (fabs(a[i][j])>fabs(maxp))
																							maxp=a[row=i][col=j];
								        if (fabs(maxp)<eps)
														return 0;
												if (col!=k){
																for (i=0;i<n;i++)
																					t=a[i][col],a[i][col]=a[i][k],a[i][k]=t;
																			j=index[col],index[col]=index[k],index[k]=j;
																					}
														if (row!=k){
																		for (j=k;j<n;j++)
																			                t=a[k][j],a[k][j]=a[row][j],a[row][j]=t;
																					t=b[k],b[k]=b[row],b[row]=t;
																							}
																for (j=k+1;j<n;j++){
																				a[k][j]/=maxp;
																							for (i=k+1;i<n;i++)
																												a[i][j]-=a[i][k]*a[k][j];
																									}
																		b[k]/=maxp;
																				for (i=k+1;i<n;i++)
																								b[i]-=b[k]*a[i][k];
																					}
						for (i=n-1;i>=0;i--)
									for (j=i+1;j<n;j++)
													b[i]-=a[i][j]*b[j];
							for (k=0;k<n;k++)
										a[0][index[k]]=b[k];
								for (k=0;k<n;k++)
											b[k]=a[0][k];
									return 1;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	init();
	int pa1,pa2;
	for(int i = 1; i <= m; i++){
		scanf("%d%d",&pa1,&pa2);
		graph[pa1][pa2] = graph[pa2][pa1] = true;
		deg[pa1]++,deg[pa2]++;
		Merge(pa1,pa2);
	}
	scanf("%d%d",&s1,&s2);
	printf("S1 = %d, S2 = %d\n",s1,s2);
	if(s1 == s2){
		puts("0");
		return 0;
	}
	if(getfather(s1) != getfather(s2)){
		puts("never meet");
		return 0;
	}
	int blk = getfather(s1);
	dp[0][s1][s2] = 1;
	for(int t = 0; t <= n*n; t++){
		for(int i = 0; i < n; i++){
			if(getfather(i) != blk)continue;
			for(int j = 0; j < n; j++){
				if(getfather(j) != blk)continue;
				if(dp[t][i][j] < 1e-12)continue;
				if(deg[i]*deg[j]==0)continue;
				for(int k = 0; k < n; k++){
					if(!graph[i][k])continue;
					for(int l = 0; l < n; l++){
						if(!graph[j][l])continue;
						dp[t+1][k][l] += dp[t][i][j] / (deg[i]*deg[j]);
					}
				}
			}
		}
	}
	bool ok = false;
	for(int i = 0; i < n; i++){
		if(dp[n*n+1][i][i] > 1e-12){
			ok = true;
			break;
		}
	}
	if(!ok){
		puts("never meet");
		return 0;
	}
				
	for(int i = 0; i < n; i++){
		if(getfather(i) != blk)continue;
		for(int j = 0; j < n; j++){
			if(getfather(j) != blk)continue;
			if(id[i][j] == id[s1][s2]){
				mat[id[i][j]][id[i][j]] = 1;
				vec[id[i][j]] = 0;
				continue;
			}
			bool vis = false;
			for(int k = 0; k < n; k++){
				if(!graph[i][k])continue;
				for(int l = 0; l < n; l++){
					if(!graph[j][l])continue;
					if(k==l)continue;
					if(id[k][l] == id[i][j])continue;
					printf("K = %d . L = %d , DegK = %d , DegL = %d\n",k,l,deg[k],deg[l]);
					mat[id[i][j]][id[k][l]] += -1.0/deg[k]/deg[l],vis=true;
					printf("Mat %d %d = %.4f\n",id[i][j],id[k][l],mat[id[i][j]][id[k][l]]);
				}
			}
			if(vis){
				mat[id[i][j]][id[i][j]] ++;
				vec[id[i][j]] ++;
			}
			else{
				mat[id[i][j]][id[i][j]] = 0;
				vec[id[i][j]] = 0;
			}
		}
	}
	for(int i = 0; i < n*(n+1)/2; i++){
		printf("Mat %d: ",i);
		for(int j = 0; j < n*(n+1)/2; j++){
			printf("%7.3f",mat[i][j]);
		}
		printf("%12.3f\n",vec[i]);
	}
	int status = gauss_tpivot(n*(n+1)/2,mat,vec);
		for(int i = 0; i < n; i++){
			for(int j = i; j < n; j++){
				printf("E(%d,%d) = %.5f\n",i,j,vec[pos(i,j)]);
			}
		}
	if(status==0){
		puts("never meet");
	}
	else{
		double ans = 0;
		for(int i = 0; i < n; i++){
			ans += vec[pos(i,i)];
			//printf("Vec %d = %.5f\n",i,vec[pos(i,i)]);
		}
		ans /= n;
		printf("%.3f\n",ans);
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}


