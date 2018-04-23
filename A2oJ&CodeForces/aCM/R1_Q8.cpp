#include <bits/stdc++.h>

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e9)
#define REP(i,n) for(ll i=0;i<(n);i++)
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

int DP(int s,int pos, vector < vector < pair< pair<int,int>,int> > > &d)
{
	if(s>=1000000)
		return 0;
	int j = s+1;
	while(d[j].empty() && j <= 1000000)j++;
	if(!d[s].empty())
	{
		if(d[s][pos].S==-1)
		{
			/*if(d[s].size()==pos)
			{
				d[s][pos].S=DP(s+1,0,d);
				return d[s][pos].S;
			}*/
			
			int val;
			if(d[s].size()>pos)
			{
				if(d[s].size()==pos+1)
					val=DP(j,0,d);
				else
					val=DP(s,pos+1,d);
			}
			else
			{
				val=DP(j,0,d);
			}
			d[s][pos].S=max(val,DP(s+d[s][pos].F.S,0,d)+d[s][pos].F.F);
			return d[s][pos].S;
		}
		else
		{
			return d[s][pos].S;
		}

	}
	else
		return DP(j,0,d);
}

int main(){
	int n ;
	cin >> n;
	vector <vector <pair<pair<int,int>,int> > > d(1000001);
	int x,y,z;
	
	REP(i,n){
		cin >> x >> y >> z;
		pair <int,int> a = make_pair(y,z);
		d[x].PB(make_pair(a,-1));
	}
	cout << DP(0,0,d);
}