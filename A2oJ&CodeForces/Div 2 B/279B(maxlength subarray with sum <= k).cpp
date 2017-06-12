// function to find max length subarray with sum <= k

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

int mlength(int *v,int n, int k){
    int start = 0;
    int end = 0;
    int sum = 0;
    int max_len = -1; 
    FOR(i,0,n,1){
        sum += v[i];
        end += 1;
        while (sum>k){
            sum -= v[start];
            start++;
        }
        max_len = max(max_len,end -start);
	}
    return max_len;
}
int main(){
	int n,k;
	cin >> n >> k;
	int v[n];
	REP(i,n)cin >> v[i];
	cout << mlength(v,n,k) << "\n";
	return 0;
}