#include <bits/stdc++.h>

using namespace std;

bool compare(vector<int> a,vector<int> b){
    return a[2] < b[2];
}

bool canPlace(vector<int> a,vector<int> b){
    return (a[0] < b[0]) && (a[1] < b[1]);
}

int boxStacking(vector<vector<int>> &v){
    sort(v.begin(),v.end(),compare);

    vector<int> dp(v.size(),0);
    for(int i=0; i<dp.size(); i++) dp[i] = v[i][2];

    for(int i=0; i<dp.size(); i++){
        for(int j=0; j<i; j++){
            if(canPlace(v[j],v[i])){
                int current_height = v[i][2];

                if(dp[j] + current_height > dp[i])
                    dp[i] = dp[j] + current_height;
            }
        }
    }

    int maxHeight = 0;
    for(int i=0; i<dp.size(); i++){
        if(maxHeight < dp[i])
            maxHeight = dp[i];
    }

    return maxHeight;
}

int main(){

    vector<vector<int>> boxes = {
                                    {2,1,2},
                                    {3,2,3},
                                    {2,2,8},
                                    {2,3,4},
                                    {2,2,1},
                                    {4,4,5}
                                };
    cout << boxStacking(boxes) << endl;

    return 0;
}
