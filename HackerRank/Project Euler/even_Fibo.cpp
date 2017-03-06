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
vi fib_sieve (3,-1);

ll fibonacci(ll i){
	if(fib_sieve[i] != -1) return fib_sieve[i];
	else{
		return fibonacci(i-1)+fibonacci(i-2);
	}
}
ll even_fibo(ll n){
	ll sum=0;
	int i =1;
	while(fib_sieve[i]<= n){
		if(fib_sieve[i] % 2 == 0){
			sum += fib_sieve[i];
		}
		if(fib_sieve[i+1]==-1){
			fib_sieve[i+1] = fibonacci(i+1);
			fib_sieve.push_back(-1);
		}
		i++;
	}
	return sum;
}

int main(){
	fib_sieve[0]=0;
	fib_sieve[1]=1;
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		cout << even_fibo(n) << endl;
	}
	return 0;
}