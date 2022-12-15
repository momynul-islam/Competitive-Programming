#include <bits/stdc++.h>

using namespace std;

int main(){

    string s1,s2;
    cin >> s1 >> s2;

    int i=s1.size()-1, j=s2.size()-1;

    while(i>=0 && j>=0){
        if(s1[i] == s2[j]){
            i--;
            j--;
        }
        else
            i--;
    }
    if(j < 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
