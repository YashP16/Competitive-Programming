#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int i;
	int a[n] ={0};
	int b[n] ={0};
	FOR(i,0,s.length(),1){
		if(i<s.length()/2) a[i] = (int)s[i]-'0';
		else b[i-s.length()/2] =(int)s[i]-'0';
	}
	sort(a,a+n);
	sort(b,b+n);
	if((a[0]<=b[0] && a[n-1]>=b[n-1]) ||(a[0]>=b[0] && a[n-1]<=b[n-1])) cout << "NO";
	else{
		if(a[0]<b[0]){
			FOR(i,0,n,1){
				if(a[i]>=b[i]){
					cout<< "NO";
					return 0;
				}
			}
		}
		else if(a[0]>b[0]){
			FOR(i,0,n,1){
				if(a[i]<=b[i]){
					cout<< "NO";
					return 0;
				}
			}
		}
		cout << "YES";
	}
	return 0;
}