#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
typedef long long LL;
const int maxn = 1e5+10;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
using namespace std;
int main(){
#ifndef ONLINE_JUDGE
	freopen("input","r",stdin);
#endif
	LL l1,l2,r1,r2,k;
	cin >> l1 >> r1 >> l2 >> r2 >> k;
	if(l2>r1 || r2<l1){
		cout << 0 << endl;
	}
	else{
		LL l = max(l1,l2);
		LL r = min(r1,r2);
		if(k>=l && k<=r)cout << r-l << endl;
		else cout << r-l+1 << endl;
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
