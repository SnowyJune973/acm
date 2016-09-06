#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#define lowbit(x) (x&(-x))
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
}dp[maxn];
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
	if(P <= 0){
		puts("1/1");
		return;
	}
	for(int i = 0; i < two[N+M]-1; i++)
		for(int j = 0; j <= 9; j++)
			dp[i] = frac(0,1);
	dp[two[M+N]-1] = frac(1,1);
	frac res(0,1);
	for(int i = two[M+N]-1; i >= 0; i--){
	//	printf("I = %d\n",i);
/*		if(i == two[M]-1){
			for(int k = 0; k < M; k++){
				dp[i^two[k]][0] = dp[i^two[k]][0] + frac(1,N+M) * dp[two[M]-1][0];
			}
			dp[i][1] = dp[i][1] + frac(N,N+M) * dp[i][0];
			continue;
		}*/
		if(dp[i].q == 0)continue;
		Acard = Bcard = 0;
		tmp = i;
		t = -1;
		LL tot_hurt = 0;
		while(t < M+N-1){
			t++;
			if(tmp&1){
				if(t < N){
					a[++Acard] = t;
				}
				else{
					b[++Bcard] = t;
				}
			}
			else{
				if(t >= N)tot_hurt += hurt[t-N+1];
		//		printf("Tot_hurt = %lld\n",tot_hurt);
			}
			tmp>>=1;
		}
//		for(int j = 0; j <= min(N,9); j++){
		//	printf("Stack = %d, Pull = %d , Potential = ",i,j);
		//	dp[i][j].print();	
//		}
	//	printf("DP[%d] = ",i);
	//	dp[i].print();
		if(tot_hurt >= P && N-Acard+1 == M-Bcard)res = res + dp[i];
		if(tot_hurt >= P && Acard == 0 && Bcard == 0)res = res + dp[i];
		if(M-Bcard >= N-Acard+1)continue;
			//Take A card
			if(Acard){
				dp[i^lowbit(i)] = frac(Acard,Acard+Bcard) * dp[i] + dp[i^lowbit(i)];
			}
			//if(i == 0){
			//	dp[i][0] = dp[i][0] + dp[i][j];
			//	break;
			//}

			//Only one B card
			
			//Take B card
			for(int k = 1; k <= Bcard; k++){
				int nxt = i^two[b[k]];
				dp[nxt] = frac(1,Acard+Bcard) * dp[i] + dp[nxt];
			}
		//for(int j = 0; j <= 3; j++){
		//	printf("Stack = %d, Pull = %d, Potential = %lld/%lld\n",i,j,dp[i][j].q,dp[i][j].p);
		//}
	}	
	/*double t3 = clock();
	for(int i = 0; i < two[M]; i++){
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
	counter += (t4-t3)/CLOCKS_PER_SEC;*/
	res.print();
}
int main(int argc,char* argv[]){
#ifndef ONLINE_JUDGE
	freopen("data/1008.in","r",stdin);
	freopen("user","w",stdout);
#endif
	int T;
	//double t1 = clock();
	init();
	scanf("%d",&T);
	while(T--){
		work();
	}
	//double t2 = clock();
	//printf("Counter time = %.3lf Sec\n",counter);
	//printf("Total time = %.3lf Sec\n",(t2-t1)/CLOCKS_PER_SEC);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
