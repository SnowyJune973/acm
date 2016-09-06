#include <cstdio>
int main(){
	freopen("data","w",stdout);
	printf("5\n");
	for(int j = 1; j <= 5; j++){
		puts("100000 99999");
		for(int i = 1; i <= 50000; i++)printf("2 3 ");
		puts("");
		for(int i = 1; i <= 33333; i++){
			puts("1 1 100000 6\n2 1 100000\n3 1 100000");
		}
	}
	return 0;
}
