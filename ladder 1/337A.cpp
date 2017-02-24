#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
	int n,m;
	cin >> n >>m;
	int f[m];
	for(int i =0;i<m;i++ ){
		cin >> f[i];
	}
	sort(f,f+m);
	int diff =f[n-1]-f[0];

	for (int i = 1; i <= m - n; ++i){
		if(f[i+n-1]-f[i] < diff) diff = f[i+n-1]-f[i];
	}
	cout << diff;
	

}
