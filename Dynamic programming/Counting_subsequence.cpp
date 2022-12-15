#include <bits/stdc++.h>

using namespace std;

int countSub(string a,string b,int n,int m,vector<vector<int>> &dp){
    if((n==-1 && m==-1) || m==-1) return 1;
    if(n == -1) return 0;

    if(dp[n][m] != 0) return dp[n][m];

    int ans = 0;
    if(a[n] != b[m]) ans += countSub(a,b,n-1,m,dp);
    else ans += countSub(a,b,n-1,m,dp) + countSub(a,b,n-1,m-1,dp);

    dp[n][m] = ans;
    return dp[n][m];
}

int main(){

    string a = "ABCEGCDGHIH";
    string b = "ABCGH";

    int n=a.size()-1,m=b.size()-1;
    vector<vector<int>> dp(n+2,vector<int>(m+2,0));

    cout << countSub(a,b,n,m,dp) << endl;

    return 0;
}
