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



int main(){
	fast_io;
	cin.tie(NULL);
	string s;
	cin >> s;
	string rev ="";
	rev += s[1] + s[0];
	int a =((int)(s[0]-'0'))*10+((int)(s[1]-'0')); 
	int m = ((int)(s[3]-'0'))*10+((int)(s[4]-'0'));
	int n = ((int)(s[1]-'0'))*10+((int)(s[0]-'0'));
	int j = ((int)(s[1]-'0')+1)*10+((int)(s[0]-'0'));
	if((int)s[1]-'0'<=5 && !(s[0]=='2' && s[1]=='3')  &&(!(s[1]=='5' && (s[3]=='5' && (s[4]>'0' && s[4]!=s[0]))))){
		if(s[3]<s[1]){
			cout <<  n - m  << endl;
		}
		else if(s[3]==s[1] && (s[4]<=s[0]))
			if(s[0]!=s[4])cout << (int)(s[0]-'0') -(int)(s[4]-'0') << endl;
			else cout << (int)(s[0]-'0') -(int)(s[4]-'0') << endl;
		else {
			cout << 60 - m + j  << endl;
		} 			
	}
	else{
		if(s[0]=='0'){
			cout <<  60-m + (10-a-1)*60  + 1<< endl;
		}
		else if((s[0]=='2' && s[1]=='3')){
			if(m>n)cout << 60-m+(24-a-1)*60 << endl;
			else cout << n-m << endl;
		}
		else {
			cout << 60-m+(20-a-1)*60 + 2<< endl;

		}
	}

	return 0;
}