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


void operate(vector<int> &v,int i){
	while(v[i] != 1|| v[i] !=0){
		int c =(int)v[i]/2; 
		v[i]=c;
		v.insert(v.begin()+i+1,v[i]%2);
		v.insert(v.begin()+i+2,c);
	}
	return;
}

int main(){
	int n,l,r,i;
	vector<int> v;
	cin >> n;
	v.push_back(n);
	operate(v,0);
	int c =0;
	FOR(c,0,v.size(),1){
		while(v[c]!=1 && v[c]!=0){
			operate(v,c);
		}
		break;
	}
	FOR(i,0,v.size(),1){
		cout << v[i] << " ";
	}
	cout << endl;
	
	return 0;
}