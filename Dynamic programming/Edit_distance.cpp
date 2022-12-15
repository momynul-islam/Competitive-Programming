#include <bits/stdc++.h>

using namespace std;

//recursion
int minDistance(string a,int n,string b,int m){
    if(n == 0) return m;
    if(m == 0) return n;

    if(a[n-1] == b[m-1]) return minDistance(a,n-1,b,m-1);

    int i = minDistance(a,n,b,m-1);
    int d = minDistance(a,n-1,b,m);
    int r = minDistance(a,n-1,b,m-1);

    return min(i,min(d,r)) + 1;
}

//dp
int minDistance2(string a,string b){
    int n=a.size(),m=b.size();
    int dp[n+1][m+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else{
                int i = dp[i][j-1];
                int d = dp[i-1][j];
                int r = dp[i-1][j-1];
                dp[i][j] = min(i,min(d,r))+1;
            }
        }
    }
    return dp[n][m];
}

int main(){
    string a,b;
    cin >> a >> b;

    cout << minDistance2(a,b) << endl;
    cout << minDistance(a,a.size(),b,b.size()) << endl;

    return 0;
}
