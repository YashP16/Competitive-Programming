#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b,c) for(int i=a;i<b;i += c)
#define FORd(i,a,b,c) for(ll i=a;i>=b;i -=c)
#define vi vector<ll>
#define vii vector<vector<ll> >
#define ll long long int //range -> â��9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
#define se second
#define fi first
using namespace std;

bool comp(const pair<int,int> &a,const pair<int,int> &b){
    if( ((float)a.se/(float)a.fi) > ((float)b.se/(float)b.fi))return true;
    else return false;
}
int main(){
	int n,m;
	cin >> n >> m; 
	pair <int,ll> s[n];
	REP(i,n)cin >> s[i].fi >> s[i].se;
	sort(s,s+n,comp);
	int count =0;
	ll total =0;
	while(m>0 && count < n){
		if(s[count].fi <= m){
			total += s[count].se;
			m -= s[count].fi;
		}
		count++;
	}
	cout << total;
	return 0;
}
