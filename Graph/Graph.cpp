#include <bits/stdc++.h>

using namespace std;

int main(){
    int v,e;
    cin >> v >> e;

    vector<vector<int>> g(v,vector<int>(v,0));

    for(int i=0; i<e; i++){
        int s,d;
        cin >> s >> d;
        g[s][d] = 1;
        g[d][s] = 1;
    }

    return 0;
}
