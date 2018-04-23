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
#define MP make_pair
#define sz size()
#define InF  2147483647
#define READ freopen("input.txt", "r", stdin);
#define WRITE freopen("output.txt", "w", stdout);
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define SQR(n) ((n)*(n))
#define MEM(a,val) memset(a,val,sizeof(a))
using namespace std;

int calc(int a,int b,vii &diagonal,vii &diagonal2){
	return 0;
}


int main(){
	fast_io;
	int t;
	cin >> t;
	while(t--){
		int m,n;
		cin >> m >> n;
		vii weight(m,vi(n)); 
		REP(i,m)REP(j,n) cin >> weight[i][j];
		vii diagonal;

		FORd(i,m-1,0,1){
			vi temp;
			temp.PB(weight[i][0]);
			int k = i+1;
			int j = 1;
			while(k<m && j<n){
				temp.PB(temp[j-1]+weight[k][j]);
				j++;
				k++;
			}
			diagonal.PB(temp);
		}
		FOR(j,1,n,1){
			vi temp(1);
			temp[0]=weight[0][j];
			int i = 1,k=j+1; 
			while(i<m && k<n){
				temp.PB(temp[i-1]+weight[i][k]);
				k++;
				i++;
			}
			diagonal.PB(temp);	
		}
		cout << "Dsum: \n";
		REP(i,diagonal.size()){
			REP(j,diagonal[i].size()){
				cout << diagonal[i][j] << " ";
			}
			cout << "\n";
		}
		vii diagonal2;
		FORd(j,n-1,0,1){
			vi temp;
			temp.PB(weight[0][j]);
			int k = j-1 ,i=1;
			while(k>=0 && i<m){
				temp.PB(temp[i-1]+weight[i][k]);
				k--;
				i++;
			}
			diagonal2.PB(temp);
		}
		reverse(diagonal2.begin(), diagonal2.end());
		FOR(i,1,m,1){
			vi temp;
			temp.PB(weight[i][n-1]);
			int k = i+1, j = n-1;
			while(k<m&&j>0){
				temp.PB(temp[k-2]+weight[k][j]);
				k++;
				j--;
			}
			diagonal2.PB(temp);
		}
		cout << "D2sum: \n";
		REP(i,diagonal2.size()){
			REP(j,diagonal2[i].size()){
				cout << diagonal2[i][j] << " ";
			}
			cout << "\n";
		}
		int maxi = -1* MAX;
		/*FOR(i,1,m-1,1){
			FOR(j,1,n-1,1){
				int crosswt = calc(i,j,diagonal,diagonal2);
				maxi = max(maxi,crosswt);
			}	
		}
		cout << maxi << "\n";*/
	}	
	return 0;
}