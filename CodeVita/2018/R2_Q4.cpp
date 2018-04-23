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
#define SQR(n) ((n)*(n))
#define MEM(a,val) memset(a,val,sizeof(a))
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, s);
		
		stack <char> l;
		int n =  s.length();
		bool flag = 1;

		REP(i,n){
			if(flag && (s[i]=='(' || s[i]=='[' || s[i]=='{' || s[i]=='(' || s[i]=='/' || s[i] == ' ') ) l.push(s[i]);
			else if(flag && s[i] == '@' && s[i+1] == '*'){
				flag = 0;
				i++;
			}
			else if(!flag && s[i] == '*' && s[i+1] == '@'){
				flag = 1;
				i++;
			}
			else if(!l.empty()){
				if(flag &&((s[i]==')' && l.top() == '(')|| (s[i]==']' && l.top() == '[') || (s[i]=='}' && l.top() == '{') || (s[i]=='\\' && l.top() == '/') || (s[i]==' ' && l.top() == ' '))) l.pop();
			}
			else if(l.empty()){
				if(flag &&(s[i]==')' || s[i]==']' || s[i]=='}' || s[i]=='\\')){
					flag = 0;
					break;
				}
			}
		}
		if(flag && l.empty())cout << "True\n";
		else cout << "False\n";
	}
	return 0;
}