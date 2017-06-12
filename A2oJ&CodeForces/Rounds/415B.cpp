#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stack>
#include <limits>
#include <vector>
#include <stack>
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

bool comp(const pair<ll,ll> &a,const pair<ll,ll> &b){
    if( (min(2*a.first,a.second)-min(a.first,a.second) ) > (min (2*b.first,b.second)-min(b.first,b.second) ) )return true;
    else return false;
}

int main(){
	int n,f;
	cin >> n >> f;
	pair <ll,ll> a[n];
	ll count = 0;

	REP(i,n){
		cin >> a[i].first >> a[i].second ;
	}
	sort(a,a+n,comp);

	FOR(i,0,n,1){
		if(i<f)count+= min(2*a[i].first,a[i].second);
		else count+= min(a[i].first,a[i].second);
	}

	cout << count << endl;
	return 0;
}