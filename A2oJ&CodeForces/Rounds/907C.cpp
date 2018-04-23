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
	vi chk(26,0);
	char c;
	string s; 
	int count = 0;
	int shock = 0;
	FOR(i,0,n,1){
		cin >> c >> s;
		if(i == 0){
			if(c =='.'){
				REP(j,s.length()) chk[s[j]-'a'] = -1;
			}
			else if(c == '!'){
				REP(j,s.length()){
					if(chk[s[j]-'a']==0)count++;
					chk[s[j]-'a'] = 1;	
				}
			}
			else{
				if(n==1){
					cout << 0 << "\n";
					return 0;
				}
				else{
					if(chk[s[0]-'a']==1)count--;
					chk[s[0]-'a']=-1;
				}
			}
		}
		else{
			if(c =='.'){
				REP(j,s.length()){
					if(chk[s[j]-'a'] == 1) count--;
					chk[s[j]-'a'] = -1;
				}
			}
			else if(c == '!'){
				if(count==1)shock++;
				else{
					REP(j,26){
						bool f = 0;
						REP(k,s.length()){
							if(s[k]-'a' == j){
								f = 1;
								if(chk[j]== 0) chk[j]=-1;
							} 
						}
						if(!f){
							if(chk[j]==1)count--;
							chk[j]=-1; 
						}

					}
				}
			}
			else if(i==n-1 && c == '?'){
				cout << shock << "\n";
				return 0;
			}
			else if(count ==1 && c == '?'){
				if(chk[s[0]-'a']==1)count--;
				chk[s[0]-'a']=-1;
				shock++;
			}
		}
		/*cout << count <<  " " << shock << " ";
		REP(k,26)cout << chk[k] << " ";
		cout << "\n";
*/
	}	 

	return 0;
}