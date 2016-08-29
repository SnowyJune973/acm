#include <cstdio>
#include <cmath>
#include <cstdlib>
const double eps = 1e-9;
double calc(double x){
	double x2 = x*x;
	return 8*x2*x2+7*x2*x+2*x2+3*x+6;
}
void work(){
	double Y;
	scanf("%lf",&Y);
	if(Y < 6 || Y > 807020306){
		puts("No solution!");
		return;
	}
	double l = 0,r = 100;
	while(r-l > eps){
		double mid = (l+r)/2.0;
		//printf("L = %.5lf, R = %.5lf , Mid = %.5lf\n",l,r,mid);
		//printf("Calcmid = %.12lf\n",calc(mid));
		if(calc(mid)<Y-eps)l=mid;
		else r=mid;
		//printf("L = %.5lf, R = %.5lf\n",l,r);
	}
	printf("%.4lf\n",l);
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

		

