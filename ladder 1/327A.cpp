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
	bool a[i];
	int zero=0,one = 0;
	FOR(i,0,n,1){
		cin >> a[i];
		if(a[i]==0)zero++;
		else one++;
	}
	int max =0;
	if(zero==0 ) cout << n-1;
	else if (zero == n) cout << n;
	else{
		int i,j,k;
		FOR(i,0,n-2,1){
			FOR(j,i+1,n,1){
				int z=0, o=0;
				int count=0;
				FOR(k,i,j+1,1){
					if(a[k]==0)z++;
					else o++;
				}
				count = one - o + z;
				if(count>=max) max = count;
			}
		}
		cout << max;
	}
	return 0;
}