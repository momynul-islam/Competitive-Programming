#include <bits/stdc++.h>

using namespace std;

// top down dp
int frogMinCost(vector<int> &v,int n,int i,vector<int> &dp){
    if(i >= n) return 0;

    if(dp[i] != -1) return dp[i];

    int x = frogMinCost(v,n,i+1,dp) + abs(v[i] - v[i+1]);
    int y = frogMinCost(v,n,i+2,dp) + abs(v[i] - v[i+2]);

    int ans = min(x,y);
    dp[i] = ans;
    return ans;
}

int main(){
    vector<int> v = {30,10,60,10,60,50};
    int n = v.size() - 1;

    vector<int> dp(n,-1);

    cout << frogMinCost(v,n,0,dp) << endl;
}
