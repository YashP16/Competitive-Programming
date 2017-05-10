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


int main(){
	int n;
	cin >> n;
	vector<string> a;
	vector<string> b;
	while(n--){
		char c;
		cin >> c;
		string s;
		cin >>s;
		if(c == '+')a.push_back(s);
		else b.push_back(s);
	}
	sort(a.begin(),a.end());
	sort(b.begin(), b.end());
	FOR(i,0,b.size(),1){
		int count = 0;
		while(b[i]>=a[count] && count<=a.size()-1){
			count++;
		}
		string temp = "";
		string temp2 = "";
		int x=0;
		if(count == 0){
			cout << b[i][x] << endl;
		}
		else if(count == a.size()){
			while(x<b[i].length() && x<a[count-1].length() && b[i][x]==a[count-1][x]){
				temp += b[i][x];
				x++;
			}
			temp+= b[i][x];
			if(temp == b[i])cout << -1 << endl;
			else  cout << temp << endl;
		}
		else{
			x = 0;
			while(x<b[i].length() && x<a[count].length() && b[i][x]==a[count][x]){
				temp += b[i][x];
				x++;
			}
			temp+=b[i][x];
			x = 0;
			while(x<b[i].length() && x<a[count-1].length() && b[i][x]==a[count-1][x]){
				temp2 += b[i][x];
				x++;
			}
			temp2+= b[i][x];
			if(temp >=temp2)
				if(temp != b[i])cout << temp << endl;
				else cout << -1 << endl;
			else {
				if(temp2 != b[i])cout << temp2 << endl;
				else cout << -1 << endl;
			}
		}
	}

	return 0;
}
