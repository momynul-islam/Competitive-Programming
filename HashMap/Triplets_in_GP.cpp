#include <bits/stdc++.h>

using namespace std;

int count_triplets(vector<int> v,int r){
    int n = v.size();
    unordered_map<long long,long long> right,left;

    for(auto x:v){
        right[x]++;
        left[x] = 0;
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        right[v[i]]--;
        if(v[i]%r == 0){
            long long a = v[i];
            long long b = v[i]/r;
            long long c = v[i]*r;

            ans += left[b] * right[c];
        }
        left[v[i]]++;
    }
    return ans;
}

int main(){
    int n,r;
    cin >> n >> r;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    cout << count_triplets(v,r) << endl;

    return 0;
}
