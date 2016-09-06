#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn = 2e5+10;
int ki[maxn],dp[maxn],n,m;
void init(){
    memset(dp,0,sizeof(dp));
}
int dfs(int x){
    if(x+ki[x]>=n)return dp[x] = 1;
    else return dp[x] = 1 + dfs(x+ki[x]);
}
void work(){
    int pa1,pa2,pa3;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++)scanf("%d",&ki[i]);
    for(int i = 0; i < n; i++){
        if(!dp[i])dp[i] = dfs(i);
    }
    for(int i = 1; i <= m; i++){
        scanf("%d%d",&pa1,&pa2);
        if(pa1==1){
            printf("%d\n",dp[pa1]);
        }
        else{
            scanf("%d",&pa3);
            ki[pa2] = pa3;
            dp[]
        }
    }
}
