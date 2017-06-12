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

string toBinary(int n){
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    int x = r.length();
    string temp = "";
    while(x < 20){
    	temp+= '0';
    	x++;
    }
    temp += r;
    return temp;
}

bool comp(string s,string x,int k){
	int maxLen = max(s.length(),x.length());
	int count =0;
	while(count < maxLen){
		if(s[19-count] != x[19-count]) k--;
		count++;
	}
	if(k< 0)return false;
	else return true;	
}

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	int x[m+1];
	string y[m+1];
	FOR(i,0,m+1,1){
		cin >> x[i];
		y[i]=toBinary(x[i]);
	}
	int count = 0;
 	REP(i,m){
 		if(comp(y[i],y[m],k)) count++;
 	}
 	cout << count << endl;

	return 0;
}

