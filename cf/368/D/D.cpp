#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;
bitset<1005> mem[110000];
int ones[110000],bks[1005];
vector<pair<int,int> > change[1005];
int tot,memtot,n,m,q,cnt1=0;
const int inf = 0x3f3f3f3f;
FILE* fout;
void init(){
	memset(bks,0,sizeof(bks));
	mem[0].reset();
	for(int i = 1; i <= 1000; i++)change[i].clear();
	tot = 0;
	cnt1=0;
}
void Add(int p,int q,int id){
	bitset<1005> tmp(mem[bks[p]]);
	mem[++tot] = tmp;
	ones[tot] = ones[bks[p]];
	if(!mem[tot].test(q))ones[tot]++,cnt1++;
	mem[tot].set(q);
	bks[p] = tot;
	change[p].push_back(make_pair(id,tot));
	
	fprintf(fout,"%d\n",cnt1);
}
void Erase(int p,int q,int id){
	bitset<1005> tmp(mem[bks[p]]);
	mem[++tot] = tmp;
	ones[tot] = ones[bks[p]];
	if(mem[tot].test(q))ones[tot]--,cnt1--;
	mem[tot].reset(q);
	bks[p] = tot;
	change[p].push_back(make_pair(id,tot));
	fprintf(fout,"%d\n",cnt1);
}
void Flip(int p,int id){
	bitset<1005> tmp(mem[bks[p]]);
	mem[++tot] = tmp;
	cnt1 = cnt1 + m-2*ones[bks[p]];
	ones[tot] = m-ones[bks[p]];
	mem[tot].flip();
	bks[p] = tot;
	change[p].push_back(make_pair(id,tot));
	fprintf(fout,"%d\n",cnt1);
}
void Return(int p,int id){
	vector<pair<int,int> >::iterator it;
	cnt1 = 0;
	for(int i = 1; i <= n; i++){
//		printf("I = %d\n",i);
		it = upper_bound(change[i].begin(),change[i].end(),make_pair(p,inf));
		if(it == change[i].begin()){
			change[i].push_back(make_pair(id,0));
			bks[i] = 0;
		}
		else{
			it--;
//			printf("It->First: Id = %d, It->Second: Tot = %d\n",it->first,it->second);
			bks[i] = it->second;
			change[i].push_back(make_pair(id,bks[i]));
		}
		cnt1 += ones[bks[i]];
	}
	fprintf(fout,"%d\n",cnt1);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
	//freopen("user","w",stdout);
#endif
	fout = fopen("user","w");
	int tp,qi,qj,qk;
	scanf("%d%d%d",&n,&m,&q);
	for(int i = 1; i <= q; i++){
		if(i % 1000 == 0)printf("I = %d\n",i);
		scanf("%d",&tp);
		if(tp<4){
			scanf("%d",&qi);
			if(tp==3){
				Flip(qi,i);
			}
			else{
				scanf("%d",&qj);
				if(tp==1){
					Add(qi,qj,i);
				}
				else{
					Erase(qi,qj,i);
				}
			}
		}
		else{
			scanf("%d",&qk);
			Return(qk,i);
		}
	}
	fclose(fout);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
		
	
