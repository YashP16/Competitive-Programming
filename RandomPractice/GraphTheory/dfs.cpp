// Implementation of dfs using stack 

#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <stack>
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

class graph {
	
	private :
		int v;
		int e;
		vector < vector <int> > list; 
	
	public :		
		graph(){
			cout << "Enter the number of vertex : ";
			cin  >> v;
			cout << "Enter the number of edges : ";
			cin >> e;

			
			list.resize(v);
			int x,y;

			FOR(i,0,e,1){
				cin >> x >> y;
				list[x].push_back(y);
			}
			FOR(i,0,v,1){
				sort(list[i].begin(), list[i].end());
			}
		}
		
		void printGraph(){
			FOR(i,0,v,1){
				cout << i << " -> "; 
				FOR(j,0,list[i].size(),1){
					cout << list[i][j] << " ";
				}
				cout << endl;
			}
		}

		void dfs(int start){
		 	stack <int> s;
		 	int color[v] = {0};
		 	s.push(start);
		 	color[start]=1;
		 	cout << start << " ";		 	
		 	while(!s.empty()){
		 		int t = s.top();
		 		if(!list[t].empty()){
		 			if(color[list[t][0]]==0){
		 				s.push(list[t][0]);
		 				cout << list[t][0] << " ";
		 				color[list[t][0]] = 1;
		 			}
		 			list[t].erase(list[t].begin(),list[t].begin()+1);
		 		}
		 		else{
		 			s.pop();
		 		}
		 	}
		 }

};

int main(){
	graph g;
	g.printGraph();
	int start;
	cout << "Please enter the starting point :";
	cin >> start;
	g.dfs(start);
	return 0;
}
