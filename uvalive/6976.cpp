#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include <stack>
using namespace std;
string dict,q;
char tmp[700000];
int Pair[700000];
map<string,string> M;
void Make_Pair(){
    int len = dict.length();
    stack<int> S;
    while(!S.empty())S.pop();
    for(int i = 0 ; i < len; i++){
        if(dict[i]=='{'){
            S.push(i);
        }
        if(dict[i]=='}'){
            int pp = S.top();
            S.pop();
            Pair[pp] = i;
        }
    }
}
void dfs(string pre,int l,int r){
    int p = l;
    string key = "" , value = "";
    //cout << "Dict = " << dict << endl;
    for(int i = l; i <= r;){
        if(dict[i] == '\"'){
            key = "";
            i++;
            while(dict[i] != '\"')key += dict[i++];
            key = '\"' + key + '\"';
            //cout << "Key = " << pre+'.'+key << endl;
            if(dict[i+2]=='{'){
                int j = Pair[i+2];
              //  cout << "Pair " << i+2 << " = " << j << endl;
                dfs(pre+'.'+key,i+3,j-1);
                M[pre+'.'+key] = dict.substr(i+2,j-i-1);
                //cout << "Value = " << dict.substr(i+2,j-i-1) << endl;
                i = j+2;
                //cout << i << ' ' << dict[i] << endl;
            }
            else{
                    //{"abc":"abc","d":"e"}
                i+=3;
                value = "";
                while(dict[i] != '\"')value += dict[i++];
                value = '\"' + value + '\"';
                M[pre+'.'+key] = value;
               // cout << "Value = " << value << endl;
                i+=2;
            }
        }
        else i++;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int T,n;

    scanf("%d\n",&T);
    while(T--){
        gets(tmp);
        //puts("********************");
        //puts(tmp);
        dict = "";
        dict.append(tmp);
        Make_Pair();
        M.clear();
        int len = dict.length();
        dfs("",0,len-1);
        scanf("%d\n",&n);
        for(int i = 1; i <= n; i++){
            gets(tmp);
          //  printf("Tmp = %s\n",tmp);
            q= ".";
            q.append(tmp);
            if(M.find(q) == M.end()){
                puts("Error!");
            }
            else{
                puts(M[q].c_str());
            }
            //puts("|||||||||||||||||||||||||||||");
        }
    }
    return 0;
}
