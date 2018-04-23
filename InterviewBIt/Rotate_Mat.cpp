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
#define sz size()
#define InF  2147483647
#define READ freopen("input.txt", "r", stdin);
#define WRITE freopen("output.txt", "w", stdout);
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define SQR(n) ((n)*(n))
#define MEM(a,val) memset(a,val,sizeof(a))
using namespace std;

void rotate(vector<vector<int> > &A) {
    int n = A.size();
    int num_layer = n/2;
    int temp;
    int l = 0;   
    int count = 1;
    while(count<n){
        l = 0;
        while(l<num_layer && l+count1<n){
            int a=l,b=l+1;
            temp = A[a][b-1];
            while(b<=n-l-1){
                swap(temp,A[a][b]);
                b++;
            }
            b--;
            a++;
            while(a<=n-l-1){
                swap(temp,A[a][b]);
                a++;
            }
            a--;
            b--;
            while(b>l){
                swap(temp,A[a][b]);
                b--;
            }
    
            while(a>=l){
                swap(temp,A[a][b]);
                a--;
            }
           
            l++;   
        }
        
        count++;
    }
    REP(i,n){
    	REP(j,n) cout << A[i][j] << " ";
    	cout << "\n";
    }
    return;
}


int main(){
	int n;
	cin >> n;
	vii A(n,vi(n));
	REP(i,n)REP(j,n)cin >> A[i][j];
	rotate(A);
	return 0;
}