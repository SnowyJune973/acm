#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <cstdlib>
#include <algorithm>
using namespace std;  
const int inf = 0x3f3f3f3f;
const int maxn = 1e6+10;  
int lb[maxn],rb[maxn],el,er;  
char s[maxn];  
int main(){
	while(scanf("%s",s) == 1){  
		int len = strlen(s),ans=0;  
		if(len&1) ans=-1;  
		else {  
			lb[0] = rb[0] = 0;  
			for(int i = 0; i < n; i++){  
				if(s[i]=='('){   
					lb[i]++;  
					rb[i]++;  
				}
				else if(s[i]=='?'){  
					lb[i]--;  
					rb[i]++;  
				}
				else{  
					lb[i]--;  
					rb[i]--;  
				}  
				if(fl[i]<0)  
					fl[i]+=2;  
				if(fr[i]<0){  
					ans=-1;  
					break;  
				}  
				fl[i+1]=fl[i];  
				fr[i+1]=fr[i];  
			}  
			if(ans!=-1){  
				el=er=0;  
				for(int i=n-1;i>0;i--){  
					if(s[i]==')'){  
						el++;  
						er++;  
					}else if(s[i]=='?'){  
						el--;  
						er++;  
					}else{  
						el--;  
						er--;  
					}  
					if(el<0)  
						el+=2;  
					if(er<0){  
						ans=-1;  
						break;  
					}  
					if(max(el,fl[i-1])==min(er,fr[i-1]))  
						ans=max(ans,0);  
					if(min(er,fr[i-1])-max(el,fl[i-1])>=2)  
						ans=max(ans,1);  
				}  
			}  
		}  
		if(ans==-1)puts("None");  
		else if(ans==1)puts("Many");  
		else puts("Unique");  
	}  
	return 0;  
}  


