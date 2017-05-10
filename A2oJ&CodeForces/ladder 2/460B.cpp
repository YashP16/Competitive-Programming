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
int s_x(ui x){
	string s= to_string(x);
	int i;
	int count =0;
	FOR(i,0,s.length(),1){
		count += (s[i]-'0');
	}
	return count;
}

int main(){
	ll x=0;
	int a,b,c;
	int count =0;
	int sum =1;
	vi v;
	cin >> a >> b >> c;
	while(sum <=81){
		ll temp = sum;
		int i;
		FOR(i,1,a,1){
			temp = temp*sum;
		}
		x = b*(temp)+c;
		if(x > 0 && x < 1000000000){
			if(s_x(x)==sum){
				count++;
				v.push_back(x);
			}
		}
		sum++;
	}
	cout << count << endl;
	REP(i,count){
		cout << v[i] << " ";
	}
	return 0;
}