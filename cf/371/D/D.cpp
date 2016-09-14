#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
typedef long long LL;
const int maxn = 1e5+10;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
using namespace std;

struct acht{
	int a,b,c,d,e,f,g,h;
	acht(int pa1=0,int pa2=0,int pa3=0,int pa4=0,int pa5=0,int pa6=0,int pa7=0,int pa8=0):
		a(pa1),b(pa2),c(pa3),d(pa4),e(pa5),f(pa6),g(pa7),h(pa8){}
	int square(){
		if(c<a || d<b || g<e || h<f)return inf;
		return (c-a+1) * (d-b+1) + (g-e+1) * (h-f+1);
	}
	void print(){
		printf("! %d %d %d %d %d %d %d %d\n",a,b,c,d,e,f,g,h);
	}
}test,Res;
int response;
bool Try(acht t){
	printf("? %d %d %d %d\n",t.a,t.b,t.c,t.d);
	fflush(stdout);
	scanf("%d",&response);
	if(response!=1)return false;
	printf("? %d %d %d %d\n",t.e,t.f,t.g,t.h);
	fflush(stdout);
	scanf("%d",&response);
	if(response != 1)return false;
	return true;
}
int main(){
#ifndef ONLINE_JUDGE
	//freopen("input","r",stdin);
#endif
	int n,u1,u2,l1,l2,r1,r2,d1,d2,l,r;
	int ms,tmp,uu,rr,ll,dd;
	scanf("%d",&n);
	l=1,r=n;
	while(l<r){
		int mid = ((l+r)>>1)+1;
		printf("Mid = %d\n",mid);
		printf("? %d %d %d %d\n",1,1,mid,n);
		fflush(stdout);
		scanf("%d",&response);
		printf("Resp = %d\n",response);
		if(response==2)r=mid-1;
		else l=mid;
	}
	d2=l+1;
	if(d2==1)d1=1;
	else{
		printf("? %d %d %d %d\n",1,1,d2-1,n);
		fflush(stdout);
		scanf("%d",&response);
		if(response==0)d1=d2;
		else{
			l=1,r=d2-1;
			while(l<r){
				int mid = ((l+r)>>1)+1;
				printf("? %d %d %d %d\n",1,1,mid,n);
				fflush(stdout);
				scanf("%d",&response);
				if(response==1)r=mid-1;
				else l=mid;
			}
			d1=l+1;
		}
	}
	printf("d1 = %d,d2 = %d\n",d1,d2);	
	l=1,r=n;
	while(l<r){
		int mid = ((l+r)>>1)+1;
		printf("? %d %d %d %d\n",1,1,n,mid);
		fflush(stdout);
		scanf("%d",&response);
		if(response==2)r=mid-1;
		else l=mid;
	}
	r2=l+1;
	if(r2==1)r1=1;
	else{
		printf("? %d %d %d %d\n",1,1,n,r2-1);
		fflush(stdout);
		scanf("%d",&response);
		if(response==0)r1=r2;
		else{
			l=1,r=r2-1;
			while(l<r){
				int mid = ((l+r)>>1)+1;
				printf("? %d %d %d %d\n",1,1,n,mid);
				fflush(stdout);
				scanf("%d",&response);
				if(response==1)r=mid-1;
				else l=mid;
			}
			r1=l+1;
		}
	}
	
	l=1,r=n;
	while(l<r){
		int mid = (l+r)>>1;
		printf("? %d %d %d %d\n",1,mid,n,n);
		fflush(stdout);
		scanf("%d",&response);
		if(response==2)l=mid+1;
		else r=mid;
	}
	l1=l-1;
	if(l1==n)l2=n;
	else{
		printf("? %d %d %d %d\n",1,l1+1,n,n);
		fflush(stdout);
		scanf("%d",&response);
		if(response==0)l2=l1;
		else{
			l=l1+1,r=n;
			while(l<r){
				int mid = (l+r)>>1;
				printf("? %d %d %d %d\n",1,mid,n,n);
				fflush(stdout);
				scanf("%d",&response);
				if(response==1)l=mid+1;
				else r=mid;
			}
			l2=l;
		}
	}

	l=1,r=n;
	while(l<r){
		int mid = (l+r)>>1;
		printf("? %d %d %d %d\n",mid,1,n,n);
		fflush(stdout);
		scanf("%d",&response);
		if(response==2)l=mid+1;
		else r=mid;
	}
	u1=l-1;
	if(u1==n)u2=n;
	else{
		printf("? %d %d %d %d\n",u1+1,1,n,n);
		fflush(stdout);
		scanf("%d",&response);
		if(response==0)u2=u1;
		else{
			l=u1+1,r=n;
			while(l<r){
				int mid = (l+r)>>1;
				printf("? %d %d %d %d\n",mid,1,n,n);
				fflush(stdout);
				scanf("%d",&response);
				if(response==1)l=mid+1;
				else r=mid;
			}
			u2=l;
		}
	}

	if(r1<l2){
		test = acht(u1,l1,d1,r1,u2,l2,d2,r2);
		if(Try(test)){
			if(ms > test.square()){
				ms = test.square();
				Res = test;
			}
		}
		test = acht(u1,l1,d2,r1,u2,l2,d1,r2);
		if(Try(test)){
			if(ms > test.square()){
				ms = test.square();
				Res = test;
			}
		}
		test = acht(u2,l1,d1,r1,u1,l2,d2,r2);		
		if(Try(test)){
			if(ms > test.square()){
				ms = test.square();
				Res = test;
			}
		}
		test = acht(u2,l1,d2,r1,u1,l2,d1,r2);
		if(Try(test)){
			if(ms > test.square()){
				ms = test.square();
				Res = test;
			}
		}
	}
	if(d1<u2){
		test = acht(u1,l1,d1,r1,u2,l2,d2,r2);
		if(Try(test)){
			if(ms > test.square()){
				ms = test.square();
				Res = test;
			}
		}
		test = acht(u1,l1,d1,r2,u2,l2,d2,r1);
		if(Try(test)){
			if(ms > test.square()){
				ms = test.square();
				Res = test;
			}
		}
		test = acht(u1,l2,d1,r1,u2,l1,d1,r2);
		if(Try(test)){
			if(ms > test.square()){
				ms = test.square();
				Res = test;
			}
		}
		test = acht(u1,l2,d1,r2,u2,l1,d2,r1);
		if(Try(test)){
			if(ms > test.square()){
				ms = test.square();
				Res = test;
			}
		}
	}
	Res.print();
	fflush(stdout);
#ifndef ONLINE_JUDGE
	//fclose(stdin);
#endif
	return 0;
}
