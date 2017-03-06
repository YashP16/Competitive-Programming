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

bool sortdes(string &a,string &b){
    if(a.length()<b.length())return true;
    else if(a.length() == b.length() && a<b)return true;
    else return false;
}

int main(){
	int n,i;
	cin >> n;
	string v[n];
	FOR(i,0,n,1){
		cin >> v[i];
	}
	sort(v,v+n,sortdes);
	FOR(i,0,n,1){
		cout << v[i] << endl;
	}
	return 0;
}