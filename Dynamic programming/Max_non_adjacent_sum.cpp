#include <bits/stdc++.h>

using namespace std;

int maxSumNoadjacent(vector<int> &v,int n,int i,vector<int> &dp){
    if(i > n) return 0;

    if(dp[i] != 0) return dp[i];

    int ans = max(maxSumNoadjacent(v,n,i+2,dp) + v[i] , maxSumNoadjacent(v,n,i+1,dp) + 0);

    dp[i] = ans;
    return dp[i];
}

int main(){

    vector<int> v = {6,10,12,7,9,14};
    int n = v.size() - 1;

    vector<int> dp(n+1,0);

    cout << maxSumNoadjacent(v,n,0,dp) << endl;

    return 0;
}
