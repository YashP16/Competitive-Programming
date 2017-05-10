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
	int n,i,m;
	cin >> n;
	cin >> m;
	ui a[n];
	ui add =0;
	REP(i,n){
		cin >> a[i];
	}
	while(m--){
		int t;
		cin >> t;
		if(t==1){
			int v,x;
			cin >> v >> x;
			a[v-1]=x - add;
		}
		else if(t==2){
			int y;
			cin >> y;
			add += y;
		}
		else if(t == 3){
			int j;
			cin >> j;
			cout << a[j-1] + add << endl;
		}
	}
	return 0;
}