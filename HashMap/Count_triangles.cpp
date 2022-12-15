#include <bits/stdc++.h>

using namespace std;

int count_triangles(vector<pair<int,int>> &points){
    unordered_map<int,int> freq_x;
    unordered_map<int,int> freq_y;

    for(auto p:points){
        freq_x[p.first]++;
        freq_y[p.second]++;
    }

    int cnt = 0;
    for(auto p:points){
        int fx = freq_x[p.first];
        int fy = freq_y[p.second];

        cnt += (fx-1)*(fy-1);
    }
    return cnt;
}

int main(){
    int n;
    cin >> n;

    vector<pair<int,int>> points;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        points.push_back({x,y});
    }

    cout << count_triangles(points) << endl;
}
