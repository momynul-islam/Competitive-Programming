#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,temp,cnt=0,largest_cnt=1;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }
    set<int> s;
    for(auto i : v)
        s.insert(i);
    for(auto element : s){
        int parent = element - 1;
        if(s.find(parent) == s.end()){
            cnt = 1;
            element = element + 1;
            while(s.find(element) != s.end()){
                cnt++;
                element += 1;
            }
            if(cnt > largest_cnt)
                largest_cnt = cnt;
        }
    }
    cout << largest_cnt << endl;
/*
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++){
        if(v[i+1] - v[i] == 1){
            cnt++;
        }
        else{
            cnt++;
            if(largest_cnt < cnt)
                largest_cnt = cnt;
            cnt = 0;
        }
    }
    cout << largest_cnt << endl;
*/
    return 0;
}
