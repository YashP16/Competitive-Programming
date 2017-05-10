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
	string m[4];
	int i,j;
	FOR(i,0,4,1){
		FOR(j,0,4,1){
			cin >> m[i][j];
		}
	}
	FOR(i,0,3,1){
		FOR(j,0,3,1){
			int count1 =0,count2=0;
			if(m[i][j+1] == m[i][j])count1++;
			else count2++;
			if(m[i+1][j+1] == m[i][j])count1++;
			else count2++;
			if(m[i+1][j] == m[i][j])count1++;
			else count2++;
			if(count1>=2 || count2 == 3){
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";

	
	return 0;
}