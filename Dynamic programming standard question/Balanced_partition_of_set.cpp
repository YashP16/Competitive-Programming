#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(int i=a;i<b;i += c)
#define FORd(i,a,b,c) for(int i=a;i>=b;i -=c)
#define vi vector<ll>
#define vii vector<vector<ll> >
#define ll long long int //range -> –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
using namespace std;


int main(){
	int n;
	cin >> n;
	int set[n];
	int m = 0;
	REP(i,n){ 
		cin >> set[i];
		m += set[i];
	}
	int table[n+1][m+1]={0};
	FOR(i,0,n+1,1){
		FOR(j,0,m+1,1){
			if(j==0)table[i][j]=1;
			else if(i==0 && j!= 0) table[i][j]=0; 
			else{
				if(j - set[i-1] < 0) table[i][j]= table[i-1][j];
				else table[i][j]=max(table[i-1][j],table[i-1][j-set[i-1]]);
			}
		}
	}
	REP(i,n+1){
		REP(j,m+1){
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}