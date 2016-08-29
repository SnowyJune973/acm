#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
bool mat[70][70];
int dp[70][70];
int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};
void init(){
	int ti,tj;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			for(int k = 0; k < 8; k++){
				ti = i+dx[k], tj = j+dy[k];
				if(ti>=0 && ti<8 && tj>=0 && tj<8){
					mat[i*8+j+1][ti*8+tj+1] = true;
					mat[ti*8+tj+1][i*8+j+1] = true;
				}
			}
		}
	}
	ms(dp,0x3f);
	for(int i = 1; i <= 64; i++){
		for(int j = 1; j <= 64; j++){
			if(mat[i][j])dp[i][j] = 1;
			if(i==j)dp[i][j] = 0;
		}
	}
	for(int k = 1; k <= 64; k++){
		for(int i = 1; i <= 64; i++){
			for(int j = 1; j <= 64; j++){
				dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
			}
		}
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	char s1[5],s2[5];
	init();
	while(scanf("%s %s",s1,s2)==2){
	int ps1 = (s1[0]-'a')*8+(s1[1]-'0');
	int ps2 = (s2[0]-'a')*8+(s2[1]-'0');
	printf("To get from %s to %s takes %d knight moves.\n",s1,s2,dp[ps1][ps2]);
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}

