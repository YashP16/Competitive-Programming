#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;

ll StringToInteger(string NumberAsString)
{
	ll NumberAsInteger;
	stringstream ss;
	ss << NumberAsString;
	ss >> NumberAsInteger;
	return NumberAsInteger;
}
void remove0 (string &s){
	int i;
	FOR(i,0,s.length(),1){
		if(s[i]=='0'){
			s.erase(s.begin()+i);
			i--;
		}
	}
}
int main(){
	string a,b;
	string c;
	cin >> a >> b;
	ll x =StringToInteger(a);
	ll y =StringToInteger(b);
	ll z = x+y; 
	c = to_string(z); 
	remove0(a);
	remove0(b);
	remove0(c);
	x =StringToInteger(a);
	y =StringToInteger(b);
	z =StringToInteger(c);
	cout << x;
	if(x+y == z)cout << "YES";
	else cout << "NO";
	
	return 0;
}