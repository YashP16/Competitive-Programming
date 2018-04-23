#include <bits/stdc++.h>

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e9)
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(int i=a;i<b;i += c)
#define FORd(i,a,b,c) for(int i=a;i>=b;i -=c)
#define all(v) ((v).begin(),(v).end())
#define vi vector<int>
#define vii vector<vector<int> >
#define vb vector<bool>
#define vbb vector<vector<bool> >
#define vI vector<ll>
#define vII vector<vector<ll> >
#define ll long long int //range -> 9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
#define F first
#define S second
#define PB push_back
#define sz size()
#define InF  2147483647
#define READ freopen("input.txt", "r", stdin);
#define WRITE freopen("output.txt", "w", stdout);
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define SQR(n) ((n)*(n))
#define MEM(a,val) memset(a,val,sizeof(a))
using namespace std;
	

class Graph{
    int V;   
    list< pair<int, int> > *adj;
 
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void sd(int src);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list< pair<int, int> >[V];
}
 
void Graph::addEdge(int u, int v, int w){
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::sd(int src){
    set< pair<int, int> > setds;
	
	int mod = 1000000007;
   	vii dist(V,vi(2));
 	REP(i,V){
 		dist[i][0]=MAX;
 		dist[i][1]= i;
 	}
    dist[src][0] = 0;


    setds.insert(make_pair(0, src));
    dist[src][0] = 0;
 
    while (!setds.empty()){
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());
        int u = tmp.second;
        
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second; 
            if (dist[v][0] > dist[u][0] + weight)
            {
                if (dist[v][0] != MAX)
                    setds.erase(setds.find(make_pair(dist[v][0], v)));
 
                dist[v][0] = dist[u][0] + weight;
                setds.insert(make_pair(dist[v][0], v));
            }
        }
    }

    sort all(dist);
    int d = 0;
    REP(i,V){
    	cout << dist[i][1]+1 << " ";
    	d = d + dist[i][0] % mod; 
    }
    cout << "\n" << d <<  "\n";   
    return;
}



int main(){
	fast_io;
	int n,m;
	cin >> n >> m;
	Graph g(n);
	vi t(3);

	while(1){
		cin >> t[0];
		if(t[0]==0)break;
		else{
			cin >> t[1] >> t[2];
			t[0]--;
			t[1]--;
			g.addEdge(t[0],t[1],t[2]);
			g.addEdge(t[1],t[0],t[2]);
		}
	}

	g.sd(m-1);
	return 0;
}