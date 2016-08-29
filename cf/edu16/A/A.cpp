#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	char i;
	int j;
	cin >> i >> j;
	if(i=='a' || i=='h'){
		if(j == 1 || j == 8){
			cout << 3 << endl;
		}
		else{
			cout << 5 << endl;
		}
	}
	else{
		if(j == 1 || j == 8){
			cout << 5 << endl;
		}
		else{
			cout << 8 << endl;
		}
	}
	return 0;
}
