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

int dx [] = {1,2,3,4,5,6};
int func(vi &mat){
	vi dice(101,MAX);
	queue <int> Q;
	Q.push(1);
	dice[1]=0;
	while(!Q.empty()){
		int f = Q.front();Q.pop();
		FOR(i,0,6,1){
			int t =f+dx[i]; 
			if(f+dx[i]<101 && dice[t+mat[t]] > dice[f]+1){
				Q.push(t+mat[t]);
				dice[t+mat[t]]= dice[f]+1;
			}
			if(t + mat[t]== 100)return dice[100];
		}
	}
	return -1;
}

int main(){
	fast_io;
	int t;
	cin >> t;
	while(t--){		
		vi mat(101,0);
		int l,s,a,b;
		cin >> l;
		REP(i,l){
			cin >> a >> b;
			mat[a] = b-a;
		}
		cin >> s;
		REP(i,s){
			cin >> a >> b;
			mat[a] = b-a;
		}
		cout << func(mat) << "\n";
	}	
	return 0;
}