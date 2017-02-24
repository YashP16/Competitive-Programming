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
	int n;
	cin >> n;
	int a[n];
	vector< vector<int> > v(100001,vector <int> (1,-1));
	int i;
	FOR(i,0,n,1){
		cin >> a[i];
		if(v[a[i]][0]==-1)v[a[i]][0] = i+1;
		else v[a[i]].push_back(i+1);
	}
	int j;
	int count =0;
	pair <int,int> p[n];
	bool check[100001] ={0};
	for(i : a){
		if(check[i]==0){
			int flag =0;
			int diff =0;
			if(v[i].size()==1){
				diff = 0;
				flag =1;
			}
			else{ 
				diff = v[i][1]-v[i][0];
				flag =1;
				FOR(j,1,v[i].size()-1,1){
					if(v[i][j+1] - v[i][j] != diff){
						flag = 0;
						break;
					}
				}
			}
			if(flag ==1){ 
				p[count].first = i;
				p[count].second = diff;
				count++;
			}
			check[i]=1;
		}
	}
	cout << count << endl;
	if(count !=0){
		sort(p,p+count);
		FOR(i,0,count,1){
			cout << p[i].first << " " << p[i].second << endl;
		}
	}

	return 0;
}