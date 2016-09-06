#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps = 1e-10;
double dp[2505][52][52];
int n,m;
void init(){
    memset(dp,0,sizeof(dp));
}
void work(){
    scanf("%d%d",&n,&m);
    dp[0][0][0] = 1;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            for(int k = 1; k <= n*m; k++){
                if(i!=n || j!=m)dp[k][i][j] = (i*j-k+1)*dp[k-1][i][j];
                if(i>0)dp[k][i][j] += (j)*(n-i+1)*dp[k-1][i-1][j];
                if(j>0)dp[k][i][j] += (i)*(m-j+1)*dp[k-1][i][j-1];
                if(i>0 && j>0)dp[k][i][j] += (n-i+1)*(m-j+1)*dp[k-1][i-1][j-1];
                dp[k][i][j] /= (n*m-k+1);
                //printf("DP %d %d %d = %.8f\n",k,i,j,dp[k][i][j]);
            }
        }
    }
    double res = 0;
    for(int i = 1; i <= n*m; i++){
        res += i*dp[i][n][m];
        if(abs(dp[i][n][m]-1) < eps)break;
    }
    printf("%.12f\n",res);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int T;
    scanf("%d",&T);
    while(T--){
        init();
        work();
    }
    #ifndef ONLINE_JUDGE
    fclose(stdin);
    #endif // ONLINE_JUDGE
    return 0;
}
