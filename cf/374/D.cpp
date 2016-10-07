#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 2e5+20;
typedef long long LL;
int n,k;
LL x,mx,mi;
struct td{
	LL val;
	int id;
}a[maxn];
LL Div(LL a,LL b){
	return (a%b)?(a/b+1):(a/b);
}
bool cmp(td a,td b){
	if(Div(a.val+mx,x)!=Div(b.val+mx,x))return Div(a.val+mx,x)>Div(b.val+mx,x);
	else return a.val>b.val;
}
bool cmp2(td a,td b){
	return a.val>b.val;
}
bool cmp3(td a,td b){
	return a.id < b.id;
}
bool operator < (td a,td b){
	return a.val < b.val;
}
multiset<td> S;
int main(){
#ifdef SNOWYJUNE
	freopen("input","r",stdin);
#endif
	scanf("%d%d%lld",&n,&k,&x);
	for(int i = 1; i <= n; i++){
		scanf("%lld",&a[i].val);
		a[i].id=i;
	}
	mx = -1LL * 0x3f3f3f3f;
	for(int i = 1; i <= n; i++)mx = max(mx,a[i].val);
	sort(a+1,a+n+1,cmp);
//	printf("%lld\n",a[n].val);
	while(a[n].val>-mx && k>0){
		a[n].val -= x;
		k--;
	}
	int Minus = a[n].id;
	a[n].val = 0-a[n].val;
	S.clear();
	for(int i = 1; i <= n; i++)S.insert(a[i]);
	while(k--){
		td tmp = *S.begin();
//		printf("%lld %d\n",tmp.val,tmp.id);
		S.erase(S.begin());
		tmp.val += x;
		S.insert(tmp);
	}
	int j = 1;
	for(set<td>::iterator it = S.begin(); it != S.end(); it++,j++){
//		printf("%lld %d\n",it->val,it->id);
		a[j] = *it;
	}
	sort(a+1,a+n+1,cmp3);
	for(int i = 1; i <= n; i++){
		if(i == Minus)a[i].val = 0-a[i].val;
		printf("%lld%c",a[i].val,(i==n)?'\n':' ');
	}
#ifdef SNOWYJUNE
	fclose(stdin);
#endif
	return 0;
}
		
	
	
