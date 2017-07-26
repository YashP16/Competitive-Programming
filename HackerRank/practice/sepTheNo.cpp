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
#define fast_io ios_base::sync_with_stdio(false)
#define SQR(n) ((n)*(n))
#define MEM(a,val) memset(a,val,sizeof(a))
using namespace std;


string isSeperable(string s){
	int lens = s.length();
	if(lens == 1)return "!";

	string init = "";
	init+=s[0];
	string curr,nxt;
	int c,n,nxts;
	int pos=1,lenn;

	int count = 1;
	while(1){
		curr= init;
		c = stoi(curr);
		n = c + count;
		nxt = to_string(n);
		lenn = nxt.length();
		if(lens-pos<lenn)return "!";
		nxts = stoi(s.substr(pos,lenn));
		if(nxts==n){
			if(pos+lenn== lens)return init;
			count++;
			pos+=lenn;
		}
		else{
			pos = init.length();
			init+=s[pos];
			if(init.length()>lens/2 )return "!";
			count = 1;
			pos++;
		}
	}
}


int main(){
	fast_io;
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		string res = isSeperable(s);
		if(res == "!")cout << "NO\n";
		else cout << "YES " << res << "\n";

	}
	return 0;
}