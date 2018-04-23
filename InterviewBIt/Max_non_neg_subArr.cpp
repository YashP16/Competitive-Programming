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

vector<int> maxset(vector<int> &A) {
    int mlength = 0;
    int templength = 0; 
    int msum = 0;
    int currsum = 0;
    int idx = 0;
    int n = A.size();
    for(int i = 0; i < n; i++){
        if(A[i]< 0){
            if(currsum > msum){
                idx = i - templength;
                msum = currsum;
                mlength = templength;
            }
            else if(currsum == msum && templength>mlength){
                idx = i - templength;
                mlength = templength;
            }
            currsum = 0;
            templength = 0;
        }
        else{
            currsum += A[i];
            templength++;
            
            if(currsum > msum){
                idx = i - templength;
                msum = currsum;
                mlength = templength;
            }
            else if(currsum == msum && templength>mlength){
                idx = i - templength;
                mlength = templength;
            }
            
        }
        
        
        
    }
    vector <int> res(A.begin()+idx,A.begin()+idx+mlength);
    return res;
    
}

int main(){
    fast_io;
    int n;
    cin >> n;
    vi A(n);
    REP(i,n)cin >> A[i];
    
    cout << maxset(A);

    
    return 0;
}

