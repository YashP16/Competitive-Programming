// Programm to find if a subset exists such that the sum of its element is == sum.


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

void subsetSum(int sum,int n,int set[]){
	int table[n][sum+1]={0};
	FOR(i,0,n,1){
		FOR(j,0,sum+1,1){
			if(j==0)table[i][j]=1;
			else{
				if(i==0){
					if(set[i]==j) table[i][j]=1;
					else table[i][j]=0;
				}
				else{
					if(set[i]>j)table[i][j]=table[i-1][j];
					else if(set[i]<=j){
						if(table[i-1][j]==1)table[i][j]=1;
						else{
							table[i][j]=table[i-1][j-set[i]];
						}
					}
				}
			}
		}
	}
	if(table[n-1][sum]==1){ 
		cout << "True\n";
		vector <int> result;
		int i = n-1,j=sum;
		while(i>=0 && j>=0){
			if(table[i-1][j]==1){
				i--;
			}
			else{
				result.push_back(set[i]);
				j-= set[i];
				i--;
			}
		}
		REP(k,result.size()){
			cout << result[k] << " ";
		}
		cout << endl;
	}
	else cout << false;
}

int main(){
	int sum,n;
	cin >> sum >> n;
	int set[n];
	REP(i,n) cin >> set[i];

	subsetSum(sum,n,set);
	return 0;
}
