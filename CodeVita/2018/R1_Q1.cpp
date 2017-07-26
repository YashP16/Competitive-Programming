#include <bits/stdc++.h>

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e9)
#define REP(i,n) for(int i=0;i<(n);i++)
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

void count(vi perm,vi shuffles,vi &err,int n){
	REP(i,n){
		if(perm[i]!=shuffles[i])err.PB(i);
	}
}

int main(){
	fast_io;
	cin.tie(NULL);
	int n;
	cin >> n;
	vi perm(n);
	REP(i,n) cin >> perm[i];
	vi cards(n);
	REP(i,n) cards[i] = i+1;
	vii shuffles(8);
	
	REP(i,8){
		int ed = 0;
		int od = n/2;
		FOR(j,0,n,1){
			if(i == 0){
				if(j%2==0){
					shuffles[i].PB(cards[ed]);
					ed++;
				}
				else{
					shuffles[i].PB(cards[od]);
					od++;
				}
			}
			else{
				if(j%2==0){
					shuffles[i].PB(shuffles[i-1][ed]);
					ed++;
				}
				else{
					shuffles[i].PB(shuffles[i-1][od]);
					od++;
				}
			}
		}
	}
	vii err(8);
	REP(i,8){
		count(perm,shuffles[i],err[i],n);
		if(err[i].size()/2 == 0){
			cout << i+1 << "\nNONE";
			break;
		}

		else if(err[i].size()/2 <= i+1){
			
		}
	}

	return 0;
}