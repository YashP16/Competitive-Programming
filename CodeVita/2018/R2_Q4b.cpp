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
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, s);
		
		/*stack <char> l;*/
		int n =  s.length();
		bool flag = 1;
		int rbrak = 0;
		int sqbrak = 0;
		int cbrak = 0;
		int slash = 0;
		int space = 0;
		bool of = 1;
		

		REP(i,n){
			if(flag){
				if(s[i]=='('){
					rbrak++;		
				}
				else if(s[i]=='['){
					sqbrak++;
				}
				else if(s[i]=='/'){
					slash++;
				}
				else if(s[i]==' '){
					space++;
				}
				else if(s[i]=='{'){
					cbrak++;
				}

				else if(s[i]==')'){
					rbrak--;		
					if(rbrak <0){
						of = 0;
						break;
					}
				}
				else if(s[i]==']'){
					sqbrak--;
					if(sqbrak <0){
						of = 0;
						break;
					}
				}
				else if(s[i]=='\\'){
					slash--;
					if(slash <0){
						of = 0;
						break;
					}
				}
	
				else if(s[i]=='}'){
					cbrak--;
					if(cbrak <0){
						of = 0;
						break;
					}
				}
				else if(flag && s[i] == '@' && s[i+1] == '*'){
					flag = 0;
					int pos =i;
					FOR(j,i+1,n,1){
						if(s[j]=='*'&&s[j+1]=='@') pos = j; 
					}
					i = pos-1;
				}	
			}
			else if(!flag && s[i] == '*' && s[i+1] == '@'){
				flag = 1;
				i++;
			}

		}

		if(of && rbrak == 0 && cbrak == 0 && slash == 0 && sqbrak == 0 && space % 2 == 0)cout << "True\n";
		else cout << "False\n";
	}
	return 0;
}