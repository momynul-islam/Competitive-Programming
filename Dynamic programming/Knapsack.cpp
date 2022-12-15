#include <bits/stdc++.h>

using namespace std;

//recursive
int knapsack(int *price,int *weights,int W,int n){
    if(n==0 || W==0) return 0;

    if(weights[n-1] > W) return knapsack(price,weights,W,n-1);
    else{
        int inc = price[n-1] + knapsack(price,weights,W-weights[n-1],n-1);
        int exc = knapsack(price,weights,W,n-1);
        return max(inc,exc);
    }
}

//dp
int knapsack2(int *price,int *weights,int w,int n){
    int dp[n+1][w+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=w; j++){
            if(i==0 || j==0) dp[i][j] = 0;
            else if(weights[i-1] > j) dp[i][j] = dp[i-1][j];
            else{
                int inc = price[i-1] + dp[i-1][j-weights[i-1]];
                int exc = dp[i-1][j];
                dp[i][j] = max(inc,exc);
            }
        }
    }
    return dp[n][w];
}

int main(){
    int n,w;
    n=3;
    w=50;

    int price[n] = {60,100,120};
    int weights[n] = {10,20,30};

    cout << knapsack2(price,weights,w,n) << endl;
    cout << knapsack(price,weights,w,n) << endl;

    return 0;
}
