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


int main(){
	vector < vector<int> >v;
	v.resize(5);
	FOR(i,0,5,1){
		FOR(j,0,3,1){
			int x;
			cin >> x; 
			v[i].push_back(x);
		}
		sort(v[i].begin(),v[i].end());
	}

	FOR(i,0,5,1){
		FOR(j,0,3,1){
			cout << v[i][j] << " "; 
		}
		cout << endl;
	}

	return 0;
}
