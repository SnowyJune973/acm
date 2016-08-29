/*************************************************************************
    > File Name: L.cpp
    > Author: SnowyJune
    > Mail: SnowyJune 
    > Created Time: 2016年08月07日 星期日 15时06分01秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <string>
#define ms(x,y) memset(x,y,sizeof(x))
#define lson(x) (x<<1)
#define rson(x) ((x<<1)|1)
using namespace std;
#define lowbit(x) (x&(-x))
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x3f3f3f3f;
const LL linf = 0x3f3f3f3f3f3f3f3fLL;
map<string,int> M;
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	M.clear();
	M["Alice"] = M["Ariel"] = M["Aurora"] = M["Phil"] = M["Peter"] = M["Olaf"] = M["Phoebus"] = M["Ralph"] = M["Robin"] = 1;
	M["Bambi"] = M["Belle"] = M["Bolt"] = M["Mulan"] = M["Mowgli"] = M["Mickey"] = M["Silver"] = M["Simba"] = M["Stitch"] = 2;
	M["Dumbo"] = M["Genie"] = M["Jiminy"] = M["Kuzko"] = M["Kida"] = M["Kenai"] = M["Tarzan"] = M["Tiana"] = M["Winnie"] = 3;
	string s;
	int pos,pres = 1,res = 0,n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> s;
		pos = M[s];
		res += abs(pos-pres);
		pres = pos;
	}
	cout << res << endl;
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
