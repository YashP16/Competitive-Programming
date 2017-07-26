// Using Union find algorithm 
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
#define fast_io ios_base::sync_with_stdio(false)
#define SQR(n) ((n)*(n))
#define MEM(a,val) memset(a,val,sizeof(a))
using namespace std;

int findParent(int i,vi parent){
    if(parent[parent[i]]!=parent[i])
        parent[i]=findParent(parent[i],parent);
    return parent[i];
}

void unionNodes(int a,int b,vi &parent,vi &size){
    int parent_a=findParent(a,parent),parent_b=findParent(b,parent);
    if(parent_a==parent_b)return;
    
    if(size[parent_a]>=size[parent_b]){
         size[parent_a]+=size[parent_b];
         parent[parent_b]=parent_a;
    }
    else{
         size[parent_b]+=size[parent_a];
         parent[parent_a]=parent_b;
    }
    return;
}

bool haveCommon(vi a,vi b){	
  int i = 0, j = 0;
  while (i < a.size() && j < b.size()){
    if (a[i] < b[j])i++;
    else if (b[j] < a[i])j++;
    else return true;
  }
  return false;
} 


int main(){
	fast_io;
	cin.tie(NULL);
	int n,l;
	cin >> n >> l;
	vii emp(n);
	int count = 0;
	
	bool flag =0;
	REP(i,n){
		int k,x;
		cin >> k;
		if(k != 0){
			while(k--){
				cin >> x;
				emp[i].PB(x);
			}
			sort(emp[i].begin(), emp[i].end());
			flag =1;
		}
	}
	
	vi parent(n),size(n,1);
	REP(i,n)parent[i]= i;

	REP(i,n-1){
		if(emp[i].size() > 0){
			FOR(j,i+1,n,1){
					if(haveCommon(emp[i],emp[j])){
					unionNodes(i,j,parent,size);		
				}

			}
		}
	}
	int nos=0;
	for(int i=0;i<n;i++){
        if(findParent(i,parent)==i)nos++;
    }
	
	if(nos == n && flag != 1)cout << nos << "\n";
	else cout << nos-1 << "\n";
	return 0;
}