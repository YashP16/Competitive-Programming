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

void editDistance(string s1, string s2){
	int table[s1.length()+1][s2.length()+1] = {0};
	FOR(i,0,s1.length()+1,1){
		FOR(j,0,s2.length()+1,1){
			if(i == 0){
				table[i][j]=j;
			}
			else if(j== 0 && i > 0){
				table[i][j]= i;
			}

			else{
				if(s1[i-1] == s2[j-1]){
					table[i][j] = table[i-1][j-1];
				}
				else{
					table[i][j]= min(min(table[i-1][j],table[i][j-1]), table[i-1][j-1]) + 1;
				}
			}
		}
	}
	cout << table[s1.length()][s2.length()] << endl;
}

int main(){
	string s1,s2;
	cin >> s1 >> s2;
	editDistance(s1,s2);
	return 0;
}