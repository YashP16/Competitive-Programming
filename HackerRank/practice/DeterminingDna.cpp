#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stack>
#include <limits>
#include <vector>
#include <stack>
#include <sstream>
#include <queue>
#include <utility> // for pair
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(int i=a;i<b;i += c)
#define FORd(i,a,b,c) for(int i=a;i>=b;i -=c)
#define vi vector<ll>
#define vii vector<vector<ll> >
#define ll long long int //range -> 9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
#define PB push_back
#define sz size()
#define InF  2147483647
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> genes(n);
    for(int genes_i = 0; genes_i < n; genes_i++){
       cin >> genes[genes_i];
    }
    vector<int> health(n);
    for(int health_i = 0; health_i < n; health_i++){
       cin >> health[health_i];
    }
    int s;
    cin >> s;
    int max = 0;
    int min = InF;
    for(int a0 = 0; a0 < s; a0++){
        int first;
        int last;
        string d;
        cin >> first >> last >> d;
        int temp = 0;
        REP(i,d.length()){
            FOR(j,first,last+1,1){
                if(d[i]==genes[j][0]){
                    if(genes[j].length()>1){
                        if(i+genes[j].length() -1 < n){
                            string sub = d.substr(i,genes[j].length());
                            if(sub == genes[j]){
                                temp += health[j];
                            }
                        }  
                    }
                    else temp+= health[j];
                }
            
            }
        }
        if(temp < min)min = temp;
        if(temp > max) max = temp;
    }
    cout << min << " " << max << endl;
    return 0;
}