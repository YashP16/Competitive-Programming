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
	int n,m,i;
	cin >> n >> m;
	int a[n+1];
	int l[m];
	FOR(i,1,n+1,1){
		cin >> a[i];	// main array
	}
	FOR(i,0,m,1){
		cin >> l[i];	// index to check from
	}
	int j;
	vector<int> s(n+1,-1);	// memory list
	int count =0;	//counter to maintain count till x;
	int x = n;
	bool c[100001] = {0};	// check if a new number is there
	FOR(i,0,m,1){		// itereting therough l
		if(s[l[i]] == -1){	//checking if evaluated early or not
			FORd(j,x,l[i],1){ 	// if not evaluated then evaluate
				if(c[a[j]]==0){	// IF NUMBER NOT ON CHECK LIST
					c[a[j]]=1;
					count++;
				}
				x--;
				s[j]=count; 
			}
		}
		cout << s[l[i]] << endl;
	}
	return 0;
}