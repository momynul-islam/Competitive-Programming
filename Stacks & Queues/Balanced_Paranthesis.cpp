#include <bits/stdc++.h>

using namespace std;

bool isOpen(char ch){
	if(ch == '(' || ch == '{' || ch == '[')
		return true;
	return false;
}

bool matchPattern(char c,char v){
	if(c == '(' && v == ')')
		return true;
	else if(c == '{' && v == '}')
		return true;
	else if(c == '[' && v == ']')
		return true;
	else
		return false;
}

int main(){
	string str;
	cin >> str;

	stack<char> s;
	
	for(int i=0; i<str.size(); i++){
		if(isOpen(str[i]))
			s.push(str[i]);
		else{
			if(s.empty()){
				cout << "NO" << endl;
				return 0;
			}
			else if(matchPattern(s.top(),str[i]))
				s.pop();
			else{
				cout << "NO" << endl;
				return 0;
			}
		}
	}	

	if(s.empty())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	
	return 0;
}