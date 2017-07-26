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
	int n,m,k;
	cin >> n >> m >> k;
	int s = (n*m)/k;
	int rem;
	vector < vector < pair <int,int> >  > tubes(k);

	int count = 0;
	int i =0,j = 0;
	bool flag = 0;
	while(count <k){
		
		if(count ==0)rem =  (n*m)%k;
		else rem = 0;

		int c = s+rem;
		while(c!= 0){
			if(!flag){
				tubes[count].PB(make_pair(i+1,j+1));
				c--;
				j++;
				if(j == m){
					i++;
					j--;
					flag = 1;
				}
			}
			else{
				tubes[count].PB(make_pair(i+1,j+1));
				c--;
				j--;
				if(j == -1){
					i++;
					j++;
					flag = 0;
				}	
			}
		}
		count++;
	} 

	REP(l,k){
		cout << tubes[l].size() << " ";
		REP(x,tubes[l].size())cout << tubes[l][x].F << " " << tubes[l][x].S << " "  ;
		cout << "\n";
	}

	return 0;
}