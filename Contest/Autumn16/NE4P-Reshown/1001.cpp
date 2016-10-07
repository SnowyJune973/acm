#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
int main(){
#ifdef SNOWYJUNE
	freopen("input","r",stdin);
#endif
	int T;
	LL n;
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> n;
		cout << "Case #" << i << ": " << (n-1)*(n+2)/2 << endl;
	}
#ifdef SNOWYJUNE
	fclose(stdin);
#endif
	return 0;
}
