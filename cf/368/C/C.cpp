#include <iostream>
#include <algorithm>
using namespace std;
unsigned long long a,b,c,n,k;
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	cin >> n;
	if(n%2 == 1){
		if(n == 1){
			cout << -1 << endl;
		}
		else{
			k = (n-1)/2;
			cout << 2*k*k+2*k << ' ' << 2*k*k+2*k+1 << endl;
		}
	}
	else{
		if(n%4==0){
			cout << n/4*3 << ' ' << n/4*5 << endl;
		}
		else{
			if(n == 2){
				cout << -1 << endl;
			}
			else{
				k = (n/2-1)/2;
				cout << 4*k*k+4*k << ' ' << 4*k*k+4*k+2 << endl;
			}
		}
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
