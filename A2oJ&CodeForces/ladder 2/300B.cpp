#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
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
	int n,m;
	cin >> n >> m;
	stack <int> s;
	if(m == 0){
		REP(i,n){
			cout << i+1 << " ";
			if((i+1)%3 == 0)cout << "\n";
		}
	}
	else{
		pair <vector<int>,int>  a[n+1];
		while(m--){
			int x,y;
			cin >> x >> y;
			a[x].first.push_back(y);
			a[x].second = -1;
			a[y].first.push_back(x);
			a[y].second = -1;
		}
		/*FOR(i,1,n+1,1){
			cout << i  << "->  " << a[i].second << " " ;
			
			FOR(j,0,a[i].first.size(),1){
				cout << a[i].first[j] << " ";
			}
			cout << endl;
		}*/
		


	}

	return 0;
}