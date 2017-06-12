#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(int i=a;i<b;i += c)
#define FORd(i,a,b,c) for(int i=a;i>=b;i -=c)
#define vi vector<ll>
#define vii vector<vector<ll> >
#define ll long long int //range -> –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
using namespace std;

string compStr(string b,string a){
	int x = 0;
	string temp1 = "";
	while(b[x] == a[x] && x < b.length()  && x < a.length()){
		temp1+= b[x];
		if(x==b.length()-1){
			return "~";
		}
		x++;
	}
	if(x < b.length())temp1+= b[x];
	return temp1;
}

int main(){
	int n;
	cin >> n;
	vector< pair<string,bool> > full;
	vector <string> ans;	
	int flag = 1;
	int active =0;
	while(n--){
		char c;
		cin >> c;
		string s;
		cin >>s;
		if(c == '+'){
			active++;
			full.push_back(make_pair(s,1));
		}
		else full.push_back(make_pair(s,0));
	}
	if(full.size() >1)sort(full.begin(),full.end());

	if(active ==0 ){
		string prev = "";
		REP(i,full.size()){
			if(full[i].first[0]!= prev[0]){
				prev =  full[i].first[0];
				ans.push_back(prev);
			}
		}
	}

	else{
		string prev = "";
		string temp3 ="!";
		int prevC =0;
		FOR(i,0,full.size(),1){
			if(full[i].second == 0){
				int fg =1;
				if(i!= 0)temp3= full[i].first.substr(0,prevC);
				int next= i+1,pre=i-1;
				string temp1 ="", temp2 ="";
				while(pre>-1 && full[pre].second == 0)pre--;
				while(next<full.size() && full[next].second==0)next++;
				if(i-pre > 1 && i != 0){
					if(temp3 == prev){
						fg = 0;
					}
				}
				if(fg == 1){
					if(pre == -1){
						temp1 = compStr(full[i].first,full[next].first);
						if(temp1[0]=='~'){
							flag = 0;
							break;
						}

						else if(flag != 0){
							ans.push_back(temp1);
							prev = temp1;
							prevC = temp1.length();
						}	
					}
					else if(next==full.size()){
						temp2= compStr(full[i].first,full[pre].first);
						if(temp2[0]=='~'){
							flag = 0;
							break;
						}
						
						else if(flag != 0){
							ans.push_back(temp2);
							prev = temp2;
							prevC = temp2.length();
						}
					}
					else{
						temp1 = compStr(full[i].first,full[next].first);
						temp2= compStr(full[i].first,full[pre].first);
						if(temp1[0]=='~' || temp2[0]=='~'){
							flag = 0;
							break;
						}
						else if(temp1 >= temp2){
							if(flag != 0){
								ans.push_back(temp1);
								prev = temp1;
								prevC = temp1.length();
							}
						}
						else{
							if(flag != 0){
								ans.push_back(temp2);
								prev = temp2;
								prevC = temp2.length();
							}		
						}
					}
				}
			}
		}
	}
	if(flag == 1){
		cout << ans.size() << endl;
		REP(i,ans.size()){
			cout << ans[i] << endl;
		}
	}
	else cout << -1 << endl;

	return 0;
}
