#include <bits/stdc++.h>

#include <sstream>
#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e9)
#define REP(i,n) for(int i=0;i<(n);i++)
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

int stoi(string NumberAsString){
	int NumberAsInteger;
	stringstream ss;
	ss << NumberAsString;
	ss >> NumberAsInteger;
	return NumberAsInteger;
}

int dp(vii set,int n){
	vii table(n,vi(5,0));
	int m = 0;
	REP(i,n){
		REP(j,5){
			if(i==0) table[i][j]=set[i][j];
			else{
				REP(l,i){
					REP(k,5){
						if(set[i][j] > set[l][k]) table[i][j] = max(table[i][j],table[l][k]+set[i][j]);	
					}
				}
			}
			if(m < table[i][j])m = table[i][j];
		}
	}
	return m;
}



int main(){
	int n;
	cin >> n;
	vii set(n,vi(5));
	string s;
	
	REP(i,n){
		cin >> s;
		int pos = 0;
		string temp = "";
		REP(j,5){
			while(s[pos]!= ','&& pos <(int)s.length()){
				temp+= s[pos];
				pos++;
			}
			pos++;		
			set[i][j] = stoi(temp);
			temp = "";
		}	
	}

	cout << dp(set,n) << "\n";
	return 0;
}