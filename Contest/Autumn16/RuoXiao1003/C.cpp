/*=============================================================================
	Author: SnowyJune - me@snowyjune.top
	QQ: 896512060
	Last modified: 2016-10-07 21:03
	Filename: C.cpp
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;
struct rec{
	int active,intime;
};
bool operator < (rec a,rec b){
	return (a.active==b.active)?(a.intime>b.intime):(a.active>b.active);
}
map<rec,string> M; 
int main(){
#ifdef SNOWYJUNE
	freopen("input","r",stdin);
#endif
	
