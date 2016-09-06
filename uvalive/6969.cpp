#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int mi=105,ma=-1;
int n,m;
void work(){
    scanf("%d%d",&n,&m);
    int x,s1=0,s2=0;
    mi=105,ma=-1;
    for(int i = 1; i <= n-1; i++){scanf("%d",&x);s1+=x;}
    for(int i = 1; i <= m; i++){scanf("%d",&x);s2+=x;}
    for(int i = 0; i <= 100; i++){
        if(n*s1>(n-1)*(s1+i) && m*(s2+i)>s2*(m+1)){
            mi=min(mi,i);
            ma=max(ma,i);
        }
    }
    printf("%d %d\n",mi,ma);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int T;
    scanf("%d",&T);
    while(T--){
        work();
    }
    #ifndef ONLINE_JUDGE
    fclose(stdin);
    #endif // ONLINE_JUDGE
    return 0;
}
