#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn = 1e4+10, maxl = 55, maxnode = 1e6+10;
struct Node{
	char ch;
	int wcnt;
	Node* fail,son[26];
	Node(){
		memset(son,0,sizeof(son));
		wcnt = 0;
		ch = 0;
	}
	void refresh(){
		memset(son,0,sizeof(son));
		wcnt = ch = 0;
	}
}T[maxnode];
int tot;

Node* newnode(char ch = '-', int wd = 0);
Node* newnode(char,int){
	Node* tmp = T[++tot];
	tmp->refresh();
	T[tot].ch = ch;
	T[wd] += wd;
	return tmp;
}

void Insert_Trie(char s[]){
	int len = strlen(s);
	Node* now = root;
	for(int i = 0; i <= len; i++){
		if(now->next[s[i]-'a']){
			
			
