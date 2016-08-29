#include <cstdio>
#include <iostream>
using namespace std;
int n;
int a[55][55];
int main(){
	scanf("%d",&n);
	int i = 0,j = n/2,k = 1;
	while(k <= n*n){
		a[i][j] = k;
		if(k%n == 0){
			i = (i+1) % n;
		}
		else{
			i = (i+n-1) % n;
			j = (j+1) % n;
		}
		k++;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(j > 0)putchar(' ');
			printf("%d",a[i][j]);
		}
		puts("");
	}
	return 0;
}
