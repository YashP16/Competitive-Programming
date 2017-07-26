#include <bits/stdc++.h>

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e9)
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(int i=a;i<b;i += c)
#define FORd(i,a,b,c) for(int i=a;i>=b;i -=c)
#define all(v) ((v).begin(),(v).end())
#define vi vector<ll>
#define vii vector<vector<ll> >
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



int main(){
	fast_io;
	cin.tie(NULL);
	int n;
	string s;
	cin >> n;
	while(n--){
		cin >> s;
		int len = s.length();
		int pos = len-1;
		while(pos>0){
			if(s[pos]<=s[pos-1])pos--;
			else break;
		}
		if(pos>0){
			char c = s[pos-1];
			int idx = len-1;
			while(idx>pos){
				if(s[idx] <= c)idx--;
				else break;
			}
			REP(i,pos-1)cout << s[i];
			cout << s[idx];
			FORd(i,len-1,pos,1){
				if(i==idx)cout << c;
				else cout << s[i];
			} 
			cout << "\n";
		}
		else cout << "no answer\n";
	}
	return 0;
}