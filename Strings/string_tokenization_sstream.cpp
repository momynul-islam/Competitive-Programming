#include <bits/stdc++.h>

using namespace std;

int main(){
    string str,token;
    getline(cin,str);
    vector<string> tokens;
    stringstream ss(str);
    while(getline(ss,token,' ')){
        tokens.push_back(token);
    }
    for(auto s : tokens)
        cout << "\"" <<s << "\"" << " ";
    cout << endl;
    return 0;
}
