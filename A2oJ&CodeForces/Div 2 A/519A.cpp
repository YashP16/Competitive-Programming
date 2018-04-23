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


int main(){
	fast_io;
	int wc = 0;
	int bc = 0;
	string s;
	REP(i,8){
		cin >> s;
		REP(i,8){
			if(s[i]== 'Q')wc+=9;
			else if(s[i]=='q')bc+= 9;
			else if(s[i]=='R')wc+= 5;
			else if(s[i]=='r')bc+= 5;
			else if(s[i]=='B')wc+= 3;
			else if(s[i]=='b')bc+= 3;
			else if(s[i]=='N')wc+= 3;
			else if(s[i]=='n')bc+= 3;
			else if(s[i]=='P')wc+= 1;
			else if(s[i]=='p')bc+= 1;
		}
	}
	if(wc > bc)cout << "White\n";
	else if(wc < bc)cout << "Black\n";
	else cout << "Draw\n";	
	return 0;
}