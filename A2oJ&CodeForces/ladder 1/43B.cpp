#include <iostream>
#include <algorithm>
#include <string.h>
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;

int main(){
	int a1[52]={0};
	int a2[52]={0};

	string s1,s2;
	getline(cin,s1);
	
	getline(cin,s2);

	int i;
	FOR(i,0,s1.length(),1){
		if(s1[i]>='A' && s1[i]<='Z'){
			a1[(int)s1[i] -(int)'A']++;
		}
		else if(s1[i]>='a' && s1[i]<='z'){
			a1[26+(int)s1[i] -(int)'a']++;
		}
	}
	FOR(i,0,s2.length(),1){
		if(s2[i]>='A' && s2[i]<='Z'){
			a2[(int)s2[i]-(int)'A']++;
		}
		else if(s2[i]>='a' && s2[i]<='z'){
			a2[26+(int)s2[i] -(int)'a']++;
		}
	}

	FOR(i,0,52,1){
		if(a2[i]>a1[i]){
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";

	return 0;
}