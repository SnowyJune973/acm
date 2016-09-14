#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;
set<int> S;
int main(){
#ifndef ONLINE_JUDGE
	freopen("input","r",stdin);
#endif
	int n,x,res;
	set<int>::iterator it1,it2;
	scanf("%d",&n);
	S.clear();
	for(int i = 1; i <= n; i++){
		scanf("%d",&x);
		if(i==1){
			res=x;
			S.insert(x);
		}
		else{
			it1 = S.lower_bound(x);
			if(it1==S.begin()){
				res += abs(x-*it1);
			}
			else{
				it2=it1;
				it2--;
				if(it1==S.end()){
					res += abs(x-*it2);
				}
				else{
					res += min(abs(x-*it2),abs(x-*it1));
				}
			}
			S.insert(x);
		}
	}
	printf("%d\n",res);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}

