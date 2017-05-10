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
#define vii vector<vector<ll>>
#define ll long long int //range -> –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	int flag =0;
	REP(i,m){
		int k,c=0;
		cin >> k;
		int v[k];
		REP(j,k){
			cin >> v[j];
		}
		if(k == 1){
			flag = 1;
		}
		else{
			int count = 0;
			int temp = 0;
			while(count < k-2){
				if(find(v+count,v+k,(v[count]*-1))!= v+k){
					temp = 1;
					break;
				}
				count++;
			}
			if(temp == 0) {
				flag = 1;
			}
		
		}
	}
	if(flag == 0) cout << "NO";
	else cout << "YES";
	return 0;
}
