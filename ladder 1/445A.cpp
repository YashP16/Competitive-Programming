#include <iostream>
#include <algorithm>
#include <string.h>
# define FOR(i,a,b,c) for(i=a;i<b;i += c)
using namespace std;
int main(){
	int n,m;
	cin >> n >> m;
	char a[n][m];
	int i,j;
	FOR(i,0,n,1){
		FOR(j,0,m,1){
			cin >> a[i][j];
			if(a[i][j] == '.'){
				if((i+j)%2 == 0) a[i][j] = 'B';
				else a[i][j]='W';
			}
		}
	}
	FOR(i,0,n,1){
		FOR(j,0,m,1){
			cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
}