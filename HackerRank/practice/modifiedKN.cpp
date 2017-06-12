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

bool isKaprekar(ll n){
    if(n == 1) return true;
    ll sq = n*n;
    cout << sq << endl;
    string s = to_string(sq);
    if(s.length() > 1){
        string l = s.substr(0,s.length()/2);
        string r = s.substr(s.length()/2);
        int a = stoi(l);
        int b = stoi(r);

        if(a+b == n)return true;
        return false;
    }
    return false;
}

int main(){
    fast_io;
    cin.tie(NULL);
    int p,q;
    cin >> p >> q;
    bool flag = 0;
    FOR(i,p,q+1,1){
        if(isKaprekar(i)){
            flag = 1;
            cout << i << " ";
        }
    }

    if(!flag)cout << "INVALID RANGE\n";
    else cout << "\n";
    return 0;
}