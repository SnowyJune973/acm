#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;
const int maxn = 1010;
char s[maxn],res[maxn],dif[maxn][3];
bool dp[maxn][maxn];
int Next[maxn][3][maxn];
int n,m;
void init(){
	memset(dif,0,sizeof(dif));
	for(int i = 0; i < n/2; i++){
		if(s[i]==s[i+n/2]){
			dif[i][0] = s[i];
			for(int j = 0; j < 26; j++){
				if(j+'a' != s[i]){
					dif[i][2] = j+'a';
					break;
				}
			}
		}
		else{
			dif[i][1] = min(s[i],s[i+n/2]);
			for(int j = 0; j < 26; j++){
				if(j+'a' != s[i] && j+'a' != s[i+n/2]){
					dif[i][2] = j+'a';
					break;
				}
			}
		}
//		printf("DIF %d: %d %d %d\n",i,dif[i][0],dif[i][1],dif[i][2]);
	}
}	
void calc2(){
	memset(dp,false,sizeof(dp));
	dp[n/2][0] = true;
	for(int i = n/2-1; i >= 0; i--){
		for(int j = 0; j <= 2*(n/2-i); j++){
			if(dif[i][0])dp[i][j] = dp[i][j] || dp[i+1][j];
			if(dif[i][1] && j >= 1)dp[i][j] = dp[i][j] || dp[i+1][j-1];
			if(dif[i][2] && j >= 2)dp[i][j] = dp[i][j] || dp[i+1][j-2];
		}
	}
}
			
/*void calc(){
	memset(dp,false,sizeof(dp));
	memset(Next,0x3f,sizeof(Next));
	for(int i = 0; i < 3; i++)dp[n/2-1][i][i] = true;
	for(int i = n/2-2; i >= 0; i--){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < 3; k++){
				for(int l = 0; l < 3; l++){
					if(dp[i+1][l][j-k]){
						dp[i][k][j] = true;
						if(dif[i+1][l] < Next[i][k][j])Next[i][k][j] = l;
					}
				}
			}
		}
	}
	int mi = 127;
	for(int i = 0; i < 2; i++){
		if(dp[0][i][m] && mi > dif[0][i])mi = i;
	}
	if(mi == 127){
		puts("Impossible");
		return;
	}
	int kk = mi, jj = m;
	printf("0 = %d\n",mi);
	sprintf(res,"%c",dif[0][mi]);
	for(int i = 0; i < n/2-1; i++){
		printf("%d = %d\n",i+1,Next[i][kk][jj]);
		int nx = Next[i][kk][jj];
		sprintf(res,"%c",dif[i+1][nx]);
		jj -= kk, kk = nx;
	}
	printf("%s%s\n",res,res);
}*/
bool dfs(int p,string prev,int rem){
//	printf("P = %d , Prev = %s , Rem = %d\n",p,prev.c_str(),rem);
	if(rem<0 || rem>n-p*2)return false;
	if(!dp[p][rem])return false;
	if(p==n/2&&rem==0){
		printf("%s%s\n",prev.c_str(),prev.c_str());
		return true;
	}
	int dig[3]={0,1,2};
	char ch[3];
	for(int i = 0; i <= 1; i++){
		for(int j = i+1; j <= 2; j++){
			if(dif[p][i] > dif[p][j]){
				swap(dig[i],dig[j]);
			}
		}
	}
	for(int i = 0; i < 3; i++)ch[i]=dif[p][dig[i]];
	for(int i = 0; i < 3; i++){
		if(dif[p][dig[i]]==0)continue;
		if(dfs(p+1,prev+ch[i],rem-dig[i]))return true;
	}
	return false;
}
void work(){
	scanf("%d%d\n",&n,&m);
	scanf("%s",s);
	init();
	calc2();
	if(!dp[0][m]){
		puts("Impossible");
	}
	else if(!dfs(0,"",m))puts("Impossible");
}
int main(){
#ifdef SNOWYJUNE
	freopen("input","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T--)work();
#ifdef SNOWYJUNE
	fclose(stdin);
#endif
	return 0;
}	

