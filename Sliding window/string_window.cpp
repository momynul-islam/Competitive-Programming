#include <bits/stdc++.h>

using namespace std;

string string_window(string s,string p){

    int fp[256]={0}, fs[256]={0};

    for(int i=0; i<p.length(); i++)
        fp[p[i]]++;

    int cnt=0, start=0, start_idx=-1, min_so_far=INT_MAX, window_size;
    char ch;

    for(int i=0; i<s.size(); i++){

        ch = s[i];
        fs[ch]++;

        if(fp[ch] !=0 && fs[ch] <= fp[ch])
            cnt++;

        if(cnt == p.length()){

            while(fp[s[start]]==0 || fs[s[start]] > fp[s[start]]){
                fs[s[start]]--;
                start++;
            }

            window_size = i-start+1;
            if(window_size < min_so_far){
                min_so_far = window_size;
                start_idx = start;
            }
        }
    }

    if(start_idx == -1)
        return "No Window Found";
    return s.substr(start_idx,min_so_far);
}

int main(){

    string s,p;
    cin >> s >> p;

    cout << string_window(s,p) << endl;

    return 0;
}
