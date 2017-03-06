#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
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

int main(){
	vi v;
	ll k=2;
	while(k <=1000000){
		if(isPrime(k)){
			v.push_back(k);
		}
		k++;
	}
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		ll sum =0;
		int i =0;
		while(v[i]<=n && i<v.size()){
			sum+= v[i];
			i++;
		}
		cout << sum << endl;
	}
	return 0;
}