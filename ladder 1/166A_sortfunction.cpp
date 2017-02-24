#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <utility>
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;

bool sortdes(const pair<int,int> &a,const pair<int,int> &b){
    if(a.first >b.first)return true;
    else if(a.first == b.first && a.second < b.second)return true;
    else return false;
}
 
int main(){
	int n,k,i;
	cin >> n >> k;
	pair <int,int> p[n];
	int x,t;
	FOR(i,0,n,1){
		cin >> x >> t;
		p[i].first = x;
		p[i].second = t;
	}
	sort(p,p+n,sortdes);
	k=k-1;
	int c1=0,c2=0;
	FORd(i,k-1,0,1){
		if(p[i].first==p[k].first && p[i].second == p[k].second) c1++;
		else break;
	}
	FOR(i,k+1,n,1){
		if(p[i].first==p[k].first && p[i].second == p[k].second) c2++;
		else break;
	}	
	cout << c1+c2+1;

	return 0;
}