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

	vii tree(n+1);
	vi c(n+1);
	
	REP(i,n-1){
		int parent;
		cin >> parent;
		tree[parent].PB(i+2);
	}
	
	REP(i,n)cin >> c[i+1];
	
	vi curr(n+1,0);
	int count=0;
	
	FOR(i,1,n+1,1){
		if(c[i]!=curr[i]){
			stack <int> s;
			s.push(i);
			count++;
			curr[i]=c[i];
			while(!s.empty()){
				int t = s.top();s.pop();
				for(int j=0;j<tree[t].size();j++){
					s.push(tree[t][j]);
					curr[tree[t][j]]=c[i];
				}
			}
		}

	}
	
	cout << count << "\n";
}