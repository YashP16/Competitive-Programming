#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(ll i=a;i<b;i += c)
#define FORd(i,a,b,c) for(ll i=a;i>=b;i -=c)
#define vi vector<ll>
#define vii vector<vector<ll> >
#define ll long long int //range -> –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
using namespace std;

bool sortdes(char a,char b){
    if(a>b)return true;
    else return false;
}

int main(){
	string s;
	string t;
	cin >> s >> t;
	sort(s.begin(),s.end());
	sort(t.begin(),t.end(),sortdes);
	string name = "";
	int counter = 0;
	int n = s.length();
	
	FOR(i,0,n,1){
		if(i%2 ==1){
			name += t[counter];
			counter++;
		}
		else{
			name += s[counter];
			
		}
	} 
	cout << name << endl;
}