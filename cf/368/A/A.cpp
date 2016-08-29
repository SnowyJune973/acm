#include <cstdio>
#include <cstring>
int main(){
	char s[500];
	int n,m;
	scanf("%d%d\n",&n,&m);
	bool isbw = true;
	for(int i = 1; i <= n; i++){
		gets(s);
		for(int j = 0; j < strlen(s); j++){
			if(s[j] == 'C' || s[j] == 'M' || s[j] == 'Y'){
				isbw = false;
				break;
			}
		}
		if(!isbw)break;
	}
	if(isbw)puts("#Black&White");
	else puts("#Color");
	return 0;
}
