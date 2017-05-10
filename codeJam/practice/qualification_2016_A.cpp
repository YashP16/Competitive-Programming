#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <cstdlib>
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
	int n;
	cin >> n;
	REP(i,n){
		bool c[10]={0};
		int sumc =0;
		int t;
		cin >> t;
		if(t == 0) cout <<"Case #"<< i+1 << ":"<< " INSOMNIA" << endl; 
		else{
			int count = 1;
			int x;
			while(sumc!= 10){
				x = t*count;
				string s = to_string(x);
				FOR(j,0,s.length(),1){
					if(c[s[j]-'0']==0){
						c[s[j]-'0']=1;
						sumc++;
					}
				}
				count++;
			}
			cout << "Case #"<< i+1 << ": "<< x << endl; 
		}
	} 
	return 0;
}