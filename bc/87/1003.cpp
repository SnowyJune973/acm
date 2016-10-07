#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
const int maxn = 1e5+20;
struct data{
	int val,id;
}a[maxn],b[maxn];
struct record{
	int key,id0,id1;
	record(int arg1=0,int arg2=0,int arg3=0):
		key(arg1),id0(arg2),id1(arg3){}
};
bool operator < (record a,record b){
	if(a.key != b.key)return a.key <b.key;
	else{
		if(a.id0 != b.id0)return a.id0 < b.id0;
		else return 
bool cmp_val(data a,data b){
	return a.val<b.val;
}
bool cmp_id(data a,data b){
	return a.id<b.id;
}
int n,m;
vector<int> pos[maxn<<1];
map<int,int> M;
map<record,int> MM;
void input(){
	M.clear();
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i].val);
		a[i].id = i;
	}
	for(int i = 1; i <= m; i++){
		scanf("%d",&b[i].val);
		b[i].id = i;
	}
	sort(a+1,a+n+1,cmp_val);
	int tot=0;
	for(int i = 1; i <= n; i++){
		if(i==1||a[i]!=a[i-1]){
			M[a[i]] = ++tot;
		}
	}
	sort(b+1,b+m+1,cmp_val);
	for(int i = 1; i <= m; i++){
		if(i==1||b[i]!=b[i-1]){
			M[-b[i]] = ++tot;
		}
	}
	for(int i = 1; i <= tot; i++)pos[i].clear();
	sort(a+1,a+n+1,cmp_id);
	sort(b+1,b+m+1,cmp_id);
	for(int i = 1; i <= n; i++){
		pos[M[a[i]]].push_back(i);
	}
	for(int i = 1; i <= m; i++){
		pos[M[-b[i]]].push_back(i);
	}
}
void cal(){
	MM.clear();
	input();
	sort(a+1,a+n+1,cmp_val);
	for(int i = 1; i <= n; i++){
		if(i==1||a[i]!=a[i-1]){
			if(M.find(-a[i])!=M.end()){
				int p0 = M[a[i]], p1 = M[-a[i]];
				MM.insert(make_pair(record(a[i],pos[p0][0], pos[p1][0]),1));
			}
		}
	}
	while(!MM.empty()){
		record tmp = MM.begin()->first;
		int val = MM.begin()->second;
		MM.erase(*MM.begin());
		int nkey = tmp.key+1;
		if(M.find(nkey)==M.end() || M.find(-nkey)==M.end()){
			continue;
		}
		int p0 = M[nkey], p1 = M[-nkey];
		vector<int>::iterator it0 = upper_bound(pos[p0].begin(),pos[p0].end(),tmp.id0), it1 = upper_bound(pos[p1].begin(),pos[p1].end(),tmp.id1);
		if(it0 == pos[p0].end() || it1 == pos[p1].end()){
			continue;
		}
		int id0 = *it0, id1 = *it1;
		MM.insert(make_pair(nkey,id0,id1),val+1);
	}
}

	
	
