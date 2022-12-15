#include <bits/stdc++.h>
#include <sstream>

using namespace std;

string simplyfi_path(string path){
	istringstream iss(path);
	vector<string> tokens;
	string token;

	while(getline(iss,token,'/')){
		if(token=="." || token=="")
			continue;
		tokens.push_back(token);
	}

	vector<string> stack;
	if(path[0]=='/')
		stack.push_back("");
	for(auto t:tokens){
		if(t == ".."){
			if(stack.size()==0 || stack[stack.size()-1]=="..")
				stack.push_back(t);
			else if(stack[stack.size()-1] != "")
				stack.pop_back();
		}else
			stack.push_back(t);
	}

	if(stack.size()==1 && stack[0]=="")
		return "/";

	ostringstream oss;
	int i=stack.size()-1;
	for(auto s:stack){
		if(s == stack[i])
			oss << s;
		else
			oss << s << "/";
	}
	
	return oss.str();
}

int main(){

	string path = "/../x/y/../z/././w/a///../../c/./";
	cout << simplyfi_path(path) << endl;	
	
	return 0;
}