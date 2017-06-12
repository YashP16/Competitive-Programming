// coach // dfs

#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
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
	int n,m;
	cin >> n >> m;
	stack <int> s;
	if(m == 0){
		REP(i,n){
			cout << i+1 << " ";
			if((i+1)%3 == 0)cout << "\n";
		}
	}
	else{
		pair <vector<int>,int>  a[n+1];
		FOR(l,1,n+1,1)a[l].second = -1;
		while(m--){
			int x,y;
			cin >> x >> y;
			a[x].first.push_back(y);
		}

		int count = n;
		vector < int > three;
		vector < int > two;
		vector < int > one;


		while(count>0){
			int i =1;
			while(a[i].second != -1 && i < n)i++;

			stack <int> s;
			vector <int> buffer;
			s.push(i);
			count--;
			buffer.push_back(i);
			a[s.top()].second = 1;
			while(!s.empty()){
				if(a[s.top()].first.size()==0){
					s.pop();
				}
				else{
					if(a[a[s.top()].first[0]].second == -1){
						buffer.push_back(a[s.top()].first[0]);
						a[s.top()].first.erase(a[s.top()].first.begin());
						s.push(buffer[buffer.size()-1]);
						a[s.top()].second = 1;
						count--;
					}
					else a[s.top()].first.erase(a[s.top()].first.begin());
				}
			}
			if(buffer.size() > 3){
			 	cout << -1 << endl;
			 	return 0;
			}
			else if (buffer.size() == 1)one.push_back(buffer[0]);				
			else if (buffer.size() == 2){
				two.push_back(buffer[0]);
				two.push_back(buffer[1]);
			}
			else if(buffer.size() == 3 ){
				three.push_back(buffer[0]);
				three.push_back(buffer[1]);
				three.push_back(buffer[2]);
			}
		}
		
		
		if(two.size()/2> one.size())cout << -1 << endl;
		
		else if((one.size()-(two.size()/2))%3 != 0)cout << -1 << endl;
		
		else{
			FOR(i,0,three.size(),1){
				cout << three[i] << " ";
				if(i % 3 == 2) cout << endl;
			}
			FOR(j,0,two.size(),1){
				cout << two[j] << " ";
				if(j%2 == 1){
					cout << one[0] << endl;
					one.erase(one.begin());
				}
			}
			FOR(i,0,one.size(),1){
				cout << one[i] << " ";
				if(i+1 % 3 == 0)cout << endl;
			}
		}
	}

	return 0;
}