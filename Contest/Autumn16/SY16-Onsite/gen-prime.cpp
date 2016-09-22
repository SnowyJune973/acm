#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
	freopen("prime","w",stdout);
	bool isprime[10050];
	memset(isprime,1,sizeof(isprime));
	isprime[1] = false;
	int primecnt=0;
	for(int i = 2; i <= 10030; i++){
		if(!isprime[i])continue;
		for(int j = 2; i*j<=10030; j++){
			isprime[i*j]=false;
		}
	}
	for(int i = 2; i <= 10030; i++){
		if(isprime[i])primecnt++;
	}
	cout << primecnt << endl;
	for(int i = 2; i <= 10030; i++){
		if(isprime[i])cout << i <<',';
		if(i%200==0)cout << endl;
	}
	fclose(stdout);
	return 0;
}
