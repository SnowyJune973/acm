#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;
typedef long long LL;
const int maxn = (1 << 20) + 10;
LL two[22],hurt[22];
int P,N,M;
double counter=0;
void init(){
	two[0] = 1;
	for(int i = 1; i <= 20; i++)two[i] = two[i-1] * 2;
}
LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}
struct frac{
	LL q,p;
	frac(LL para1 = 0,LL para2 = 1){
		q = para1, p = para2;
	}
	void reduce(){
		LL G = gcd(q,p);
		q /= G, p /= G;
	}
	void print(){
		printf("%lld/%lld\n",q,p);
	}
}dp[maxn][12];
frac operator + (const frac &a,const frac &b){
	frac neu(a.q*b.p+b.q*a.p,a.p*b.p);
	neu.reduce();
	return neu;
}
frac operator * (const frac &a,const frac &b){
	frac neu(a.q*b.q,a.p*b.p);
	neu.reduce();
	return neu;
}
bool operator <= (const frac &a,const frac &b){
	return a.q*b.p <= b.q*a.p;
}
void work(){
	char a[22],b[22];
	int t,tmp,Acard,Bcard;
	int max_j = -1;
	scanf("%d%d%d",&P,&N,&M);
	for(int i = 1; i <= M; i++)scanf("%lld",&hurt[i]);
	for(int i = 0; i < two[N+M]-1; i++)
		for(int j = 0; j <= 10; j++)
			dp[i][j] = frac(0,1);
	dp[two[N+M]-1][1] = frac(1,1);
	for(int i = two[N+M]-1; i >= 0; i--){
		//printf("I = %d\n",i);
		Acard = Bcard = 0;
		tmp = i;
		t = -1;
		while(t < N+M){
			t++;
			if(tmp&1){
				if(t < N){
					a[++Acard] = t;
				}
				else{
					b[++Bcard] = t;
				}
			}
			tmp>>=1;
		}	
		frac mul(1,Acard+Bcard);
		for(int j = 1; j <= min(10,Acard+Bcard); j++){
			if(dp[i][j].q == 0)continue;
			if(i == 0){
				dp[i][0] = dp[i][0] + dp[i][j];
				break;
			}
			for(int k = 1; k <= Acard; k++){
				int nxt = i^two[a[k]];
				dp[nxt][j+min(Acard+Bcard-1,2)-1] = dp[nxt][j+min(Acard+Bcard-1,2)-1] + mul * dp[i][j];
			}
			for(int k = 1; k <= Bcard; k++){
				int nxt = i^two[b[k]];
				dp[nxt][j-1] = dp[nxt][j-1] + mul * dp[i][j];
			}
		}
		//for(int j = 0; j <= 3; j++){
		//	printf("Stack = %d, Pull = %d, Potential = %lld/%lld\n",i,j,dp[i][j].q,dp[i][j].p);
		//}
	}	
	frac res(0,1);
	double t3 = clock();
	for(int i = 0; i < two[N+M]; i++){
		LL tot_hurt = 0;
		int tmp = i>>N;
		for(int j = 1; j <= M; j++){
			if(tmp%2==0)tot_hurt+=hurt[j];
			tmp>>=1;
		}
		if(tot_hurt>=P){
			res = res + dp[i][0];
		}
	}
	double t4 = clock();
	counter += (t4-t3)/CLOCKS_PER_SEC;
	res.print();
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	int T;
	double t1 = clock();
	init();
	scanf("%d",&T);
	while(T--){
		work();
	}
	double t2 = clock();
	printf("Counter time = %.3lf Sec\n",counter);
	printf("Total time = %.3lf Sec\n",(t2-t1)/CLOCKS_PER_SEC);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
