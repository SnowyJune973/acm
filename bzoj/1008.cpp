#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
const LL mod = 100003;
LL n,m;
LL mi(LL a,LL x){
    LL mul = 1;
    while(x){
        if(x&1)mul = (mul*a) % mod;
        x>>=1;
        a=(a*a)%mod;
    }
    return mul;
}
int main(){
    cin >> m >> n;
    cout << (100003LL + mi(m,n) - (m*mi(m-1,n-1)) % mod) % mod <<endl;
    return 0;
}
