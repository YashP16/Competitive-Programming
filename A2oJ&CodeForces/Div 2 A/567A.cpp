#include <bits/stdc++.h>

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e9)
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(int i=a;i<b;i += c)
#define FORd(i,a,b,c) for(int i=a;i>=b;i -=c)
#define all(v) ((v).begin(),(v).end())
#define vi vector<int>
#define vii vector<vector<int> >
#define vb vector<bool>
#define vbb vector<vector<bool> >
#define vI vector<ll>
#define vII vector<vector<ll> >
#define ll long long int //range -> 9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define sz size()
#define InF  2147483647
#define READ freopen("input.txt", "r", stdin);
#define WRITE freopen("output.txt", "w", stdout);
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define SQR(n) ((n)*(n))
#define MEM(a,val) memset(a,val,sizeof(a))
using namespace std;


int main(){
	fast_io;
	int n; 
	cin >> n;
	vi cities(n);
	for(int i = 0; i< n; i++){
		cin >> cities[i];
	}
	int leftmost = cities[0];
	int rightmost = cities[n-1];

	vector <pair <int,int> > dist(n); 
	dist[0].F = abs(cities[1]-cities[0]);
	dist[0].S = abs(rightmost-cities[0]);
	dist[n-1].F = abs(cities[n-1]-cities[n-2]);
	dist[n-1].S = abs(cities[n-1]-leftmost);

 	for(int i= 1; i< n-1; i++){
		dist[i].F = min(abs(cities[i]-cities[i-1]), abs(cities[i+1]-cities[i]));
		dist[i].S = max(abs(rightmost-cities[i]), abs(cities[i]-leftmost));
	}

	for(int i= 0; i<n; i++){
		cout << dist[i].F << " " << dist[i].S << "\n";
	}

	return 0;
}