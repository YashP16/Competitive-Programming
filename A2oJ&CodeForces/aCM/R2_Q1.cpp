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

vector <string> st;

bool sortdes(const pair<int,int> &a,const pair<int,int> &b){
    if(a.first >=b.first && st[a.S][0] == '(')return true;
    return false;
}

int main(){
	fast_io;
	int n;
	cin >> n;
	string s;
	int t = 0;
	vector <pair<int,int> >paper;
	
	FOR(j,0,n,1){
		cin >> s;
		st.PB(s);
		int c = 0;
		FOR(i,0,s.length(),1){
			if(s[i]=='(')c++;
			else c--;
		}
		paper.PB({c,j});
		t+=c;
	}
	bool f = 1;
	sort (paper.begin(), paper.end(),sortdes);
	int c = 0;
	REP(i,n){
		string k = st[paper[i].S] ;
		REP(j,k.length()){
			if(k[j]==')')c--;
			else c++;
			if(c<0){
				f = 0;
				break;
			} 
		}
		if(!f)break;
	}
	if(t!=0 || !f)cout << "NO\n";
	else{

		cout << "YES\n";
		REP(i,n)cout << paper[i].S+1 << " ";
		cout << "\n";
	}
	return 0;
}