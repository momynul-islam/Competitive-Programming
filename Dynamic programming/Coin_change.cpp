#include <bits/stdc++.h>

using namespace std;

//recursion
int no_coin(int amount,vector<int> &coins){
    if(amount == 0) return 0;

    int ans = INT_MAX;
    for(auto x : coins){
        if(amount - x >= 0)
            ans = min(ans , no_coin(amount-x,coins) + 1);
    }
    return ans;
}

//top down dp
int no_coin2(int amount,vector<int> &coins,int *dp){
    if(amount == 0) return 0;

    if(dp[amount] != -1) return dp[amount];

    int ans = INT_MAX;
    for(auto x : coins){
        if(amount - x >= 0)
            ans = min(ans , no_coin2(amount-x,coins,dp) + 1);
    }
    dp[amount] = ans;
    return ans;
}

int main(){

    vector<int> coins = {1,3,7,10};
    int N;
    cin >> N;

    int dp[1000];
    memset(dp,-1,sizeof(dp));

    cout << no_coin2(N,coins,dp) << endl;
    cout << no_coin(N,coins) << endl;

    return 0;
}
