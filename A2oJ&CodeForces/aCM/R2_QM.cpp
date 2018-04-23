#include <bits/stdc++.h>

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX long long int(1e9)
#define MIN long long int(-1e9)
#define vi vector<long long int>
#define vb vector<bool>
#define vvi vector<vector<long long int> >
#define vii vector<pair<long long int,long long int> >
#define lli long long long long int //range -> 9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define F first
#define S second
#define PB push_back
#define sz size()
#define InF  2147483647
#define fast_io ios_base::sync_with_stdio(false)
using namespace std;
int main()
{
	fast_io;
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	std::vector<int> a(n);
	int sum=0;
	int x=-2;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		sum+=a[i];
		if(a[i]==0 && x==-2)
			x=i-1;
	}
	if(sum>=n)
	{
		cout<<"NO";
		return 0;
	}
	string out="";
	if(x==-1 || x==-2)
	{
		cout<<"YES\n";
		return 0;
	}
	for (int i = n-1; i>=0; i--)
	{
		if(a[i]>0)
		{
			cout<<"NO";
			return 0;
		}
		a[x]--;
		out+="\n" + to_string(x+1)+" "+to_string(i+1);
		if(a[x]==0)
			x--;
		if(x==-1)
		{
			cout<<"YES"<<out;
			return 0;
		}
	}
	if(x==-1)
		cout<<"YES"<<out;
	return 0;

}