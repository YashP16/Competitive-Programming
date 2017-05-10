#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;
ll nDiv(ll a){
	ll count = 0;
	int i;
	FOR(i,1,(int)sqrt(a)+1,1){
		if(a%i == 0){ 
			if(i!=a/i)count+=2;
			else count+=1;
		}
	}
	return count;
}

int main(){
	int a,b,c,i,j,k;
	cin >> a >> b >> c;
	ll count=0;
	ll m[(a*b*c)+1] = {0};
	FOR(i,1,a+1,1){
		FOR(j,1,b+1,1){
			FOR(k,1,c+1,1){
				ll d;
				if(m[i*j*k] == 0){
					 d = nDiv(i*j*k);
					 m[i*j*k]=nDiv(i*j*k);
				}
				else d = m[i*j*k];
				count+= d;
			}
		}
	}
	cout << count;
	return 0;
}