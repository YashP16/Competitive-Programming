#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(ll i=a;i<b;i += c)
#define FORd(i,a,b,c) for(ll i=a;i>=b;i -=c)
#define vi vector<ll>
#define vii vector<vector<ll> >
#define ll long long int //range -> â��9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
using namespace std;

ll fact(int n,ll m){
	ll temp=n;
	FOR(i,1,n,1){
		if(temp>m) temp = temp%m;
		else temp *= (n-i);
	}
	return temp;
};

int main(){
	int n;
	cin >> n;
	vector<ll> a;
	ll sum = 0;
	REP(i,n){
		ll x;
		cin >> x;
		sum+= x;
		a.push_back(x);
	}

	if(sum%2 != 0 )cout << "NO\n";
	
	else{
		sum /= 2;
		ll temp =0;
		int p =0;
		while(temp<sum){
			temp += a[p];
			p++;
		}
		if(temp > sum){
			FOR(j,0,p,1){
				if(temp - a[j] == sum){
					cout << "YES\n";
					return 0;
				}
			}
			temp -= a[p-1];
			FOR(j,p,a.size(),1){
				if(temp + a[j] == sum){
					cout << "YES\n";
					return 0;
				}
			}
			
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
	return 0;
}