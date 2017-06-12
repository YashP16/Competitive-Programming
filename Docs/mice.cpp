#include <bits/stdc++.h>
using namespace std;

//type helpers

#define ll long long
#define vi vector <int>
#define vl vector <ll> 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector <pii >
#define vpll vector <pll >
//debugging
#define debug(x) cout<<"debugging "<<x<<endl

//loops
#define FOR(i,a,b) for(ll i=a;i<b;++i)
#define FORD(i,a,b) for(ll i=a-1;i>=b;--i)
#define iter(it, s) for(auto it=s.begin(); it!=s.end(); ++it)

//io helpers
#define sd(n) scanf("%d", &n)
#define sld(n) scanf("%ld",&n)
#define sll(n) scanf("%lld", &n)
#define slf(n) scanf("%lf", &n) 
#define pd(n) printf("%d", n)
#define pld(n) printf("%ld", n)
#define plld(n) printf("%lld", n)
#define plf(n) printf("%0.9lf", n)
#define pstr(s) printf("%s\n",s);
#define ps printf(" ")
#define pn printf("\n")


//ds helpers
#define f first
#define s second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define sz(n) (ll)n.size()


//fast input and output when using cin,cout
#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
//some constants
const int INF = 1<<29;
#define MOD 1000000007
#define PI 3.14159265358979323846
#define EPS 0.0000000001
#define max_size 10000005

//some helper functions
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9;}
inline ll lcm(ll a,ll b){ return (a*b)/(__gcd(a,b));}
#define mod(a) ((a)%MOD)
inline ll ciel(double a) { ll ret = a; if(a-ret>EPS) ret++; return ret; }
inline ll powf(ll n, ll p) {if(p==0)return 1; if(n<=1)return n;ll res = 1;while(p){if(p&1) res = mod(res*n);n = mod(n*n);p /= 2;} return res;}
inline bool ispoweroftwo(ll x){return (x && !(x&(x-1)));}



ll c( int n, ll k )
{
    if (k > n) return 0;
    
    if (k * 2 > n) k = n-k;
    
    if (k == 0) return 1;

    int result = n;
    
    for( int i = 2; i <= k; ++i ) 
    {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int main(){
	
	int n;

	sd(n);
	ll k,a[n],t=0,j,total=0,temp;
    sll(k);
	FOR(i,0,n) sll(a[i]);

	sort(a,a+n);

//	FOR(i,0,n) b[i]=k/a[i];

	FOR(i,0,n)
	{
		temp = a[i];
		
		if(temp>k) 
		{

		    t++;
		}
		
		FOR(j,i+1,n)
		{

			FOR(o,i+1,j)
			{

			    temp *= a[o];
			}
			
			FOR(l,j,n) if(temp*a[l]>k)
			{
				FOR(r,l,n) 
				{

				    t += c(r-i-1 , j-i-1);
				}
				break;
			}

			temp=a[i];

		}

	}

	FOR(i,1,n+1) total+=c(n,i);
    
    cout<<t<<endl;
    cout<<total<<endl;
	plld(total-t);
	pstr("");

	return 0;
}



/*


/*

*/
