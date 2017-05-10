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
int A[14]={4,7,44,47,74,77,444,447,474,477,744,747,774,777};

int main(){
	int n,i;
	cin >> n;
	FOR(i,0,14,1){
		if(n==A[i] || n%A[i]==0){
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}