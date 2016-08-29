#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>
using namespace std;
typedef long long LL;
const int maxl = 1e6+10;
LL Cn2[maxl];
map<LL,int> mpCn2;
void init(){
	mpCn2.clear();
	for(int i = 1; i <= 100000; i++){
		Cn2[i] = 1LL*i*(i-1)/2;
		mpCn2[Cn2[i]] = i;
	}
}
int main(){
	LL a00,a01,a10,a11;
	cin >> a00 >> a01 >> a10 >> a11;
	init();
	if(a00==0&&a01==0&&a10==0&&a11==0){
		cout << '1' << endl;
		return 0;
	}
	if(mpCn2.find(a00)==mpCn2.end() || mpCn2.find(a11)==mpCn2.end()){
		cout << "Impossible" << endl;
		return 0;
	}
			if(a00==0&&a01==0&&a10==0&&a11!=0){
				for(int i = 1; i <= mpCn2[a11]; i++)cout << '1';
				cout << endl;
				return 0;
			}
			if(a00!=0&&a01==0&&a10==0&&a11==0){
				for(int i = 1; i <= mpCn2[a00]; i++)cout << '0';
				cout << endl;
				return 0;
			}
		//0011
		//0101
		//1001
		int cnt0 = mpCn2[a00], cnt1 = mpCn2[a11];
		//cout << "cnt0 = " << cnt0 << ",cnt1 = " << cnt1 << endl;
		if(Cn2[cnt0+cnt1] != a00+a01+a10+a11){
			cout << "Impossible" << endl;
		}
		else{
				
			string s = "";
			for(int i = 1; i <= a10/cnt0; i++)s=s+"1";
			for(int i = 1; i <= cnt0; i++)s=s+"0";
			for(int i = 1; i <= cnt1-a10/cnt0; i++)s=s+"1";
			swap(s[cnt0+a10/cnt0],s[cnt0+a10/cnt0-a10%cnt0]);
			cout << s << endl;
		}
	return 0;
}
