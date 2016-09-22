#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
typedef long long LL;
const int maxn = 1e5+10;
LL a[maxn<<2],t;
queue<LL> Q;
int n;
int Div(int a,int b){
	if(a%b==0)return a/b;
	else return a/b+1;
}
bool ok(int k,int n,LL a[]){
//	printf("K = %d\n",k);
	int i=1,cnt;
//	for(int i = 1; i <= n; i++)printf("%lld ",a[i]);
//	puts("");
	LL sum=0,tmp;
	while(!Q.empty())Q.pop();
	while(!(i>n && Q.size()==1)){
		cnt=0;
		tmp=0;
		while(cnt<k){
			if(i>n && Q.empty())break;
			if(Q.empty() || (i<=n && a[i] < Q.front())){
				tmp+=a[i++];
				cnt++;
			}
			else{
				tmp+=Q.front();
				Q.pop();
				cnt++;
			}
			//printf("Tmp = %lld, Cnt = %d, I = %d\n",tmp,cnt,i);
			//getchar();
		}
		Q.push(tmp);
		sum+=tmp;
//		printf("%lld\n",tmp);
	}
//	printf("K-1 = %d: Sum = %lld\n",k-1,sum);
	return sum<=t;
}
int Binary(int l,int r){
//	printf("L = %d , R= %d\n",l,r);
	if(l==r)return l;
	int mid = (l+r)>>1, delta = (mid-1-(n-1)%(mid-1))%(mid-1);
	if(ok(mid,n+delta,a+n-delta))return Binary(l,mid);
	else return Binary(mid+1,r);
}
int main(){
#ifdef SNOWYJUNE
	freopen("input","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%lld",&n,&t);
//		printf("N-1 = %d\n",n-1);
		memset(a,0,sizeof(a));
		for(int i = 1; i <= n; i++)scanf("%lld",&a[i]);
		sort(a+1,a+2*n+1);
//		for(int i = 1; i <= 2*n;i ++)printf("%lld ",a[i]);
//		puts("");
		/*int sq,resk=-1;
		for(sq=1;sq*sq<=n-1;sq++);
		for(;sq*sq>n-1;sq--);
		for(int i = 2; i <= n; i++)ok(i);
		for(int i = 1; i <= sq; i++){
			LL tmp = ok(i+1);
			if(t>=tmp){
				resk=i+1;
				break;
			}
		}
		if(resk==-1){
			for(int i=sq; i >= 1; i--){
				LL tmp = ok(Div(n-1,i)+1);
				if(t>=tmp){
					resk=Div(n-1,i)+1;
					break;
				}
			}
		}
		printf("%d\n",resk);*/
		printf("%d\n",Binary(2,n));
	}
#ifdef SNOWYJUNE
	fclose(stdin);
#endif
	return 0;
}
