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

bool inDict(int n,string dict[],string s){
	FOR(i,0,n,1){
		if(s==dict[i])return true;
	}
	return false;
}

bool isBreakable(int n,string s, string dict[]){
	int len = s.length();
	vector<bool> v(len,0);
	FOR(i,0,len,1){
		if(inDict(n,dict,s.substr(0,i+1)))v[i]=1;
		if(v[i] && i==len-1)return true;
		if(v[i]){
			FOR(j,i+1,len,1){
				if(inDict(n,dict,s.substr(i+1,j-i)))v[j]=1;
				if(v[j] && j == len-1)return true;
			}
		}
	}
	REP(i,len)cout << v[i] << " ";
	cout << endl << endl;
	return false;
}


int main(){
	fast_io;
	cin.tie(NULL);

	int n;
	cin >> n;
	string dict[n],s;
	REP(i,n)cin >> dict[i];
	cin >> s;

	cout << isBreakable(n,s,dict) << "\n";


	return 0;

}