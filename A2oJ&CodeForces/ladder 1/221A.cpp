#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	for(int i =1; i<=n;i++){
		if(i == 1)cout << n << " ";
		else cout <<i-1 << " ";
	}	
}