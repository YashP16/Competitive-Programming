#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define vi vector<ll>
#define vii vector<vector<ll> >
#define ll long long int //range -> –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
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
		int *m = min_element(h,h+n);
		x = m-h;
	}
	else{	
		int flag =0;	
		int sum =0;
		FOR(i,0,n-k+1,1){
			int temp =0;
			if(flag == 0){
				FOR(j,0,k,1){
					sum += h[j];
				}
				flag = 1;
				temp = sum;
			}
			else{
				sum =sum - h[i-1] + h[i+k-1];
				temp = sum;
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