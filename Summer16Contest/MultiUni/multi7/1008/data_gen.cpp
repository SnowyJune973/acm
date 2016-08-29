#include <cstdio>
#include <cstdlib>
#include <ctime>
int main(){
	FILE* fout = fopen("data","w");
	fprintf(fout,"10\n");
	srand((unsigned int)(time(0)));
	for(int i = 1; i <= 10; i++){
		int a,b,c;
		a = rand()%1000+1;
		b=rand()%9+1;
		c=20-b;
		fprintf(fout,"%d %d %d\n",a,b,c);
		for(int j = 1; j <= c; j++){
			fprintf(fout,"%d ",rand()%95+1);
		}
		fprintf(fout,"\n");
	}
	fclose(fout);
	return 0;
}
