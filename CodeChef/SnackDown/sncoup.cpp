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
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s[2];
		cin >> s[0] >> s[1];
		int c[n];
		int count =0;
		int mid =0;
		char status = '!';
		REP(i,n){
			if(s[0][i]=='*'&&s[1][i]=='*')mid =1;
		}
		bool flag =0;
		if(mid == 1){
			count = 1;
			REP(i,n){
				if(flag == 1){
					i--;
					flag =0;
				}
				if(status == '!'){
					if(s[0][i]=='*'&&s[1][i]=='*')status='3';
					else if(s[0][i]=='*')status = '1';
					else if(s[1][i]=='*')status = '2';
					i++;

				}
				if((status == '1' && s[1][i]=='*' && s[0][i]!='*') || (status == '2' && s[0][i]=='*' && s[1][i]!='*'))status == '3';
		
				else if(((status == '1' || status == '3' && s[0][i] == '*') || (status == '2' || status == '3' && s[1][i] == '*'))&& i<n){
					status = '!';
					count++;
					flag =1;
				}
			}
		}
		else{
			REP(i,n){
				if(flag == 1){
					i--;
					flag =0;
				}
				if(status == '!'){
					if(s[0][i]=='*')status = '1';
					else if(s[1][i]=='*')status = '2';
					i++;

				}
				if(status == '1' || status == '2' && (s[0][i] == '*' || s[1][i] == '*') && i<n){
					status = '!';
					count++;
					flag =1;
				}
			}
		}
		cout << count << endl;
	}	
	return 0;
}