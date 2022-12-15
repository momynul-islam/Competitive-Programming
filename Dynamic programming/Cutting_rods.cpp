#include <bits/stdc++.h>

using namespace std;

//recursion
int rod_cutting(int n,vector<int> &price){
    if(n == 0) return 0;

    int ans = INT_MIN;
    for(int i=1; i<=price.size(); i++){
        if(n-i >= 0)
            ans = max(ans,rod_cutting(n-i,price) + price[i]);
    }
    return ans;
}

//top down dp
int rod_cutting2(int n,vector<int> &price,int *dp){
    if(n == 0) return 0;

    if(dp[n] != -1) return dp[n];

    int ans = INT_MIN;
    for(int i=1; i<=price.size(); i++){
        if(n-i >= 0)
            ans = max(ans,rod_cutting2(n-i,price,dp) + price[i]);
    }
    dp[n] = ans;
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> price(10);
    price = {0,3,5,8,9,10,17,17,20};

    int dp[1000];
    memset(dp,-1,sizeof(dp));

    cout << rod_cutting(n,price) << endl;
    cout << rod_cutting2(n,price,dp) << endl;

    return 0;
}
