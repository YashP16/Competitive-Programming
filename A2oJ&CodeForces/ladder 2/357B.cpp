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
	int n,m;
	cin >> n >> m;
	int a[n+1] = {0};
	int d[m][3];
	FOR(i,0,m,1){
		FOR(j,0,3,1){
			cin >> d[i][j];
		}	
	}
	int counter = 0;
	FOR(i,0,m,1){
		FOR(j,0,3,1){
			d[i][j];
			if(i == 0){
				a[d[i][j]] = ++counter;
			}
		}	
	}

	FOR(i,1,m,1){
		counter = 1;
		int flag = 0;
		int pos=0;
		FOR(j,0,3,1){
			if(a[d[i][j]]!=0){
				flag = a[d[i][j]];
				pos = j;
				break;
			}
		}
		if(flag!= 0){
			FOR(j,0,3,1){
				if(j!= pos){
					if(counter != flag){
						a[d[i][j]] = counter++;
					}
					else{
						a[d[i][j]] = ++counter;
						flag = a[d[i][j]];
					}
				}	
			}
		}
		else{
			FOR(j,0,3,1){
				a[d[i][j]]=counter++;
			}
		}
	}

	FOR(i,1,n+1,1){
		cout << a[i] << " ";
	}

	return 0;
}