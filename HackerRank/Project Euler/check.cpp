#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(int i=a;i<b;i += c)
#define FORd(i,a,b,c) for(int i=a;i>=b;i -=c)
#define vi vector<ll>
#define vii vector<vector<ll> >
#define ll long long int //range -> –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
using namespace std;

bool isPrime(ll n){
    if(n == 2)return true;
    ll i;
    FOR(i,2,sqrt(n)+1,1){
        if(n%i ==0){
            return false;
        }
    }
    return true;
}

int numDiv(ll n){
	if(n == 1) return 1;
	ll x = n;
	int c = 1;
	FOR(i,2,x,1){
		int temp = 0;
		if(isPrime(i)){
			while(n%i==0){
				temp++;
				n = n/i;
			}
			c = c*(temp+1);
		}
	}
	return c;
}

int main(){
	cout << "{ ";
	int x = 1;
	ll tn = 1;
	FOR(i,1,1001,1){
		while(numDiv(tn)<=i){
			x++;
			tn =x*(x+1)/2;  
		}
		cout << tn << ", ";
	}
	cout << "}\n";
	return 0;
}