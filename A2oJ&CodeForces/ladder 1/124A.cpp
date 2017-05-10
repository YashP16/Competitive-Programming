#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	int m = 0;
	int count = 0;
	for(int i =0; i<s.length(); i++){
		if(s[i]-'0' == m){
			count++;
		}
		else{
			m = !m;
			count = 1;
		}
		if(count == 7) break;
	}
	if(count>= 7)cout << "YES";
	else cout << "NO";

}