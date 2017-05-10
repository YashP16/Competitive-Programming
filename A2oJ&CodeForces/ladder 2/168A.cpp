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
	int n,x,y;
	cin >> n >> x >> y; 
	int clones =0;
	if((ceil((double)(y*n)/(double)100)-x)>0) clones = ceil((double)(y*n)/(double)100)-x;
	cout<< clones;
	
	return 0;
}