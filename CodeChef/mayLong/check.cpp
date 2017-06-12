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
string toBinary(int n)
{
    string r;
    while(n!=0) {r+=(n%2==0 ?"0":"1"); n/=2;}
    return r;
}
int main(){
	int n=0;
	cin >> n;
	while(n--){
		int x;
		cin >> x;
		cout << toBinary(x) << endl;
	}
}