#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 1e5+10;
typedef long long LL;
multiset<LL> S[26];
char s[maxn];
LL c[26],sum[maxn];
void init(){
	for(int i = 0; i < 26; i++)scanf("%lld",&c[i]);
	scanf("%s",s);
	int len = strlen(s);
	for(int i = 0; i < len; i++){
		sum[i]=(i==0)?c[s[i]-'a']:(sum[i-1]+c[s[i]-'a']);
	}
	for(int i = 0; i < 26; i++)S[i].clear();
}
void cal(){
	LL res = 0;
	int len = strlen(s);
	S[s[0]-'a'].insert(sum[0]);
	for(int i = 1; i < len; i++){
		res += S[s[i]-'a'].count(sum[i-1]);
		S[s[i]-'a'].insert(sum[i]);
	}
	printf("%lld\n",res);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input","r",stdin);
#endif
	init();
	cal();
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
