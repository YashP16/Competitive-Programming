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

void LCS(string s1, string s2){
	int table[s1.length()][s2.length()]={0};
	int check[s1.length()][s2.length()]; // can have values 0 , 1 , 2;

	FOR(i,0,s1.length(),1){
		FOR(j,0,s2.length(),1){
			if(s1[i]==s2[j]){
				if(i==0 || j == 0){
					table[i][j]= 1;
				}
				else{
					table[i][j]= max(table[i-1][j],table[i][j-1]) + 1;
				}
				check[i][j]= 2;
			}
			else{
				if(i==0 && j > 0){
					table[i][j]=table[i][j-1];
					check[i][j]=0;
				}
				else if(j==0 && i > 0){
					table[i][j]=table[i-1][j];
					check[i][j]=1;	
				}
				else{
					if(table[i][j-1] >= table[i-1][j]){
						table[i][j]=table[i][j-1];
						check[i][j]=0;
					}
					else{
						table[i][j]=table[i-1][j];
						check[i][j]=1;
					}
				}
			}
		}
	}

	int i=s1.length()-1,j=s2.length()-1;
	string result="";
	while(i>=0 && j>=0){
		switch(check[i][j]){
			case 0:
				j--;
				break;
			case 1:
				i--;
				break;
			case 2:
				result += s2[j];
				i--;
				j--;
				break;
		}
	}
	reverse(result.begin(),result.end());
	cout << result << endl; 
}

int main(){
	string s1,s2;
	cin >> s1 >> s2;
	LCS(s1,s2);
	return 0;

}