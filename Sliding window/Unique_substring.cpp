#include <bits/stdc++.h>

using namespace std;

string unique_substring(string str){

    int i=0,j=0,window_len=0,max_window_len=0,start_window=-1,len=str.size();
    char ch;
    unordered_map<char,int> m;

    while(j < len){
        ch = str[j];

        if(m.count(ch) && m[ch]>=i){
            i = m[ch] + 1;
            window_len = j - i;
        }

        m[ch] = j;
        window_len++;
        j++;

        if(window_len > max_window_len){
            max_window_len = window_len;
            start_window = i;
        }
    }

    return str.substr(start_window,max_window_len);

}

int main(){

    string input;
    cin >> input;

    cout << unique_substring(input) << endl;

    return 0;
}
