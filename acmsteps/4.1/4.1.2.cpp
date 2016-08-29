#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-7;
double calc(double x,double y){
	double x2 = x*x,x6 = x2*x2*x2;
	return 6*x6*x+8*x6+7*x2*x+5*x2-y*x;
}
void work(){
	double Y,l=0,r=100;
	scanf("%lf",&Y);
	while(r-l > eps){
		double mid = (l+r)/2.0, midmid = (mid+r)/2.0;
		double Fmid = calc(mid,Y), Fmidmid = calc(midmid,Y);
		if(Fmid > Fmidmid)l = mid;
		else r = midmid;
	}
	printf("%.4lf\n",calc(l,Y));
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

