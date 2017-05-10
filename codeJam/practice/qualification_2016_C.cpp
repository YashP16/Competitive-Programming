// Template for Codejam
// use ./a.out < smallQ#.in > smallQ#.txt 

#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <cstdlib>
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

ll isPrime(ll n){
	FOR(i,2,sqrt(n),1){
		if(n%i == 0) return i;
	}
	return -1;
}

ll* isJamcoin(string n){
	ll *v;
	v = new ll[9];
	FOR(i,2,11,1){
		ll num = 0;
		FOR(j,0,n.length(),1){
			num += (n[j]-'0')*pow(i,n.length()-1-j);
		}
		ll k = isPrime(num);
		if(k ==-1)return NULL;
		else v[i-2] = k;
	}
	return v;
}

string itobs(ll n){
	string out ="";
	while(n!=0){
		if(n%2 == 0) out+= '0';
		else out+= '1';
		n = n/2;
	}
	reverse(out.begin(),out.end());
	return out;
}
int main(){
	int n;
	cin >> n;
	REP(i,n){
		int l,j;
		cin >> l >> j;
		cout << "Case #"<< i+1 << ":\n"; 
		int count =0;
		FOR(k,pow(2,l-1)+1,pow(2,l),1){
			string s = itobs(k);
			if(s[s.length()-1] == '1'){
				ll *a;
				a = isJamcoin(s);
				if (a !=NULL && count<j){
					cout <<s << " ";
					REP(x,9){
						cout << a[x] << " ";
					}
					cout << endl;
					count++;
				}
				else if(count == j){
					break;
				}
			}
		}
		
	} 
	return 0;
}