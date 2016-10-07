#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,m,mat[35][35];
bool work(){
	for(int i = 1; i < n; i++){
		for(int j = i+1; j <= n; j++){
			if(mat[i][1] == mat[j][1])return true;
			if(mat[i][m] == mat[j][m])return true;
		}
	}
	for(int i = 1; i < m; i++){
		for(int j = i+1; j <= m; j++){
			if(mat[1][i] == mat[1][j])return true;
			if(mat[n][i] == mat[n][j])return true;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(i+1<=n && mat[i][j] == mat[i+1][j])return true;
			if(j+1<=m && mat[i][j] == mat[i][j+1])return true;
		}
	}
	return false;
}
int main(){
#ifdef SNOWYJUNE
	freopen("input","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	for(int t = 1; t <= T; t++){
		scanf("%d%d",&n,&m);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				scanf("%d",&mat[i][j]);
		printf("Case #%d: %s\n",t,work()?"Yes":"No");
	}
#ifdef SNOWYJUNE
	fclose(stdin);
#endif
	return 0;
}
