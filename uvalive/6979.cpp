#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
char str[1020];
void work(){
    scanf("%s",str);
    //puts(str);
    int dig=0,asterik=0,res=0;
    string s="";
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        if(str[i]=='*')asterik++;
        else dig++;
    }
    s.append(str);
    while(dig<=asterik)s="1"+s,res++,dig++;
    //cout << '<' << s << endl;
    len = s.length();
    dig=asterik=0;
    for(int i = 0; i < len; i++){
        if(s[i]=='*')asterik++;
        else dig++;
        if(dig<=asterik && s[i]=='*'){
            for(int j = len-1; j > i; j--){
                if(s[j] >= 48 && s[j] <= 57){
                    asterik--;
                    dig++;
                    swap(s[i],s[j]);
                    res++;
                    break;
                }
            }
        }
    }
    printf("%d\n",res);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int T;
    scanf("%d",&T);
    while(T--)work();
    #ifndef ONLINE_JUDGE
    fclose(stdin);
    #endif // ONLINE_JUDGE
    return 0;
}
