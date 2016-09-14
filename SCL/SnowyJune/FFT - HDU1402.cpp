#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define maxl 140000
#define pi acos(-1.0)
using namespace std;
int two[20] = {1};
struct Complex{
	double u,v;
	Complex(double _u = 0, double _v = 0){
		u = _u, v = _v;
	}
	void init(double _u, double _v){
		u = _u, v = _v;
	}
	Complex operator + (Complex b){
		return Complex(u+b.u,v+b.v);
	}
	Complex operator - (Complex b){
		return Complex(u-b.u,v-b.v);
	}
	Complex operator * (Complex b){
		return Complex(u*b.u-v*b.v,u*b.v+v*b.u);
	}
}F1[maxl],F2[maxl];
void RaderSwap(Complex F[],int len){
	int j = len >> 1;
	for(int i = 1; i <= len-2; i++){
		if(i < j)swap(F[i],F[j]);
		int k = len >> 1;
		while(j >= k){
			j ^= k;
			k >>= 1;
		}
		if(j < k) j ^= k;
	}
}
void FFT(Complex F[],int len,int xs){
	RaderSwap(F,len);
	for(int d = 2; d <= len; d <<= 1){
		Complex Wn(cos(-xs*2*pi/d),sin(-xs*2*pi/d));
		for(int i = 0; i < len; i += d){
			Complex w(1,0);
			for(int j = i; j < i+d/2; j++){
				Complex q = F[j];
				Complex t = w * F[j+d/2];
				F[j] = q + t;
				F[j+d/2] = q - t;
				w = w * Wn;
			}
		}
	}
	if(xs == -1){
		for(int i = 0; i < len; i++)F[i].u /= len;
	}
}
void Conv(Complex a[],Complex b[],int len){
	FFT(a,len,1);
	FFT(b,len,1);
	for(int i = 0; i < len; i++){
		a[i] = a[i] * b[i];
	}
	FFT(a,len,-1);
}
int len;
void Initialize(char num1[],char num2[]){
	int len1 = strlen(num1),len2 = strlen(num2);
	for(int i = 0,j = len1-1;i < j;i++,j--)swap(num1[i],num1[j]);
	for(int i = 0,j = len2-1;i < j;i++,j--)swap(num2[i],num2[j]);
	len = 2;
	while(max(len1,len2)*2 > len)len <<= 1;
	for(int i = 0; i < len; i++){
		if(i < len1){
			F1[i].init(num1[i] - '0',0);
		}
		else{
			F1[i].init(0,0);
		}
		if(i < len2){
			F2[i].init(num2[i] - '0',0);
		}
		else{
			F2[i].init(0,0);
		}
	}
}
char s1[65000],s2[65000];
int ans[140000];
int main(){
	while(scanf("%s",s1) != EOF){
		scanf("%s",s2);
		int len1 = strlen(s1),len2 = strlen(s2);
		if((strlen(s1) == 1 && s1[0] == '0') || (strlen(s2) == 1 && s2[0] == '0')){
			puts("0");
			continue;
		}
		bool isnegative = (s1[0] == '-' && s2[0] != '-') || (s1[0] != '-' && s2[0] == '-');
		if(s1[0] == '-'){
			for(int i = 1; i < len1; i++){
				s1[i-1] = s1[i];
			}
			s1[len1-1] = 0;
		}
		if(s2[0] == '-'){
			for(int i = 1; i < len2; i++){
				s2[i-1] = s2[i];
			}
			s2[len2-1] = 0;
		}
		Initialize(s1,s2);
		Conv(F1,F2,len);
		memset(ans,0,sizeof(ans));
		for(int i = 0; i < len; i++){
			ans[i] = (int)(F1[i].u+0.5);
		}
		for(int i = 0; i < len; i++){
			if(ans[i] >= 10){
				ans[i+1] += ans[i] / 10;
				ans[i] %= 10;
			}
		}
		int high = len;
		if(isnegative)putchar('-');
		while(ans[high] == 0)high--;
		for(int i = high; i >= 0; i--){
			putchar(ans[i]+'0');
		}
		puts("");
	}
	return 0;
}
