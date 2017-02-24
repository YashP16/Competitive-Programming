#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;
bool isR(int a,int b,int c){
	if((c*c == (a*a)+(b*b))&& c>=a && c>=b)return true;
	else return false;
}

int main(){
	int n,a,b;
	cin >> n;
	int count =0;
	FOR(a,1,n+1,1){
		FOR(b,a,n+1,1){
			int c =(int)sqrt((a*a) + (b*b));
			if(c<=n){
				if(isR(a,b,c)){
					count++;
				}
			}
		}
	}
	cout << count;
	return 0;
}