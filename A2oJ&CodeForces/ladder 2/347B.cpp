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
	int n,i;
	cin >> n;
	int a[n];
	int count =0; 
	int flag =0;
	REP(i,n){
		cin >> a[i];
	}
	REP(i,n){
		if(a[i]==i)count++;
		else if(flag == 0 && a[a[i]] == i){
			flag =1;
			count += 2;
		}
	}
	if(flag == 1)cout << count;
	else if(count !=n && flag !=1)cout << count +1;
	else cout << count;
	return 0;
}