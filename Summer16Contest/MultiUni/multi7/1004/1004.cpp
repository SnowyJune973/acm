#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <ctime>
#define ms(x,y) memset(x,y,sizeof(x))
#define lowbit(x) (x&(-x))
using namespace std;
const int maxx = 1e6+10;
const int inf = 0x3f3f3f3f;
int two[22];
int f[maxx],C[maxx][22],D[maxx];
bool inset[maxx];
void init(){
	f[1] = 0;
	for(int i = 2; i <= 1000000; i++)f[i] = 1;
	for(int i = 2; i <= 1000000; i++){
		if(f[i] > 1)continue;
		for(int j = 2; j * i <= 1000000; j++){
			f[i*j] = f[i] + f[j];
		}
	}
}
void init0(){
	ms(C,0);
	ms(D,0);
	ms(inset,0);
}
void Insert(int x){
	if(inset[x])return;
	inset[x] = true;
	for(int i = 1; i * i <= x; i++){
		if(x%i != 0)continue;
		C[i][f[x/i]] ++;		
		if(i*i != x)C[x/i][f[i]] ++;
	}
}	
void Erase(int x){
	if(!inset[x])return;
	inset[x] = false;
	for(int i = 1; i * i <= x; i++){
		if(x%i != 0)continue;
		C[i][f[x/i]] --;
		if(i*i != x)C[x/i][f[i]] --;
	}
}
void Query(int x){
	int res = inf;
	for(int i = 1; i * i <= x; i++){
		if(x%i != 0)continue;
		for(int j = 0; j <= 20; j++){
			if(C[i][j]){
				res = min(res, f[x/i]+j);
				break;
			}
		}
		if(i * i == x)continue;
		for(int j = 0; j <= 20; j++){
			if(C[x/i][j]){
				res = min(res, f[i]+j);
			}
		}
	}
	if(res != inf)printf("%d\n",res);
	else printf("-1\n");
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("data/1004.in","r",stdin);
	freopen("user","w",stdout);
#endif
	int N,tx,cs;
	char op[3];
	init();
	cs = 0;
	while(1){
		scanf("%d",&N);
		if(!N)break;
		init0();
		printf("Case #%d:\n",(++cs));
		for(int i = 1; i <= N; i++){
			scanf("%s %d\n",op,&tx);
			if(op[0] == 'I'){
				Insert(tx);
			}
			if(op[0] == 'D'){
				Erase(tx);
			}
			if(op[0] == 'Q'){
				Query(tx);
			}
		}
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
