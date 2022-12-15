#include <bits/stdc++.h>

using namespace std;

int lis(vector<int> &v,int n,int i,vector<int> &dp){
    if(i >= n) return 1;

    if(dp[i] != 0) return dp[i];

    int ans = INT_MIN,output = 0;
    for(int x=i+1; x<=n; x++){
        if(v[i] < v[x]){
            output = lis(v,n,x,dp) + 1;
        }
        ans = max(ans,output);
    }

    dp[i] = ans;
    return ans;
}

int main(){

    vector<int> v = {50,4,10,8,30,100};
    int n = v.size() - 1;

    vector<int> dp(n,0);

    int ans = INT_MIN;
    for(int i=0; i<=n; i++){
        ans = max(ans,lis(v,n,i,dp));
    }
    cout << ans << endl;

    return 0;
}
