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

bool comp(const pair<int,pair<int,int> > &a,const pair<int,pair<int,int> > &b){
    if(a.second.first <b.second.first)return true;
    else return false;
}

bool comp2(const pair<int,pair<int,int> > &a,const pair<int,pair<int,int> > &b){
    if(a.first <b.first)return true;
    else return false;
}

int main(){
	int n,w;
	cin >> n >> w;
	int max = 0;
	pair<int,pair<int,int> > a[n];
	REP(i,n){
		cin >> a[i].second.first;
		a[i].first = i;
		a[i].second.second = ceil((float)a[i].second.first/(float)2);
		w -= a[i].second.second;
		if(w <0 && i < n){
		 	cout << -1 << endl;
			return 0;
		}
	}
	sort(a,a+n,comp);
	FORd(i,n-1,0,1){
		if(w + a[i].second.second >= a[i].second.first){
			w = w - (a[i].second.first - a[i].second.second); 
			a[i].second.second = a[i].second.first;
		}
		else if(w+a[i].second.second < a[i].second.first){
			a[i].second.second += w;
			w = 0;
			break;
		}
	}
	sort(a,a+n,comp2);

	REP(i,n){
		cout << a[i].second.second << " ";
	}
	cout << endl;
}