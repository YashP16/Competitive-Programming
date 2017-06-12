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
	string s;
	cin >> s;
	int len = s.length();
	int p = -1;
	REP(i,len-1){
		if((int)(s[i]-'0') %2 == 0){
			if(s[i]<s[len-1]){
				swap(s[i],s[len-1]);
				p = len;
				break;
			}
			else{
				p = i;
			}
		}
	}
	if(p== len)cout << s << endl;
	else if(p!=-1){
		swap(s[p],s[len-1]);
		cout << s;
	}
	else cout << -1;
	
	return 0;
}