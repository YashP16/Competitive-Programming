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

int main(){
	fast_io;
	cin.tie(NULL);
    int l,k,x,y;
    cin >> l >> k;
    int qx,qy;
    cin >> qx >> qy;
    int count=0,e=l-qy,w=qy-1,s=qx-1,n=l-qx,sw=min(qx-1,qy-1),se=min(qx-1,l-qy),ne=min(l-qx,l-qy),nw=min(l-qx,qy-1);
    
    REP(i,k){
        cin >> x >> y;  
        if(qx-x == 0){
            if(y - qy <0 && abs(y-qy)<w)w=abs(y-qy)-1;  
            else if(y-qy>0 && abs(y-qy)<e)e=abs(y-qy)-1;
        }
        else if(qy-y == 0){
            if(x - qx <0 && abs(x-qx)<s)s=abs(x-qx)-1;  
            else if(x-qx>0 && abs(x-qx)<n)n=abs(x-qx)-1;
        }
        else if(abs(qy-y)==abs(qx-x)){
            if(x-qx<0){
                if(y - qy <0 && abs(y-qy)<sw)sw=abs(y-qy)-1;  
                else if(y-qy>0 && abs(y-qy)<se)se=abs(y-qy)-1;
            }
            else if(x-qx>0){
                if(y - qy <0 && abs(y-qy)<nw)nw=abs(y-qy)-1;  
                else if(y-qy>0 && abs(y-qy)<ne)ne=abs(y-qy)-1;
            }
            
        }
    }   
    
    count = e + w + n + s + ne + nw + se + sw;
    cout << count << "\n";
	return 0;
}