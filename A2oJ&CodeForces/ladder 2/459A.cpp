#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;

int main(){
		int x1,x2,y1,y2;
		cin >> x1 >> y1 >> x2 >> y2;

		if(x2-x1 == 0 || y2-y1 ==0){
			if(x2-x1 == 0){
				int c = abs(y2-y1);
				cout << x1+c << " " << y1 << " " << x1+c <<" "<<y2;
			}
			else{
				int c = abs(x2-x1);
				cout << x1  << " " << y1+c  << " " <<x2 <<" "<< y1+c ;	
			}
		}
		else if(abs(x2-x1) == abs(y2-y1)){
			cout << x2 << " " << y1 << " " << x1 <<" "<< y2;
		}
		else cout <<-1;
	
	return 0;
}

