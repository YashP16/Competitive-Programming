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


bool comp(int a,int b){
	if(a>b)return true;
	return false;
}

int findPos(int l[],int left,int right,int x){
	if(left<= right){
		int mid = (left+right)/2;
		if(x>l[mid]) return findPos(l,left,mid-1,x);
		else return findPos(l,mid+1,right,x);
	}
	return right;
}

int main(){
	int t,r,pos,count,rem,x;
	cin >> t;
	while(t--){
		int n,q;
		cin >> n >> q;
		int l[n];
		REP(i,n) cin >> l[i];
		sort(l,l+n,comp);
		while(q--){
			count=0;
			cin >> x;
			if(x <= l[n-1]){
				count = n;
			}
			else{
				r = n-1;
				pos = findPos(l,0,n-1,x);
				count += pos+1;
				pos++;
				rem =0;
				while(pos < r){
					rem = x - l[pos];
					if(r-pos >= rem){
						count++;
						r -= rem;
					}
					else break;
					pos++;
				}
			}
			cout << count << endl;
		}
	}
	return 0;
}