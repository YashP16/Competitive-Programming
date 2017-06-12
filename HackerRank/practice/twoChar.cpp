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
#define ll long long int //range -> â��9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
using namespace std;

int mk_str(string s,char a,char b){
	string temp = "";
	REP(i,s.length()){
		if(s[i]==a||s[i]==b)temp+=s[i];
	}
	if(temp.length()<=1)return 0;
	char last = temp[0];
	FOR(i,1,temp.length(),1){
		if(temp[i]==last)return 0;
		last = temp[i];
	}
	return temp.length();
}

int main(){
	int n;
	cin >> n;
	string s;
	cin>>s;
	vector <char> c;
	bool alph[26]= {0};
	REP(i,n){
		if(alph[s[i]-'a']==0){
			alph[s[i]-'a']=1;
			c.push_back(s[i]);
		}
	}
	int max =0;
	FOR(i,0,c.size()-1,1){
		FOR(j,i+1,c.size(),1){
			int temp = mk_str(s,c[i],c[j]);
			if(temp> max)max= temp;
		}
	}
	cout << max << endl;

	
}