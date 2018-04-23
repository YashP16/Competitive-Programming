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
#define sz size()
#define InF  2147483647
#define READ freopen("input.txt", "r", stdin);
#define WRITE freopen("output.txt", "w", stdout);
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define SQR(n) ((n)*(n))
#define MEM(a,val) memset(a,val,sizeof(a))
using namespace std;

int Func(ll k,ll l,ll n,vI &keys){
	k = k%100000;
	if (k==l)return 0;
	vb visited(100000,0); 
	queue < pair <ll,ll> > Q;
	Q.push(make_pair(k,0));
	visited[k]=1;
	while(!Q.empty()){
		pair <ll,ll> f = Q.front(); 
		FOR(i,0,n,1){
			ll p = (f.F*keys[i])%100000;
			if(!visited[p]){
				if(p == l)return f.S +1;
				Q.push(make_pair(p,f.S+1));
				visited[p]=1;
			} 
		}
		Q.pop();
	}
	return -1;
}

int main(){
	fast_io;
	ll k,l,n;
	cin >> k >> l >> n;
	vI keys(n);
	REP(i,n)cin >> keys[i]; 
	cout << Func(k,l,n,keys) << "\n";
	return 0;
}