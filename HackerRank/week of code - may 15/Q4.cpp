#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stack>
#include <limits>
#include <vector>
#include <sstream>
#include <queue>
#include <utility> // for pair
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(int i=a;i<b;i += c)
#define FORd(i,a,b,c) for(int i=a;i>=b;i -=c)
#define vi vector<ll>
#define vii vector<vector<ll> >
#define ll long long int //range -> 9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
#define PB push_back
#define sz size()
#define InF  2147483647
using namespace std;

bool isTriple(string s,int a,int c){
	ll prod = (a+1)*(c+1);
	ll m = sqrt(prod);
	if (m*m == prod){
		if(s[m-1]=='b')return true;
	}
	return false;
}

int main(){
	vector< vector<int> > v(2);
	int n;
	string s;
	cin >> n;
	cin >> s;
	REP(i,n){
		if(s[i]=='a')v[0].PB(i);
		else if(s[i]=='c')v[1].PB(i);
	}
	int count =0;
	REP(i,v[0].size()){
		REP(j,v[1].size()){
			if(isTriple(s,v[0][i],v[1][j]))count++;
		}
	}
	cout << count << endl;
	return 0;
}