#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b,c) for(int i=a;i<b;i += c)
#define FORd(i,a,b,c) for(ll i=a;i>=b;i -=c)
#define vi vector<ll>
#define vii vector<vector<ll> >
#define ll long long int //range -> â��9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
using namespace std;

void knapSackP(int W,int n,int weight[],ll value[]){
	ll table [n+1][W+1]={0};
	FOR(i,0,n+1,1){
		FOR(j,0,W+1,1){
			if(i==0 || j ==0){
				table[i][j]=0;
			}
			else{
				if(weight[i-1]==j){
					if(table[i-1][j]>value[i-1])table[i][j]= table[i-1][j];
					else table[i][j] =value[i-1];
				}
				else if(weight[i-1]>j){
					table[i][j] = max(table[i][j-1],table[i-1][j]);
				}
				else{
					table[i][j] = value[i-1];

					if(i>1){
						ll k = j-weight[i-1];
						table[i][j] += table[i-1][k];

					}
					if(table[i-1][j]>table[i][j])table[i][j]= table[i-1][j];
				}
			}
		}
	}
	cout << table[n][W] << endl;
}

int main(){
	int n,m;
	cin >> n >> m;
	int weight[n];
	ll value[n];
	REP(i,n) cin >> weight[i] >> value[i];
	knapSackP(m,n,weight,value);
	return 0;
}