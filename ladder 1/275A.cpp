#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <utility> // for pair
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;

int main(){
	int i,j;
	vector < vector<bool> > l(5,vector <bool> (5,1));
	int m[3][3];
	FOR(i,0,3,1){
		FOR(j,0,3,1){
			cin >> m[i][j];
			if(m[i][j]%2 != 0){
				l[i+1][j+1]= 1-l[i+1][j+1];
				l[i][j+1] =1-l[i][j+1];
				l[i+1][j+2] = 1-l[i+1][j+2];
				l[i+1][j] = 1-l[i+1][j];
				l[i+2][j+1] = 1-l[i+2][j+1]; 
			}
		}
	}
	FOR(i,1,4,1){
		FOR(j,1,4,1){
			cout << l[i][j];
		}
		cout << endl;
	}	
			
	return 0;
}