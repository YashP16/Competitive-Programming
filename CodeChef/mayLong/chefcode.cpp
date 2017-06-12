#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(ll i=a;i<b;i += c)
#define FORd(i,a,b,c) for(ll i=a;i>=b;i -=c)
#define vi vector<ll>
#define vii vector<vector<ll> >
#define ll long long int //range -> â��9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
using namespace std;
 
 
bool sortdes(const double a,const double b){
    if(a >b)return true;
    else return false;
}
class chefcode{
private :
	double *v;
	int count;
	int n;
	double sum;
	bool flag;
	ll k;
	double lim;
public:	
	chefcode(){
		count = 0;
		sum = 0;
		flag = 1;
		cin >> n >> k;
		v = new double[n];
		lim = log(k);
		REP(i,n){
			ll x;
			cin >> x;
			double a = log(x);
			sum+= a;
			v[i]=a;
		}
		if(sum <= lim){
			count =pow(2,n)-1;
			flag = 0;
		}
			
	}
 
	void getNum(double prev,double rem,int index,int dirn){
		if(dirn == -1){
			sort(v,v+n,sortdes);
			prev = v[0];
			index = 0; 
		}
		
		else if(dirn == 0){
			if(sum-v[index] - rem <= lim){
				count += pow(2,n-index-1)-1;
				return;
			}
			prev += v[index+1] - v[index];
			rem += v[index];
			index++;
		}
 
		else{
			prev += v[index+1];
			index++;
		}
		if(prev<=lim){
			count++;
			if(index<n-1){
				getNum(prev,rem,index,0);
				getNum(prev,rem,index,1);
			}
		}
		else{
			if(index < n-1)getNum(prev,rem,index,0);
		}
		return;
	}
	bool getFlag(){
		return flag;
	}
 
	void printCount(){
		cout << count << endl;
	}
};
 
 
int main(){
	chefcode c;
	if(c.getFlag())c.getNum(0,0,0,-1);
	c.printCount();
} 