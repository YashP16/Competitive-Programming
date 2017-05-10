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
	vector<int> v(10);
	vector<int>::iterator x =v.begin();

	int c=2;
	while(c!=0){
		int y = v.size();
		int n;
		cin >> c;
		cin >> n; 
		//v.resize(y+1);
		v.insert(x+c+1,n);
		int i;
		FOR(i,0,v.size(),1){
			cout << v[i] << " ";
		}
		cout << endl;

	}
	
	
	return 0;
}