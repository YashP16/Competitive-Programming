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

void func(int n,int m,vii &field){
	vbb visited(n,vb(m,0));
	vi troops;
	REP(i,n){
		REP(j,m){
			if(!visited[i][j]){
				visited[i][j]=1;
				if(field[i][j]==1){
					queue <pair <int,int> > Q;
					Q.push(make_pair(i,j));
					int c = 1;
					while(!Q.empty()){
						pair <int,int>f = Q.front();
						if(f.F-1>=0){
							if(!visited[f.F-1][f.S] && field[f.F-1][f.S]==1){
								Q.push(make_pair(f.F-1,f.S));
								c++;
							}
							visited[f.F-1][f.S]=1;

							if(f.S-1>=0){
								if(!visited[f.F-1][f.S-1]&& field[f.F-1][f.S-1]==1){
									Q.push(make_pair(f.F-1,f.S-1));
									c++;
								}
								visited[f.F-1][f.S-1]=1;
							
							}
							if(f.S+1<m){
								if(!visited[f.F-1][f.S+1] && field[f.F-1][f.S+1]==1){
									Q.push(make_pair(f.F-1,f.S+1));
									c++;
								}
								visited[f.F-1][f.S+1]=1;
							}
						}
						if(f.F+1<n){
							if(!visited[f.F+1][f.S] && field[f.F+1][f.S]==1 ){
								Q.push(make_pair(f.F+1,f.S));
								c++;
							}
							visited[f.F+1][f.S]=1;
							
							if(f.S-1>=0){
								if(!visited[f.F+1][f.S-1]&& field[f.F+1][f.S-1]==1){
									Q.push(make_pair(f.F+1,f.S-1));
									c++;
								}
								visited[f.F+1][f.S-1]=1;
							}
							
							if(f.S+1<m){
								if(!visited[f.F+1][f.S+1]&& field[f.F+1][f.S+1]==1){
									Q.push(make_pair(f.F+1,f.S+1));
									c++;
								}
								visited[f.F+1][f.S+1]=1;
							}
						}
						if(f.S-1>=0){
							if(!visited[f.F][f.S-1]&& field[f.F][f.S-1]==1){
								Q.push(make_pair(f.F,f.S-1));
								c++;
							}
							visited[f.F][f.S-1] = 1;
						}
						if(f.S+1<m){
							if(!visited[f.F][f.S+1]&& field[f.F][f.S+1]==1){
								Q.push(make_pair(f.F,f.S+1));
								c++;
							}
							visited[f.F][f.S+1] = 1;
						}
						Q.pop();

					}
					troops.PB(c);
				}
			}
		}

	}
	if (troops.size() == 0) cout << 0 << " " << 0 << "\n";
	else cout << troops.size() << " " << *max_element(troops.begin(), troops.end()) << "\n";
}



int main(){
	fast_io;
	int t;
	cin >>t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vii field(n,vi(m));
		REP(i,n){
			REP(j,m){
				cin >> field[i][j];
			}
		}
		func(n,m,field);
 	}
	return 0;
}