/*=============================================================================
	Author: SnowyJune - me@snowyjune.top
	QQ: 896512060
	Last modified: 2016-10-07 16:42
	Filename: D.cpp
=============================================================================*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef unsigned int U;
typedef long long LL;
const int maxn = 1e5+10;
LL ca[maxn];
int main(){
#ifdef SNOWYJUNE
	freopen("input","r",stdin);
#endif
	for(int i = 1; i <= maxn; i++){
		ca[i] = 1LL*i*(i+1)/2;
	}
	LL A;
	scanf("%lld",&A);
	LL* pt = upper_bound(ca+1,ca+maxn+1,A);
	int n = pt-(ca+1), d = A - ca[n];
	if(d==0){
		for(int i = 1; i <= n; i++)putchar(')');
		for(int i = 1; i <= n; i++)putchar('(');
	}
	else{
		for(int i = 1; i <= d; i++)putchar(')');
		putchar('(');
		putchar(')');
		for(int i = 1; i <= n-d; i++)putchar(')');
		for(int i = 1; i <= n; i++)putchar('(');
	}
	puts("");
#ifdef SNOWYJUNE
	fclose(stdin);
#endif
	return 0;
}
	

