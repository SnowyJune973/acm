/*=============================================================================
	Author: SnowyJune - me@snowyjune.top
	QQ: 896512060
	Last modified: 2016-10-07 16:00
	Filename: A.cpp
=============================================================================*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;
set<int> S;
const int maxn = 1e3+10;
int main(){
#ifdef SNOWYJUNE
	freopen("input","r",stdin);
#endif
	int n,a[maxn];
	scanf("%d",&n);
	S.clear();
	for(int i = 1; i <= 9; i++){
		int t = i;
		S.insert(t);
		for(int j = i+1; j <= 9; j++){
			t = t*10 + j;
			S.insert(t);
		}
	}
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
	}
	int res = -1;
	for(int i = 1; i < n; i++){
		for(int j = i+1; j <= n; j++){
			if(res < a[i]*a[j] && S.find(a[i]*a[j]) != S.end()){
				res = a[i]*a[j];
			}
		}
	}
	printf("%d\n",res);
#ifdef SNOWYJUNE
	fclose(stdin);
#endif
	return 0;
}	
