#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;

int main(){
	ll n;
	cin >> n;
	vector < vector<int> > c(5001,vector <int> (1,-1));
	int i;
	int d;	
	FOR(i,0,2*n,1){
		cin >> d;
		if(c[d][0]!=-1)c[d].push_back(i);
		else(c[d][0] = i);
	}
	FOR(i,1,5001,1){
		if(c[i][0]!=-1){
			if(c[i].size()%2 !=0) {
				cout << -1;
				return 0;
			}
		}
	}
	int j;
	FOR(i,1,5001,1){
		if(c[i][0]!=-1){
			FOR(j,0,c[i].size(),2){
				cout << c[i][j]+1 << " " <<c[i][j+1]+1<<endl;
				c[i][j] = c[i][j+1]=-1;
			}
		}
	}
	return 0;
}