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

int main(){
	int n;
	cin >> n;
	string s[n];
	REP(l,n){
		cin >> s[l];
	}
	vector<int> x;
	int carry=0;
	int i = 49;
	while(i>=0){
		int sum = carry;
		int j;
		FOR(j,0,n,1){
			//cout << sum << "(" << s[j][i]-'0' << ") ";
			sum+= s[j][i]-'0';
		}
		//cout << sum << " " << sum/10 << " " << sum % 10 << endl;
		x.push_back(sum % 10);
		carry = sum / 10;
		i--;
	}
	if(carry!=0){
		x.push_back(carry);
	}	
	REP(k,10){
		cout << x[x.size()-1-k];
	}
	cout << endl;
	return 0;
}