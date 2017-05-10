#include <iostream>
#include <algorithm>
#include <string.h>
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;

int main(){
	int a1[26]={0};
	int a2[26]={0};

	string s1,s2;
	cin >> s1 >> s2;

	int i;
	if(s1.length()!= s2.length()){
		cout << "NO";
		return 0;
	}
	int count =0;
	FOR(i,0,s1.length(),1){
		if(s1[i]!= s2[i])count++;
		a1[(int)s1[i]-'a']++;
		a2[(int)s2[i]-'a']++;
		if(count > 2) break;
	}

	if(equal(a1,a1+26,a2) && count <=2) cout << "YES";
	else cout << "NO";

	return 0;
}