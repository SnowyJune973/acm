#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
char s[100010];
int main(){
#ifndef ONLINE_JUDGE
	freopen("/home/snowyjune/code/input","r",stdin);
#endif
	scanf("%s",s);
	int len = strlen(s);
	int l=0,r;
	while(l<len&&s[l]=='a')l++;
	if(l<len){
		r=l;
		while(r<len&&s[r]!='a')r++;
		if(r>=len)r=len;
		for(int i = l; i < r; i++){
			s[i]--;
		}
	}
	else{
		s[len-1]='z';
	}
	puts(s);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}

