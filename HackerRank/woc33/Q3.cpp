#include <bits/stdc++.h>

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e9)
#define REP(i,n) for(int  i=0;i<(n);i++)
#define FOR(i,a,b,c) for(int i=a;i<b;i += c)
#define FORd(i,a,b,c) for(int i=a;i>=b;i -=c)
#define all(v) ((v).begin(),(v).end())
#define vi vector<ll>
#define vii vector<vector<ll> >
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
#define fast_io ios_base::sync_with_stdio(false)
#define SQR(n) ((n)*(n))
#define MEM(a,val) memset(a,val,sizeof(a))
using namespace std;


int lps(vector <int> &s,vector<int> &val){
   int len = s.size();
   int i, j, cl;
   int L[len][len]; 

   for (i = 0; i < len; i++)
      L[i][i] = 1;

    for (cl=2; cl<=len; cl++)
    {
        for (i=0; i<len-cl+1; i++)
        {
            j = i+cl-1;
            if ((val[s[i]] == val[s[j]] )  && cl == 2)
               L[i][j] = 2;
            
            else if (val[s[i]] == val[s[j]])
               L[i][j] = L[i+1][j-1] + 2;
            
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }
    return L[0][len-1];
}

int main(){
	fast_io;
	cin.tie(NULL);
	int n,k,m,x,y;
	cin >> n >> k >> m;
	vector< vector<int> > e(n+1);
	vector <int> s(m);
	
	while(k--){
		cin >> x >> y;
		e[x].PB(y);
		e[y].PB(x);
	}
	
	REP(i,m)cin >>s[i];

	bool color[n+1] ={0};
	vector<int> val(n+1);
	REP(i,n)val[i+1]=i+1;
	FOR(i,1,n+1,1){
		if(color[i]!=1){
			stack <int> st;
	 		st.push(i);
	 		color[i]=1;
	 		val[i]=i;
	 		while(!st.empty()){
	 			int t = st.top();
	 			if(!e[t].empty()){
	 				if(color[e[t][0]]==0){
	 					val[e[t][0]]=i;
	 					st.push(e[t][0]);
	 					color[e[t][0]] = 1;
	 				}
	 				e[t].erase(e[t].begin(),e[t].begin()+1);
	 			}
		 		else{
		 			st.pop();
		 		}
	 		}
	 	}
	}
	
	int count = lps(s,val);
	cout << count << "\n";

	return 0;
}