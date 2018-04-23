#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
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

vector <bool> prime(2001,1);

void sieve(int n){
	prime[0]=0;
	prime[1]=0;
    for (int p=2; p*p<=n; p++){
        if (prime[p] == true){
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
}


int main(){
	sieve(2001);
	
	int t;
	cin >> t;
	
	while(t--){
		string s;
		cin >> s;
		int n = s.length();

		int minBase = 2;
		char maxChar = max(s[0],s[1]);
		
		if(maxChar>= 'A') minBase = 10 + maxChar - 'A' + 1; 
		else minBase = (int)(maxChar - '0') +1 ;
		vi res;
		
		FOR(i,minBase,37,1){
			long n = strtol(s.c_str(),NULL,i);
			if(prime[n]) res.PB(i);	
		}
		
		if(res.empty())cout << "NONE";
		else{
			int x = res.size();
			REP(i,x){
				cout << res[i] ;
				if(i!= x-1) cout << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}