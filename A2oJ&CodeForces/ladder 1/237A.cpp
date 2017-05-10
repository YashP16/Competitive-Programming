#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <utility> // for pair
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;

int main(){
	int n,i;
	cin >> n;
	pair <int,int> p[n];
	FOR(i,0,n,1){
		cin >> p[i].first >> p[i].second;
	}
	sort(p,p+n);
	int c =1;
	int temp=1;
	FOR(i,0,n-1,1){
		if(p[i].first==p[i+1].first && p[i].second == p[i+1].second){
			temp++;
		}
		else temp =1;
		if(temp > c)c =temp;  
	}
	cout << c;
	return 0;
}