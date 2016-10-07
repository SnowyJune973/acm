/*=============================================================================
	Author: SnowyJune - me@snowyjune.top
	QQ: 896512060
	Last modified: 2016-10-07 17:32
	Filename: primeGen.cpp
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;
long long d,t;
long long paw_mod(long long bs,long long power,long long diver)
    {
     if(power==0) return(1);
      else if(power==1) return(bs);
       else if ((power&1)==0) return(paw_mod(bs*bs%diver,(power>>1),diver));
         else return(paw_mod(bs*bs%diver,power/2,diver)*bs%diver);
    }
bool M_R(long long base,long long num)
    {
       d=num-1;
       while((d&1)==0)
       {
         d=(d>>1);
       }

      if((paw_mod(base,d,num)==1)||(paw_mod(base,d,num)==num-1)) return true;
     else
     {
        t=(num-1)/2;
       while(d!=t)
       {
         d=(d<<1);
         if(paw_mod(base,d,num)==num-1) return true;
       }
       return false;     
      }       
    } 


bool check(long long p)
    {

       if(((p&1)!=0) && (p%3!=0) && (p>2) && M_R(2,p) && ((p<=7)||M_R(7,p)) && ((p<=11)||M_R(11,p)) && ((p<=3)||M_R(3,p)) && ((p<=5)||M_R(5,p)) || (p==2) || (p==3)) return true;
                                        else return false;
    }
int main(){
	/*int pm[20] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};//0 ~ 14
	for(int i = 0; i < 14; i++){
		for(long long j = 1LL << 37; pm[i]*j <= (1LL << 60); j<<=1){
			printf("P = %lld\n",pm[i]*j+1);
			if(check(pm[i]*j+1)){
				printf("%lld\n",pm[i]*j+1);
			}
		}
	}*/
	long long p;
	while(cin >> p){
		while(1){
		bool ok = true;
		for(long long i = 2; i*i<=p; i++){
			if(p%i==0){
		//		cout << "No" << endl;
				ok = false;
				break;
			}
		}
		if(ok){
			cout << p << endl;
			break;
		}
		else p+=2;
		}
	}
			
	return 0;
}


