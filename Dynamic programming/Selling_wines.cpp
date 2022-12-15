#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &v,int i,int j,int y,vector<vector<int>> &dp){
    if(i == j) return v[i]*y;
    if(i > j) return 0;

    if(dp[i][j] != 0) return dp[i][j];

    int ans = max( maxProfit(v,i+1,j,y+1,dp) + v[i]*y , maxProfit(v,i,j-1,y+1,dp) + v[j]*y );

    dp[i][j] = ans;
    return dp[i][j];
}

int main(){

    vector<int> wines = {2,3,5,1,4};
    int n = wines.size() - 1;

    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    cout << maxProfit(wines,0,n,1,dp) << endl;

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
