#include <bits/stdc++.h>

using namespace std;

int min_jumps(vector<int> &v,int n,int i,vector<int> &dp){
    if(i >= n) return 0;

    if(dp[i] != 0) return dp[i];

    int ans = INT_MAX;
    for(int jump=1; jump<=v[i]; jump++)
        ans = min(ans,min_jumps(v,n,i+jump,dp)+1);

    dp[i] = ans;
    return ans;
}

int main(){

    vector<int> v = {3,10,2,1,2,3,7,1,1,3};
    int n = v.size() - 1;

    vector<int> dp(n,0);

    cout << min_jumps(v,n,0,dp) << endl;

    return 0;
}
