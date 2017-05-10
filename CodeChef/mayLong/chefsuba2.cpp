#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
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
	vector <int> ans(n,-1);
	bool a[2*n];
	int count1 =0;
	REP(i,n){
		cin >> a[i];
		a[n+i]=a[i];
		if(a[i]==1)count1++;
	
	}
	int start = 0;

	string s;
	cin >> s;

	FOR(i,0,p,1){
		int of = 0;
		int poi =0;
		int max = 0;
		int count =0;
		if(s[i]=='!'){
			if(start==0) start = n-1;
			else start--;
		}
		else if(s[i]=='?'){
			if(k>=n){
				cout << count1 << endl;
			}
			else if(ans[start] == -1){
				if(of == 0){
					int flag = 0;
					int x = start;
					count = 0;
					max = 0;
					FOR(j,start,n+start-k+1,1){
						if(flag==0){
							FOR(l,start,start+k,1){
								count+=a[l];
							}
							if(count>max)max = count;
							flag = 1;
						}
						else{
							count = count - a[x] + a[x+k];
							x++;
							if(count>max){
								max = count;
								poi = j;
							}
						}
						if(max == k) break;
					}
					ans[start]=max;
					cout << max << endl;
					of =1;
				}
				else{
					if(poi + k - n < 0){
						if(start < poi || start > poi+k-1){
							count = 0;
							FOR(l,start,start+k,1){
								count+=a[l];
							}
							if(count>max){
								max = count;
								poi = start;
							}
						}
						else{
							of = 0;
							i--;
						}
					}
					else{
						if(start < poi || start > poi+k-1-n){
							count = 0;
							FOR(l,start,start+k,1){
								count+=a[l];
							}
							if(count>max){
								max = count;
								poi = start;
							}
						}
						else{
							of = 0;
							i--;
						}
					ans[start] = max;
					cout << ans[start] << endl;
					}
				}
			}
			else {
				cout << ans[start]<<endl;
			}
		}
	}

	return 0;
}