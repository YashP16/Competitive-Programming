#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int //range -> –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
using namespace std;

int main(){
	int n,m,i,j;
	cin >> n >> m;
	char a[n+2][m+2] ={'.'};
	FOR(i,1,n+1,1){
		FOR(j,1,m+1,1){
			cin >> a[i][j];
		}
	}
	int count =0;
	FOR(i,1,n+1,1){
		FOR(j,1,m+1,1){
			if(a[i][j]=='W'){
				if(a[i-1][j]== 'P' || a[i][j+1]=='P' || a[i][j-1]=='P' || a[i+1][j]=='P'){
					count++;
				}
			}	
		}
	}		
	cout << count;

	return 0;
}