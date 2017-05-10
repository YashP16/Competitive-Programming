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

bool crout(string s){
	int flag = 0;
	FOR(i,0,s.length()-1,1){
		if(flag == 0){
			if(s[i]> s[i+1]){
				return false;
			}
			else if(s[i]<s[i+1]){
				flag=1;
			}
		}
		else{
			if(s[i]>=s[i+1]){
				flag = 0;
			}
		}
	}
	return true;
}


int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		if(crout(s))cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}
