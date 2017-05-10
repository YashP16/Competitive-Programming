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

bool sortasc(const pair<int,int> &a,const pair<int,int> &b){
    if(a.first < b.first)return true;
    else if(a.first == b.first && a.second < b.second)return true;
    else return false;
}

int main(){
	int n, v;
	cin >> n >> v;
	pair <int,int> t[n];
	FOR(i,0,n,1){
		cin >> t[i].first >>t[i].second;
	}
	sort(t,t+n,sortasc);
	int m = t[n-1].first;
	int fruits = 0;
	FOR(i,0,m+1,1){
		int f = v;
		int tr = 0;
		while(f>0 & tr<n){
			if(t[tr].first >= 0 && t[tr].first < 2 && t[tr].second > 0){
				if(f>=t[tr].second){
					fruits+= t[tr].second;
					f -= t[tr].second;
					t[tr].second = 0;
				}
				else{
					fruits += f;
					t[tr].second -= f;
					f = 0;
				}
			}
			else if(t[tr].first > 1) break;
			else tr++;
		} 

		FOR(j,0,n,1){
			t[j].first--;
		}
	}
	cout << fruits;	return 0;
}