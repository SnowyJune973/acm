#include <cstdio>
#include <ctime>
#include <cstdlib>
int main(){
	puts("1000 1000 100000\n");
	srand((unsigned int)(time(0)));
	for(int i = 1; i <= 1000; i++){
		printf("1 %d %d\n",rand()%1000+1,rand()%1000+1);
	}
	for(int i = 1001; i <= 100000; i++){
		printf("4 1000\n");
	}
	return 0;
}
