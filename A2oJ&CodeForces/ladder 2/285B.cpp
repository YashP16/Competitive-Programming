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
	int n,s,t,i;
	cin >> n >> s >>  t;
	int p[n+1];
	FOR(i,1,n+1,1){
		cin>>p[i];
	}
	int count =0;
	if(s==t){
		cout <<count;
		return 0;
	}
	i =s;
	int flag = 1;
	while(i !=t){
		if(flag==1 && (p[i]==s) || (p[i] == i)){
			flag =0;
			break;
		}
		else{
			i = p[i];
			count++;
		}
	}
	if(flag ==0)cout << -1;
	else cout << count;

	
	
	return 0;
}