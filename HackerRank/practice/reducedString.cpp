#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
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

int main(){
	string s;
	cin>>s;
	stack <char> a;
	a.push(s[0]);
	FOR(i,1,s.length(),1){
		if(a.empty())a.push(s[i]);
		else if(s[i]==a.top()){
			a.pop();
		}
		else a.push(s[i]);
	}
	if(a.empty()) cout << "Empty String\n";
	string temp = "";
	while(!a.empty()){
		temp += a.top();
		a.pop();
	}
	FORd(i,temp.length()-1,0,1){
		cout << temp[i];
	} 
	cout << endl;
}