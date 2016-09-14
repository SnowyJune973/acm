#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <string>
typedef long long LL;
const int maxn = 1e5+10;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
using namespace std;
map<string,int> M;
int main(){
#ifndef ONLINE_JUDGE
	freopen("input","r",stdin);
#endif
	int n;
	char t[10],tt[30];
	string s;
	M.clear();
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%s %s",t,tt);
		s = "";
		s.append(tt);
		int llen = s.size();
		for(int j = 1; j <= 20-llen; j++)s="0"+s;
		for(int j = 0; j < 20; j++)s[j]=s[j]%2+48;
		/**/
		if(t[0]=='+'){
			if(M.find(s)==M.end())M[s]=1;
			else M[s]++;
		}
		if(t[0]=='-'){
			if(M[s]==1)M.erase(s);
			else M[s]--;
		}
		if(t[0]=='?'){
			if(M.find(s)==M.end())puts("0");
			else printf("%d\n",M[s]);
		}
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
