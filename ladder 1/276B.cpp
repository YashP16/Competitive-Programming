#include <iostream>
#include <algorithm>
#include <string.h>
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;

int main(){
	string s;
	cin >> s;
	int a[26] = {0};
	int i;
	FOR(i,0,s.length(),1){
		a[(int)s[i]-(int)'a']++;
	}
	int countodd =0;
	FOR(i,0,26,1){
		if(a[i]%2!=0) countodd++;
	}
	if(countodd%2 == 1 || countodd == 0) cout << "First";
	else cout << "Second";

	return 0;
}