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

int searchCount(vi &numbers, int target){
	int low = 0, high = numbers.sz - 1;

	int startIndex = -1;
    while (low <= high) 
    {
        int mid = (high - low) / 2 + low;
        if (numbers[mid] > target) 
        {
            high = mid - 1;
        }
        else if (numbers[mid] == target) 
        {
            startIndex = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    int endIndex = -1;
    low = 0;
    high = numbers.sz - 1;
    while (low <= high) 
    {
        int mid = (high - low) / 2 + low;
        if (numbers[mid] > target) 
        {
            high = mid - 1;
        }
        else if (numbers[mid] == target) 
        {
            endIndex = mid;
            low = mid + 1;
        }
        else
            low = mid + 1;
    }

    if(endIndex!=-1 && startIndex!=-1)
    	return endIndex-startIndex+1;
    else return 0;
}


int main(){
	fast_io;
	int n;
	int x,y= 0;
	cin >> n;
	vi ps(n);

	REP(i,n){
		cin >> x;	
		ps[i] = x+y;
		y = ps[i];
	}

	if(ps[n-1]%3 != 0 || n<2) cout << 0 << "\n";
	else{
		int c = 0;
		int l =ps[n-1]/3; 
		c+=searchCount(ps,l);
		if(c>=1){
			int d = 0;
			d+=searchCount(ps,2*l);
			if(d>0){
				int e = searchCount(ps,3*l);
				if(e>0) cout << c*d << "\n";
				else cout << 0 << "\n";
			}
			else cout << 0 << "\n";
		}
		else cout << 0 << "\n";
	}
	return 0;
}