#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stack>
#include <limits>
#include <vector>
#include <stack>
#include <sstream>
#include <queue>
#include <utility> // for pair
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(int i=a;i<b;i += c)
#define FORd(i,a,b,c) for(int i=a;i>=b;i -=c)
#define vi vector<ll>
#define vii vector<vector<ll> >
#define ll long long int //range -> 9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
#define PB push_back
#define sz size()
#define InF  2147483647
using namespace std;

int main(){
	string s;
	cin >> s;
	vector <int> count;
	count.PB(s[0]-'a'+1);
	int temp = count[0];
	FOR(i,1,s.length(),1){
		if(s[i]==s[i-1]){
			count.PB(temp + (s[i]-'a')+1);
			temp+=(s[i]-'a')+1;
		}
		else{
			count.PB(s[i]-'a'+1);
			temp = s[i]-'a'+1;
		}
	}
	int n;
	cin >> n;
	while(n--){
		int x;
		cin >> x;
		if(find(count.begin(),count.end(),x)!= count.end()) cout << "Yes\n";
		else cout << "No\n";
	}
}