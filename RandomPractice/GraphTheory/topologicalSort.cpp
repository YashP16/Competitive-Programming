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
		int* color;
		int e;
		vector < vector <int> > list; 
	
	public :		
		graph(){
			cout << "Enter the number of vertex";
			cin  >> v;
			cout << "Enter the number of edges";
			cin >> e;

			int *color = new int[v];
			FOR(i,0,v,1)color=0;
			
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

		void tS(graph g){
		 	vector < vector<int> > temp(list);
		 	pair <int,int> a[v];
		 	stack <int> s;
		 	s.push(0);
		 	color[0]=1;
		 	counter = 0;
		 	while(!s.empty()){
		 		if(!list[s.top()].empty()){
		 			if(color[list[s.top()][0]]==0){
		 				s.push(list[s.top()][0]);
		 				color[list[s.top()][0]];
		 			}
		 			erase(list[s.top()].begin(),list[s.top()]+1);
		 		}
		 		else{

		 		}
		 	}
		 }

};

int main(){
	graph g;
	g.printGraph();
	return 0;
}
