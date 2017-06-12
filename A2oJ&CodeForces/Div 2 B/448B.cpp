// NEW CONCEPT 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>
using namespace std;
typedef long long ll;


const int N = 1e5+5;

int cnt[30];


void solve(){
    //scanf("%s%s",&s,&t);
	string s,t;
	cin >> s >> t;
    int n = s.length();
    int m = t.length();
    
    memset(cnt, 0, sizeof cnt);
    
    bool sau = false;
    for(int i=0,j=0; i<n; ++i){
        if(j<m && s[i]==t[j]) ++j;
        if(j==m) sau = true;
    }
    
    for(int i=0;i<n;++i) cnt[s[i]-'a']++;
    for(int i=0;i<m;++i) cnt[t[i]-'a']--;
    
    bool sar = true;
    bool all = true;
    
    for(int i=0;i<26;++i){
        sar&=cnt[i]==0;
        all&=cnt[i]>=0;
    }
    
    if(sau) cout<<"automaton"<<endl; else
    if(sar) cout<<"array"<<endl; else
    if(all) cout<<"both"<<endl; else
    cout<<"need tree"<<endl;
}

int main(){
    //freopen("input.txt","r",stdin);// freopen("output.txt","w",stdout);
    
    solve();
    
    return 0;
}