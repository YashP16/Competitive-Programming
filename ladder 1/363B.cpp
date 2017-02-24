#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;

int main(){
	int n,k,i,j;
	cin >> n >> k;
	int h[n];
	FOR(i,0,n,1){
		cin>>h[i];
	}
	int min = 2147483647;
	int x =0;
	if(k ==1){
		FOR(i,0,n,1){
			if(h[i]<min){
				min = h[i];
				x=i;
			}
		}
	}
	else{		
		FOR(i,0,n-k,1){
			int temp =0;
			FOR(j,i,i+k,1){
				temp += h[j];
			}
			if(temp<min){
				min = temp;
				x = i;
			}
			if(temp == k)break;
		}
	}
	cout << x+1;

	return 0;
}