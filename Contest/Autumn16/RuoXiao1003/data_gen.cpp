#include <cstdio>
#include <cstdlib>
#include <ctime>
int fa[100010];
int getfather(int x){
	return (fa[x]==x)?x:(fa[x]=getfather(fa[x]));
}
int Union(int x,int y){
	fa[getfather(x)] = getfather(y);
}
int main(){
	freopen("input","w",stdout);
	srand((unsigned int)(time(0)));
	puts("100000");
/*&	for(int i = 1; i <= 100000; i++)fa[i] = i;
	for(int i = 1; i <= 99999; i++){
		int x=1,y=1;
		while(getfather(x)==getfather(y)){
			x=rand()%100000+1,y=rand()%100000+1;
		}
		Union(x,y);
		printf("%d %d\n",x,y);
	}*/
	for(int i = 1; i <= 99999; i++)printf("%d %d\n",i,i+1);
	return 0;
}

