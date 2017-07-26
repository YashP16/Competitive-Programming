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

bool sa(pair<ll,bool> &a,pair<ll,bool> &b){
    return a.F>b.F;
}


int main(){
    fast_io;
    cin.tie(NULL);
    int t,n,m;
    int mod = 1000000007;
    cin >> t;
    
    while(t--){
        cin >> m >> n;
        vector < pair <ll,bool> > x;
        int p = 0;
        REP(i,m-1){
            cin >> p;
            x.PB(make_pair(p,1));
        }
        REP(i,n-1){
            cin >> p;
            x.PB(make_pair(p,0));
        }
        
        ll xp = 1,yp = 1;
        ll total =0;
        sort(x.begin(),x.end(),sa);
        
        int pos = 0;
        while(pos < m+n-2){
            if(x[pos].S){
                total = (total + xp*x[pos].F)%mod;
                yp++;
            }
            else{
                total = (total + yp*x[pos].F)%mod;
                xp++;
            }
            pos++;
        }
        
        cout << total << "\n";
        
    }
    return 0;
}