#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const double eps = 1e-8;
int n;
char t[10];
void work(){
    scanf("%d %s",&n,t);
    double B,res=0;
    int x;
    if(t[0] == 'b')B = 2;
    if(t[0] == 'n')B = exp(1);
    if(t[0] == 'd')B = 10;
    for(int i = 1; i <= n; i++){
        scanf("%d",&x);
        if(x>0){
            res -= x*0.01*log(x*0.01)/log(B);
        }
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
        work();
    }
    #ifndef ONLINE_JUDGE
    fclose(stdin);
    #endif // ONLINE_JUDGE
    return 0;
}
