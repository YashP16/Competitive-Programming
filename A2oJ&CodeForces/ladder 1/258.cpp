#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;

int main(){
	string s;
	cin >> s;
	string s1="";
	int flag =0;
	int i;
	FOR(i,0,s.length(),1){
		if(flag == 0 && s[i]=='0'){
			i++;
			flag =1;
		}
		if(flag==0 && i==s.length()-1){
			s1 += '\n';
			break;
		}
		s1 += s[i];	
	}
	cout << s1 << endl;
	return 0;
}