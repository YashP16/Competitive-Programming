#include <iostream>
#include <algorithm>
#include <string.h>
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;

int main(){
	int index[5] ={0,1,2,3,4};
	int m[5][5];
	int i,j;
	FOR(i,0,5,1){
		FOR(j,0,5,1){
			cin >> m[i][j];
		}
	}
	int max = 0;
	do{
		int x = m[index[0]][index[1]] + m[index[1]][index[0]] + m[index[1]][index[2]] + m[index[2]][index[1]] +( 2*(m[index[2]][index[3]] + m[index[3]][index[2]]) )+ (2*(m[index[4]][index[3]] + m[index[3]][index[4]]));
		if(x > max) max =x;
	}while(next_permutation(index,index+5));
	cout << max;
	return 0;
}