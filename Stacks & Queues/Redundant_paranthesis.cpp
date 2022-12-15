#include <bits/stdc++.h>

using namespace std;

bool is_redundant(string str){
	stack<char> s;

	for(auto ch:str){
		if(ch != ')')
			s.push(ch);
		else{
			bool operator_found = false;
			while(!s.empty() && s.top()!='('){
				if(s.top()=='+' || s.top()=='-' || s.top()=='*' || s.top()=='/')
					operator_found = true;
				s.pop();
			}
			s.pop();
			if(!operator_found)
				return false;
		}
	}
	return true;
}

int main(){

	string str = "((a+(b))*c)";

	if(!is_redundant(str))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	
	return 0;
}