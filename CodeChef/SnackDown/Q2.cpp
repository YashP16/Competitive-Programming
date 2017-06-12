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

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector <int> h(n);
		bool flag = 1;
		cin >> h[0];
		int prev =h[0];
		
		FOR(i,1,n,1){
			cin >> h[i];
			if(abs(prev - h[i])!= 1)flag = 0;
			prev = h[i];
		}
		
		if(n%2 == 0)cout << "no\n";
		else{
			if(h[0]==1 && h[n-1]==1 && h[n/2]==(n/2)+1 && flag ==1)cout << "yes\n";
			else cout << "no\n";
		}
	}
	return 0;
}