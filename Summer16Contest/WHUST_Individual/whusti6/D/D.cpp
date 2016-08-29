/*************************************************************************
    > File Name: D.cpp
    > Author: SnowyJune
    > Mail: SnowyJune 
    > Created Time: 2016年07月30日 星期六 22时53分15秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#define ms(x,y) memset(x,y,sizeof(x))
#define lson(x) (x>>1)
#define rson(x) ((x>>1)|1)
using namespace std;
#define lowbit(x) (x&(-x))
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x3f3f3f3f;
const LL linf = 0x3f3f3f3f3f3f3f3fLL;
int enters;
LL operate1(){
	LL cnt = 0;
	char ch=getchar();
	while(ch!='}'){
		if(ch == '|')cnt++;
		if(ch == '\n')enters++;
		ch = getchar();
	}
	return cnt+1;
}
LL operate2(){
	LL cnt = 1,bcnt;
	char ch=getchar();
	while(ch!='$'){
		printf("cnt = %d , ch = %c\n",cnt,ch);
		bcnt=-1;
		if(ch==' '){
			bcnt=0;
			while(ch==' ' || ch=='\n'){
				if(ch==' ')bcnt++;
				else enters++;
				ch=getchar();
			}
			cnt*=(bcnt+1);
		}
		if(cnt>100000LL)return -1;
		if(bcnt==-1)ch=getchar();
	}
	return cnt;
}
char s[2000000];
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	int n;
	char ch;
	while(scanf("%d\n",&n)==1){
		//printf("N = %d\n",n);
		memset(s,0,sizeof(s));
		for(int i = 1; i <= n; i++){
			int len = strlen(s);
			gets(s+len);
			//puts("");
			//int offset = 0;
			//while(*(t+offset)!=0){
			//	putchar(*(t+offset));
			//	offset++;
			//}
			//puts("");
			//printf("T = [%s]\n",t);
			//memcpy(s+len,t,sizeof(char)*strlen(t));
		//	printf("S = *%s*\n",s);
		}
		LL res = 1,cnt;
		int len = strlen(s);
		bool flag;
		for(int i = 0; i < len; i++){
		//	printf("I = %d\n",i);
			flag = true;
			if(s[i] == '$'){
				do{
					i++;
					if(s[i] == ' '){
						cnt = 0;
						while(s[i] == ' ')i++,cnt++;
						res = 1LL*(cnt+1)*res;
					}
					if(res>100000)break;
				}while(s[i] != '$');
				flag = false;
		//		printf("IIII = %d\n",i);
			}
			if(res>100000)break;
			if(s[i] == '{'){
				cnt = 1;
				while(s[i] != '}'){
					if(s[i] == '|')cnt++;
					i++;
				}
				res = 1LL*cnt*res;
				if(res>100000)break;
			}
			//if(!flag)i--;
		}
		if(res > 100000){
			puts("doge");
		}
		else{
			printf("%lld\n",res);
		}
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
