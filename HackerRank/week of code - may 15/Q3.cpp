#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stack>
#include <limits>
#include <vector>
#include <sstream>
#include <queue>
#include <utility> // for pair
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(int i=a;i<b;i += c)
#define FORd(i,a,b,c) for(int i=a;i>=b;i -=c)
#define vi vector<ll>
#define vii vector<vector<ll> >
#define ll long long int //range -> 9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
#define PB push_back
#define sz size()
#define InF  2147483647
using namespace std;
bool ck(int n,int s,int t,int r){
	if(s+r < n){
		if(t>s && t<=s+r){
			return true;
		}
	}
	else if(s+r >=n){
		if((t>s && t<=n-1)|| (t<=(s+r)%n))return true;	
	}
	if(s-r>=0){
		if(t<s&& t >= s-r)return true;
	}
	else if(s-r < 0){
		if ((t<s && t>= 0)|| (t >= (s-r)+n))return true;
	}
	return false;
}

int main(){
	int n,s,g,seed,t,p;
	cin >> n >> s >> t ;
	int *R;
	R = new int[n];
	cin >> R[0] >> g >> seed >> p;

	FOR(i,1,n,1){
		R[i]= ((R[i-1]* g) + seed) % p;
	}
	if(s!= t){
		queue <int> q;
		q.push(s);
		bool check[n]={0};
		int dist[n]={0};
		fill_n(dist,n,InF);
		check[q.front()]=1;
		dist[q.front()]=0;
		while(!q.empty()){
			if( ck(n,q.front(),t,R[q.front()] ) ){
				dist[t] = dist[q.front()] +1;
				break;
			}
			else {
				if(R[q.front()]!= 0){
					FOR(i,q.front()+1,q.front()+R[q.front()]+1,1){
						if(check[i%n]==0){
							q.push(i%n);
							dist[i%n] = dist[q.front()] +1;
							check[i%n]=1;
						}
					}
					FORd(i,q.front()-1,q.front()-R[q.front()],1){
						if(check[(n+i)%n]==0){
							q.push((n+i)%n);
							dist[(n+i)%n] = dist[q.front()] +1;
							check[(n+i)%n]=1;
						}	
					}
				}
			}
			
			if(dist[t]!=InF)break;
			q.pop();
		}
		if(dist[t] == InF){
			cout << "-1\n";
		}
		else cout << dist[t] << endl;
	}
	else if(R[0] == 0 && s!= t) cout << "-1\n";
	else if(s == t )cout << "0\n";
}