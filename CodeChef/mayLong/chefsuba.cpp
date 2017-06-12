#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <list>
#include <sstream>
#include <utility> // for pair
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(int i=a;i<b;i += c)
#define FORd(i,a,b,c) for(int i=a;i>=b;i -=c)
#define vi vector<ll>
#define vii vector<vector<ll> >
#define ll long long int //range -> –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
using namespace std;

int main(){
	int n,k,p;
	cin >> n >> k >> p;
	bool a[n];
	int count1 =0;
	
	REP(i,n){
		cin >> a[i];
		count1 += a[i];
	}

	string s;
	cin >> s;

	if(k>=n){
		FOR(i,0,s.length(),1){
			if(s[i]=='?')cout << count1 << endl;
		}
		return 0;
	}

	int c = 0;
	list <int> swa;
	
	FOR(j,0,n-k+1,1){
		if(j == 0){
			FOR(l,0,k,1){
				c+=a[l];
			}	
		}
		else{
			c = c - a[j-1] + a[j+k-1];
		}
		swa.push_back(c);
	} 

	int end = n-1;
	int pre  = k-1;
	int max = *max_element(swa.begin(), swa.end());
	int index = distance(swa.begin(),max_element(swa.begin(), swa.end())); 
	
	FOR(i,0,p,1){
		if(s[i]=='!'){
			
			int f = swa.front();
			swa.pop_back();
			swa.push_front(f+a[end]-a[pre]);
			
			if(index == n-k){
				max = *max_element(swa.begin(),swa.end());
	        	index = distance(swa.begin(),max_element(swa.begin(),swa.end()));	
			}
			
			else{
				if(swa.front() >= max)
				{
					max = swa.front();
					index = 0;
				}
				else index++;
			}

			if(end == 0) end = n-1;
			else end--;
			
			if(pre == 0) pre = n-1;
			else pre--;
		
		}

		else{
			cout << max << endl;
		}
	}
	
	return 0;
}