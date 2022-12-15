#include <bits/stdc++.h>

using namespace std;

void subsequences(string s,string o,vector<string> &v){
    //base case
    if(s.size() == 0){
        v.push_back(o);
        return;
    }

    char ch = s[0];
    string reduced_input = s.substr(1);
    //includes
    subsequences(reduced_input,o + ch,v);
    //excludes
    subsequences(reduced_input,o,v);
}

bool compare(string s1,string s2){
    if(s1.length() == s2.length())
        return s1 < s2;
    return s1.length() < s2.length();
}

int main(){

    string str,output = "";
    cin >> str;

    vector<string> v;
    subsequences(str,output,v);

    sort(v.begin(),v.end(),compare);

    for(auto s : v)
        cout << s << ",";

    return 0;
}
