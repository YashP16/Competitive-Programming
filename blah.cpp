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
    int t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        ve ctor <ll> a(n);
        REP(i,n){
            cin >> a[i];
        }
        int l=0,r = 0; 
        int count = 0;
        ll p=1;
        
        while(l < n){
            if(r < l)r = l;
            cout << "l: " << l << " p: " << p << '\n';

            while(r < n){
                if(p*a[r] < k){
                    p*=a[r];
                    cout << "r: " << r << " p: " << p << '\n';
                    r++;
                }
                else{
                    break;
                }
            }
            count += r-l;
            if(r-l != 0)
                p /= a[l];
            l++;
        }
    cout << count << "\n";
    }
	return 0;
}