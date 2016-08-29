#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;
const int maxn = 2e7+10;
const LL linf = 0x3f3f3f3f3f3f3f3f;
LL Time[maxn];
LL n,x,y;
struct stat{
	LL n,t;
	stat(LL para1 = 0,LL para2 = 0):
		n(para1),t(para2){}
};
bool operator < (stat a,stat b){
	return a.t > b.t;
}
priority_queue<stat> Q;
int main(){
	cin >> n >> x >> y;
	//queue<stat> Q;
	while(!Q.empty())Q.pop();
	Q.push(stat(1,x));
	memset(Time,0x3f,sizeof(Time));
	Time[0] = 0;
	Time[1] = x;
	while(!Q.empty()){
		stat fr = Q.top();
		Q.pop();
		if(fr.n == n)break;
		if(fr.n+1 < 2*n && Time[fr.n+1] > fr.t+x){
			Time[fr.n+1] = fr.t + x;
			Q.push(stat(fr.n+1,fr.t+x));
		}
		if(fr.n-1 >= 1 && Time[fr.n-1] > fr.t+x){
			Time[fr.n-1] = fr.t + x;
			Q.push(stat(fr.n-1,fr.t+x));
		}
		if(fr.n*2 < 2*n && Time[fr.n*2] > fr.t+y){
			Time[fr.n*2] = fr.t + y;
			Q.push(stat(fr.n*2,fr.t+y));
		}
	}
	/*for(int i = 1; i < n; i++){
		dp[i+1] = min(dp[i+1], dp[i]+x);
		dp[i*2] = min(dp[i*2], dp[i]+y);
	}*/
	LL res = Time[n];
	cout << res << endl;
	return 0;
}

