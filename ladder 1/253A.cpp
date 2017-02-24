#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int n,m;
	cin>>m;
	cin>>n;
	
	if(n>m){
		for(int i = 0; i<m; i++)
			printf("GB");
		for(int i = m; i<n; i++)
			printf("G");
	}
	if(n<=m){
		for(int i = 0; i<n; i++)
			printf("BG");
		for(int i = n; i<m; i++)
			printf("B");
	}
}