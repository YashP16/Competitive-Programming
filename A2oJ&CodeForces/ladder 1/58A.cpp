#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
	string s;
	cin >> s;

	int a[26] = {0};
	int m=0,ex=0; 
	for(int i = 0;i<s.length();i++){
		a[(int)s[i]-(int)'a']++;
		if((s[i] == 'h')||(s[i]== 'e')||(s[i] == 'l')||(s[i] == 'o')) m++;
		else ex++;
	}
	int flag = 0;
	string r = "hello";
	int countr =0,counts =0;
	// hlelo
		while (flag != 1 && counts<s.length()){
			if(s[counts] == r[countr]){
				if(r[countr]=='o'){
					flag =1;
					break;
				}
				else{
					countr++;
					counts++;
				}	
			}
			else counts++;
		}
		
	if((a[(int)'h'-(int)'a']>=1 && a[(int)'e'-(int)'a']>=1 && a[(int)'l'-(int)'a']>=2 && a[(int)'o'-(int)'a']>=1 && (m+ex) >= 5) && flag ==1) cout<<"YES";
	else cout << "NO";
}