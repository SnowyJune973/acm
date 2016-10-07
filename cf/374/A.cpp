#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> V;
int n;
char s[105];
int main(){
#ifdef SNOWYJUNE
	freopen("input","r",stdin);
#endif
	scanf("%d",&n);
	scanf("%s",s);
	int yong = 0;
	V.clear();
	for(int i = 0; i < n; i++){
//		printf("I = %d\n",i);
		if(i==0){
			if(s[i]=='B'){
				yong = 1;
			}
		}
		else{
			if(s[i] == 'B' && s[i-1] == 'W'){
				if(yong != 0)V.push_back(yong);
				yong = 1;
			}
			else if (s[i] == 'B' && s[i-1] == 'B')yong ++;
		}
	}
	if(yong != 0)V.push_back(yong);
	printf("%d\n",V.size());
	for(int i = 0; i < V.size(); i++){
		printf("%d%c",V[i],(i==V.size()-1)?'\n':' ');
	}
#ifdef SNOWYJUNE
	fclose(stdin);
#endif
	return 0;
}

