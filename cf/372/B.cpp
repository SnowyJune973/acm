#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn = 1e5+10;
const int inf = 0x3f3f3f3f;
const long long linf = 1LL<<60;
typedef long long LL;
char s[maxn];
int main(){
#ifndef ONLINE_JUDGE
	freopen("input","r",stdin);
#endif
	scanf("%s",s);
	int len = strlen(s),cnt[26],que;
	bool had = false;
	if(len<26){
		puts("-1");
		return 0;
	}
	for(int i = 0; i <= len-26; i++){
		memset(cnt,0,sizeof(cnt));
		for(int j = 0; j < 26; j++){
			if(s[i+j]=='?'){
				que++;
			}
			else{
				cnt[s[i+j]-'A']++;
			}
		}
		bool flag = true;
		for(int j = 0; j < 26; j++){
			if(cnt[j] > 1){
				flag = false;
				break;	
			}
		}
		if(flag){
			int k = 0;
			for(int j = 0; j < 26; j++){
				if(s[i+j] == '?'){
					while(cnt[k]>0)k++;
					s[i+j] = 'A' + k;
					cnt[k]++;
				}
			}
			for(int j = 0; j < len; j++){
				if(s[j]=='?')s[j]='A';
			}
			puts(s);
			had = true;
			break;
		}
	}
	if(!had){
		puts("-1");
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
