// Given a matrix of size n x m  calculate the size of the maximum sub array with all 1s 

#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define vi vector<ll>
#define vii vector<vector<ll> >
#define ll long long int //range -> –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	int matrix[n][m];
	REP(i,n){
		REP(j,m){
			cin >> matrix[i][j];
		}
	}
	int max=0;
	int table[n][m];

	REP(i,n){
		REP(j,m){
			if(i == 0 || j ==0){
				table[i][j]=matrix[i][j];
			}
			else if(matrix[i][j] == 0) table[i][j] = 0;
			else{
				table[i][j] = min(min(table[i-1][j],table[i-1][j-1]),table[i][j-1]) +1;
			}
			if(max < table[i][j]) max = table[i][j];
		}
	}
	cout << max << endl;

	return 0;
}
