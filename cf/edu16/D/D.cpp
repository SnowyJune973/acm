#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;
LL ex_gcd(LL a,LL b,LL &x,LL &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	LL r = ex_gcd(b,a%b,x,y);
	LL t = x;
	x = y;
	y = t-a/b*y;
	return r;
}
LL mod_equations(LL b1,LL b2,LL m1,LL m2){
	LL y1,z1,x;
	if(m1 > m2){
		swap(b1,b2);
		swap(m1,m2);
	}
//	cout << b1 << ' ' << b2 << ' ' << m1 << ' ' << m2 << endl;
	LL d = ex_gcd(b1,b2,y1,z1), c = m2 - m1;
	if(c % d != 0)return -1;
//	cout << "y1 = " << y1 << " z1 = " << z1 << endl;
	y1 = (y1 % (b2/d) + (b2/d)) % (b2/d);
	LL lcm = b1/d*b2;
	x = ((c/d*y1) % lcm * b1 + m1) % lcm;
	return x;
}
LL Div(LL a,LL b){
	if(a%b==0)return a/b;
	else{
		if(a >= 0)return a/b;
		else return a/b-1;
	}
}
int main(){
	LL a1,b1,a2,b2,L,R,x,tmp1,tmp2;
	LL mini,maxi,d,lcm;
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	cin >> a1 >> b1 >> a2 >> b2 >> L >> R;
	d = ex_gcd(a1,a2,tmp1,tmp2);
	lcm = a1/d*a2;
	L = max(max(b1,b2),L);
	x = mod_equations(a1,a2,(b1%a1+a1)%a1,(b2%a2+a2)%a2);
//	cout << "L = " << L << ", R = " << R << endl;
	if(x == -1){
		cout << 0 << endl;
	}
	else{
//		cout << "X = " << x << endl;
		cout << max((Div(R-x,lcm) - Div(L-1-x,lcm)),0LL) << endl;
	}
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
