#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#define ms(x,y) memset(x,y,sizeof(x))
#define lowbit(x) (x&(-x))
const int maxn = 1e5+10;
typedef long long LL;
using namespace std;
int n,n1,n2,m,c[maxn<<2];
map<int,int> M;
using namespace std;

struct Segment{
	int x1,x2,y1,y2;
	Segment(int para1 = 0,int para2 = 0,int para3 = 0,int para4 = 0):
		x1(para1),x2(para2),y1(para3),y2(para4){}
}HSeg[maxn],SSeg[maxn];

struct Element{
	int x,segid,segtype;
	Element(int para1 = 0,int para2 = 0,int para3 = 0):
		x(para1),segid(para2),segtype(para3){}
}A[maxn<<2];
bool operator < (Element a,Element b){
	return (a.x==b.x)?(a.segtype>b.segtype):(a.x<b.x);
}

void Update(int p,int x,int n){
	while(p <= n){
		c[p] += x;
		p += lowbit(p);
	}
}
int Sum(int p){
	int res = 0;
	while(p){
		res += c[p];
		p -= lowbit(p);
	}
	return res;
}

void work(){
	int x1,x2,y1,y2;
	LL res = 0;
	ms(c,0);
	M.clear();
	scanf("%d",&n);
	n1 = n2 = m = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1 == x2){
			if(y1 > y2){
				swap(x1,x2);
				swap(y1,y2);
			}
			M[y1] = 0;
			M[y2] = 0;
			SSeg[++n2] = Segment(x1,x2,y1,y2);
			A[++m] = Element(x1,n2,0);
		}
		else{
			if(x1 > x2){
				swap(x1,x2);
				swap(y1,y2);
			}
			M[y1] = 0;
			HSeg[++n1] = Segment(x1,x2,y1,y2);
			A[++m] = Element(x1,n1,1);
			A[++m] = Element(x2,n1,-1);
		}
	}
	int j,maxSize = M.size() + 10;
//	printf("MaxSize = %d\n",maxSize);
	map<int,int>::iterator it;
	for(it=M.begin(),j=1;it!=M.end();it++,j++){
		it->second = j;
	}
	for(int i = 1; i <= n1; i++){
		HSeg[i].y1 = M[HSeg[i].y1];
		HSeg[i].y2 = HSeg[i].y1;
	}
	for(int i = 1; i <= n2; i++){
		SSeg[i].y1 = M[SSeg[i].y1];
		SSeg[i].y2 = M[SSeg[i].y2];
	}
/*	printf("Heng Segment: \n");
	for(int i = 1; i <= n1; i++){
		printf("Number %d: x1 = %d , x2 = %d , y1 = %d, y2 = %d\n",i,HSeg[i].x1,HSeg[i].x2,HSeg[i].y1,HSeg[i].y2);
	}
	puts("");
	puts("Shu Segment:");
	for(int i = 1; i <= n2; i++){
		printf("Number %d: x1 = %d , x2 = %d , y1 = %d , y2 = %d\n",i,SSeg[i].x1,SSeg[i].x2,SSeg[i].y1,SSeg[i].y2);
	}*/
	sort(A+1,A+m+1);
	/*for(int i = 1; i <= m; i++){
		printf("A[%d]: X = %d , Segid = %d , Segtype = %d\n",i,A[i].x,A[i].segid,A[i].segtype);
	}*/
	for(int i = 1; i <= m; i++){
		if(A[i].segtype != 0){
			Update(HSeg[A[i].segid].y1,A[i].segtype,maxSize);
		}
		else{
			res += 1LL * (Sum(SSeg[A[i].segid].y2) - Sum(SSeg[A[i].segid].y1 - 1));
		}
	}
	printf("%lld\n",res);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T--){
		work();
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
