#include <cstdio>
#include <iostream>
using namespace std;
int a[101];
int main(){
    a[0] = 0;
    a[1] = 1;
    for(int i = 2; i <= 100; i++){
        if(i%2)a[i] = a[i/2] + a[i/2+1];
        else a[i] = a[i/2];
    }
    for(int i = 1; i <= 100; i++){
        printf("%8d",a[i]);
        if(i%10==0)puts("");
    }
    return 0;
}
