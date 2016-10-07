/*=============================================================================
	Author: SnowyJune - me@snowyjune.top
	QQ: 896512060
	Last modified: 2016-10-07 16:15
	Filename: B.cpp
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;
const int inf = 0x3f3f3f3f;
int n,m,hx,hy;
char mat[205][205];
int dist[205][205];
struct rec{
	int x,y;
	rec(int pa1=0, int pa2=0):
		x(pa1),y(pa2){}
};

bool bfs(){
	int pt = inf, st = inf;
	queue<rec> Q;
	while(!Q.empty())Q.pop();
	memset(dist,0x3f,sizeof(dist));
	dist[hx][hy] = 0;
	Q.push(rec(hx,hy));
	int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
	while(!Q.empty()){
		int frx = Q.front().x, fry = Q.front().y;
		Q.pop();
		for(int i = 0; i < 4; i++){
//			printf("Direction = (%d,%d)\n",dx[i],dy[i]);
			if(frx+dx[i]<0||frx+dx[i]>=n||fry+dy[i]<0||fry+dy[i]>=m)continue;
			if(dist[frx+dx[i]][fry+dy[i]]<inf){
				continue;
			}
			if(mat[frx+dx[i]][fry+dy[i]]=='#')continue;
			dist[frx+dx[i]][fry+dy[i]] = dist[frx][fry] + 1;
			Q.push(rec(frx+dx[i],fry+dy[i]));
//			printf("Push X = %d , Y = %d , Dist = %d\n",frx+dx[i],fry+dy[i],dist[frx+dx[i]][fry+dy[i]]);
			if(mat[frx+dx[i]][fry+dy[i]]=='@')pt=dist[frx+dx[i]][fry+dy[i]];
			if(mat[frx+dx[i]][fry+dy[i]]=='$'){
				st=dist[frx+dx[i]][fry+dy[i]];
				break;
			}
		}
		if(st<inf)break;
	}
	return pt<st;
}	
int main(){
#ifdef SNOWYJUNE
	freopen("input","r",stdin);
#endif
	while(scanf("%d%d",&n,&m) == 2){
		for(int i = 0; i < n; i++){
			scanf("%s",mat[i]);
		}
		hx = hy = -1;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				if(mat[i][j] == '%'){
					hx = i, hy = j;
					break;
				}
			if(hx != -1)break;
		}
		puts(bfs()?"Yes":"No");
	}
#ifdef SNOWYJUNE
	fclose(stdin);
#endif
	return 0;
}
		
