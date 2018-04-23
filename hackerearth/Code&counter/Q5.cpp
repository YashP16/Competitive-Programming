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

int main()
{
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vii graph(n),graph2(n);
    string u,v;
    int size=0;
    map<string,int> mapper;
    vector<string> vec;
    set<string> stringer;
    for (int i = 0; i < m; ++i){
        cin>>u>>v;
        stringer.insert(u);
        if(stringer.size()>size)
        {
            vec.push_back(u);
            mapper[u]=size++;
        }
        stringer.insert(v);
        if(stringer.size()>size)
        {
            vec.push_back(v);
            mapper[v]=size++;
        }
        graph[mapper[u]].PB(mapper[v]);
        graph2[mapper[v]].PB(mapper[u]);
    }

    set <string> s;
    vb vis(n,0);
    FOR(i,0,n,1){
        if(graph[i].empty()){
            s.insert(vec[i]);
        }
    } 
    int count = 0;
    while(!s.empty()){
        string k = *s.begin();
        s.erase(s.begin());
        int t = mapper[k];
        FOR(i,0,graph2[t].size(),1){
            s.insert(vec[graph2[t][i]]);

        }
        cout << k;
        count++;
        if(count!= n) cout << " -> ";
    }
    cout << "\n";
}