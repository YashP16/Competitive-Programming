#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <utility> // for pair,
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;
int main(){
	int n,m,d,i,j;
	cin >> n >> m >> d;
	int a[n][m] ={0};
	int flag=1;
	int mod = -1;
	int b[n*m]={0};
	int c=0;
	FOR(i,0,n,1){
		FOR(j,0,m,1){
			cin >> a[i][j];
			b[c] = a[i][j];
			if(mod == -1)mod = a[i][j]%d;
			else if(a[i][j]%d!=mod)flag = 0;
			c++;
		}
	}
 	if(flag ==1){
		sort(b,b+(n*m));
		int median = b[(n*m)/2];
		int count=0;
		FOR(i,0,n*m,1){
			count +=(abs(median-b[i]))/d;			
		}
		cout << count;
 	}
 	else cout << -1;
	return 0;
}