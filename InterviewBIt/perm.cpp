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

vector<int>findPerm(const string A, int B) {
    vector <int> res;
    int n = A.length();
    int big = B;
    int x=0;
    int small = 1;
    int i = 0;
    bool flag =1;
    while(i<n){
        x=0;
        while(A[i]==A[i+x]){
            x++;
        }
        if(i == 0){
        	if(A[0]=='D'){
        		res.push_back(big);
        		big--;
        	}
        	else{
        		res.push_back(small);
        		small++;
        	}
        	flag =0;
        }
        if(A[i]=='D'){
            int y = small+x-1;
            while(y>=small){
                res.push_back(y);
                y--;
            }
            small = small+x; 
        }
        else{
            int y = big-x+1;
            while(y<=big){
                res.push_back(y);
                y++;
            }
            big = big - x;
        }
        i+= x;
    }
    if(flag)res.push_back(small);
    return res;
}

int main(){
	fast_io;
	int n;
	string s;
	cin >> s;
	cin >> n;
	findPerm(s,n);
	return 0;
}