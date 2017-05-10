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
	int n,k;
	cin >> n >> k ;
	int i = 2;
	vector<int> result;
	while (k>0){
		if(n%i == 0 && k > 1 && n/i >= i){
			result.push_back(i);
			k--;
		}
		else if(n%i==0 && k>1 && n/i<i){
			cout << "-1";
			return 0;
		}
		else i++;
	}
	REP(j,result.size())cout << result[i] << " ";
	cout << endl;
	return 0;
}