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

string hex(int n){
	stringstream ss;
	ss<< hex << n; 
	string res(ss.str());
	return res;
}

bool check(string s){
	bool flag = 1;
	char a = s[0];
	int n = s.length();
	FOR(i,1,n,1){
		if(flag && s[i]!= a){
			flag = 0;
			a = s[i];
		}
		else if(!flag && s[i]!= a)return false;
	}
	return true;
}


int main(){
	fast_io;
	cin.tie(NULL);
	int n;
	cin >> n;
	int i = 2;
	int x = n*i;
	bool flag = 0;
	while( x <= 268435455){
		string s = hex(x);
		if(check(s)){
			int l =s.size();
			REP(i,l){
				if(s[i] >= 'a' && s[i] <= 'z'){
					s[i] = toupper(s[i]);
				}					
				cout << s[i];
			}
			cout << endl;
			flag =1;
			break;
		} 
		i++;
		x = n*i;
	}
	if(!flag) cout << "NOTFOUND\n";
	return 0;	
}