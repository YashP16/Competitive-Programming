#include <bits/stdc++.h>

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e9)
#define REP(i,n) for(int i=0;i<(n);i++)
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,p,q,r;
	int m = 1000000007;
	cin >> t;
	while(t--){
		cin >> p >> q >> r;
		ll a[p],b[q],c[r], psa=0,psc=0;
		
		REP(i,p){
			cin >> a[i];
			psa += a[i];
		}
		REP(j,q)cin >> b[j];
		REP(k,r){
			cin >> c[k];
			psc+= c[k];
		}
		
		sort (a,a+p);
		sort(b,b+q);
		sort (c,c+r);

		int apos=p-1,cpos=r-1;
		ll sum=0;
		
		FORd(i,q-1,0,1){
			while(b[i]<a[apos] && psa>0){
				psa -= a[apos];
				apos--;
			}

			while(b[i]<c[cpos] && psc>0){
				psc -= c[cpos];
				cpos--;
			}

			if(apos!=-1 && cpos !=-1 )sum = (sum + ( (  (psa%m) + ( ( (apos+1) * b[i]) %m ) ) * ( (psc%m) + (( (cpos+1) * b[i])%m) ) ) )%m; 
			else break;
		}

		cout << sum << endl;

	}			
	return 0;
}