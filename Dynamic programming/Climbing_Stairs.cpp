#include <bits/stdc++.h>

using namespace std;

//recursion
int countSteps(int n){
    if(n==0 || n==1) return 1;

    return countSteps(n-1) + countSteps(n-2);
}

//top down dp/memorization
int countSteps2(int n,int *arr){
    if(n==0 || n==1) return 1;

    if(arr[n] != 0) return arr[n];

    int ans = countSteps2(n-1,arr) + countSteps2(n-2,arr);
    arr[n] = ans;
    return ans;
}

//bottom up dp/iterative
int countSteps3(int n){
    int dp[n+1];
    dp[0]=dp[1]=1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main(){
    int n;
    cin >> n;

    int arr[n+1];
    for(int i=0; i<=n; i++) arr[i] = 0;
    arr[0]=arr[1]=1;

    cout << countSteps3(n) << endl;
    cout << countSteps2(n,arr) << endl;
    cout << countSteps(n) << endl;

    return 0;
}
