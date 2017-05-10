#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;

int main(){
	int n,i;
	cin >> n;
	int a[n];
	FOR(i,0,n,1){
		cin >> a[i];		
	}
	sort(a,a+n);
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	v1.push_back(a[0]);
	if(a[1]<0 && a[2]<0){
		v2.push_back(a[1]);
		v2.push_back(a[2]);
		FOR(i,3,n,1){
			v3.push_back(a[i]);
		}
	}
	else if(a[1]<0&&a[2]==0){
		v3.push_back(a[1]);
		v3.push_back(a[2]);
		FOR(i,3,n,1){
			v2.push_back(a[i]);
		}
	}
	else if(a[1]==0){
		v3.push_back(a[1]);
		FOR(i,2,n,1){
			v2.push_back(a[i]);
		}
	}
	cout << v1.size() << " ";
	FOR(i,0,v1.size(),1){
		cout << v1[i] << " ";
	}
	cout << endl;

	cout << v2.size() << " ";
	FOR(i,0,v2.size(),1){
		cout << v2[i] << " ";
	}
	cout << endl;

	cout << v3.size() << " ";
	FOR(i,0,v3.size(),1){
		cout << v3[i] << " ";
	}
	cout << endl;

	return 0;
}