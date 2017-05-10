#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	int a[m];
	for(int i =0;i<m;i++){
		cin >> a[i];
	}
	int min=0;int max=0;
	sort(a,a+m);
	int count =0;
	int x = n;
	int b[m];
	copy(a,a+m,b);
	while(n--){
		if(a[count] ==0){
			count++;
			n++;
		}
		else{
			min+= a[count];
			a[count]--;
		}
	}
	int countb=m-1;
	while(x--){
		if(b[countb]==0){
			countb--;
			x++;
		}
		else{
			max+=b[countb];
			b[countb]--;
			sort(b,b+m);
		}
		if(countb ==-1) countb = m-1;
	}
	cout << max << " ";
	cout << min;
}