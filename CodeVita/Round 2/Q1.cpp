#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
using namespace std;
#include <algorithm>

string revString(string S){
	char temp;
	temp = S[1];
	S[1]=S[0];
	S[0]= temp;
	return S;
	}

int hexTochar (string s){
	int temp, temp1;
	if( '0' <= s[0] && s[0] <= '9') {
		temp = s[0]- '0';
	} 
	else {
		 temp = s[0]-'A' +10;
	}
	if( '0' <= s[1] && s[1] <= '9') {
		temp1 = s[1]- '0';
	} 
	else {
		 temp1 = s[1]-'A' +10;
	}
	return temp+temp1;  
}

int main(){
	char ans;
	std :: cin >> ans;
	if(ans == 'E'){
		string S;
		getline(cin,S);
		getline(cin,S);
		string id;
		cin >> id;
		int n = id.length();
		stringstream ss;
		ss << n <<"-"<<id;
		string result;
		result = ss.str();
		cout << result;
		for(int i =0; S[i]!='\0'; i++){
			cout <<"-";
			stringstream s1;
			s1 << hex << uppercase << (int)S[i];
			string temp;
			temp=revString(s1.str());	
			cout << temp;
			}
		
	}

	else if(ans =='D'){
		string T;
		getline(cin,T);
		getline(cin,T);
		unsigned int counter = 0;
		int flag = 0;
		while(T[counter] != '\0'){
			string t1;
			while( (T[counter] != '-') && T[counter] != '\0'){
				t1 = t1 + T[counter];
				counter++;
			 }
			 if(flag == 0){
				flag++;
			}
			else if(flag == 1){
				cout << t1 << endl;
				flag++;
			}
			else{
				t1 = revString(t1);
				int x = hexTochar(t1);
				cout <<(char) x;
			}
			counter++;
		}
	}
	return 0;
}