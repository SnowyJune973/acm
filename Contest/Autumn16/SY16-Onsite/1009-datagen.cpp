#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	freopen("input","w",stdout);
	int T;
	cin >> T;
	cout << T << endl;
	while(T--){
		int n = rand()%100+1;
		cout << n << endl;
		for(int i = 1; i <= n; i++)cout << rand()%20+2 << ' ';
		cout << endl;
		for(int i = 1; i <= n; i++)cout << rand()%500000000 + rand()%700000000 << ' ';
		cout << endl;
	}
	fclose(stdout);
	return 0;
}
	
