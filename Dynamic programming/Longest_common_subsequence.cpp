#include <bits/stdc++.h>

using namespace std;

//recursion
int lcs(string s1,int i,string s2,int j){
    if(i==s1.size() || j==s2.size()) return 0;

    if(s1[i] == s2[j])
        return lcs(s1,i+1,s2,j+1)+1;
    return max(lcs(s1,i+1,s2,j),lcs(s1,i,s2,j+1));
}

//dp
int lcs2(string s1,string s2){
    int n=s1.size(),m=s2.size();
    int dp[m+1][n+1];

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0) dp[i][j] = 0;
            else if(s2[i-1] == s1[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return dp[m][n];
}

int main(){
    string s1,s2;
    cin >> s1 >> s2;

    cout << lcs2(s1,s2) << endl;
    cout << lcs(s1,0,s2,0) << endl;

    return 0;
}
