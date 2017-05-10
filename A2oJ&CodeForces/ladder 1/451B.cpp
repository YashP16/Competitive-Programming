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
	ll a[n+1];
	int x=1,y=1;
	a[0] = -12312;
	FOR(i,1,n+1,1){
		cin >>a[i];
	}
	int flag =1;
	int count = 0;
	FOR(i,1,n,1){
		if(count >1){
			flag=0;
			break;
		}
		else if(a[i]>a[i-1]&&a[i]>a[i+1] && count<1) {
			x = i;
			y = x+1;
			while(y<n){
				if(a[y]>=a[y+1]){
					y++;
				}
				else break;
			}
			if(y==n){
				if(a[y]>=a[x-1])flag =1;
				else flag =0;
				break;
			}
			else{
				int c = y+1;
				if(c == n){
					if(a[c]>a[x])flag =1;
					else flag =0;
					break;		
				}
				else{
					while(c<n){
						if(a[c]<=a[c+1]&&a[c]>= a[x] && a[y]>=a[x-1]){
							flag =1;
							c++;
						}
						else {
							flag =0;
							break;
						}
						break;
					}
				}
			}	
			count++;
		}
	}

	if(flag ==1){
		cout<<"yes\n";
		cout << x << " " << y;
	}
	else{
		cout << "no\n";
	}
	return 0;
}