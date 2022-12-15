#include <bits/stdc++.h>

using namespace std;

//recursion
int minSteps(int n){
    if(n <= 1) return 0;

    int x = minSteps(n-1);

    int y=INT_MAX,z=INT_MAX;
    if(n%2 == 0) y = minSteps(n/2);
    if(n%3 == 0) z = minSteps(n/3);

    int ans = min(x,min(y,z))+1;
    return ans;
}

// top down dp/memorization
int minSteps2(int n,int *arr){
    if(n <= 1) return 0;
    if(arr[n] != -1) return arr[n];

    int x = minSteps2(n-1,arr);

    int y=INT_MAX,z=INT_MAX;
    if(n%2 == 0) y = minSteps2(n/2,arr);
    if(n%3 == 0) z = minSteps2(n/3,arr);

    int ans = min(x,min(y,z))+1;
    arr[n] = ans;

    return ans;
}

//bottom up dp/iterative
int minSteps3(int n){
    int *dp = new int[n+1];
    dp[0]=dp[1]=0;

    for(int i=2; i<=n; i++){
        int x = dp[i-1];

        int y=INT_MAX,z=INT_MAX;
        if(i%2 == 0) y = dp[i/2];
        if(i%3 == 0) z = dp[i/3];

        int output = min(x,min(y,z))+1;
        dp[i] = output;
    }

    int ans = dp[n];
    delete []dp;
    return ans;
}

int main(){

    int n;
    cin >> n;

    int *arr = new int[n+1];
    for(int i=0; i<=n; i++) arr[i] = -1;

    cout << minSteps3(n) << endl;
    cout << minSteps2(n,arr) << endl;
    cout << minSteps(n) << endl;

    return 0;
}
