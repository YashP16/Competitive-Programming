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
	int n,i;
	cin >> n;
	int a[n];
	int c25 = 0;
	int c50 = 0;
	int flag =1;
	FOR(i,0,n,1){
		cin >> a[i];
		if(flag == 1){
			if(a[i]==25)c25++;
			else if(a[i]==50){
				c25-=1;
				c50++;
				if(c25<0)flag =0;
			}
			else{
				if(c50==0){
					c25-=3;
					if(c25<0)flag=0;
				}
				else{
					c50--;
					c25--;
					if(c25<0)flag =0;
				}
			}
		}
	}
	if(flag ==1)cout << "YES";
	else cout << "NO";

		
	return 0;
}