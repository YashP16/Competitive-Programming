#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(int i=a;i<b;i += c)
#define FORd(i,a,b,c) for(int i=a;i>=b;i -=c)
#define vi vector<ll>
#define vii vector<vector<ll> >
#define ll long long int //range -> –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
using namespace std;

void merge(int* a,int l,int mid,int r){
	
	int n1 = mid - l +1;
	int n2 = r - mid;
	int x[n1],y[n2];

	REP(i,n1){
		x[i] = a[l+i];
	}

	REP(i,n2){
		y[i] = a[mid+1+i];
	}

	int x_ptr =0,y_ptr = 0, a_ptr = l;
	
	while(x_ptr < n1 && y_ptr < n2){
		if(x[x_ptr] >= y[y_ptr]){
			a[a_ptr] = y[y_ptr];
			y_ptr++;
		}
		else{
			a[a_ptr]=x[x_ptr];
			x_ptr++;
		}
		a_ptr++;
	}
	
	while(x_ptr < n1){
		a[a_ptr] = x[x_ptr];
		x_ptr++;
		a_ptr++;
	}
	
	while (y_ptr < n2){
		a[a_ptr] = y[y_ptr];
		y_ptr++;
		a_ptr++;
	}
}

void mergeSort (int *a,int l,int r){
	if(l < r){ 
		int mid = l+(r-l)/2;
	    mergeSort(a,l,mid);
		mergeSort(a,mid+1,r);
	 	merge(a,l,mid,r);
 	}
}



int main(){
	int n;
	cin >> n;
	int a[n];
	REP(i,n){
		cin >> a[i];
	}
	mergeSort(a,0,n-1);

	REP(i,n){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}