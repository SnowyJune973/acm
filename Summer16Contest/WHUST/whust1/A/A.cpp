/*************************************************************************
    > File Name: A.cpp
    > Author: SnowyJune
    > Mail: SnowyJune 
    > Created Time: 2016年08月07日 星期日 15时02分13秒
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
#define ms(x,y) memset(x,y,sizeof(x))
#define lson(x) (x<<1)
#define rson(x) ((x<<1)|1)
using namespace std;
#define lowbit(x) (x&(-x))
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x3f3f3f3f;
const LL linf = 0x3f3f3f3f3f3f3f3fLL;
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	int f;
	cin >> f;
	cout << ((f >= 7)?"YES":"NO") << endl;
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
