#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,temp,ans=0;
    cin >> n;
    vector<int> v;
    vector<bool> visited(n,false);
    pair<int,int> p[n];
    for(int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
        p[i].first = temp;
        p[i].second = i;
    }
    sort(p,p+n);
    for(int i=0; i<n; i++){
        int old_position = p[i].second;
        if(visited[i] == true || old_position == i)
            continue;
        int node = i,cycle = 0;
        while(visited[node] != true){
            visited[node] = true;
            node = p[node].second;
            cycle++;
        }
        ans += cycle-1;
    }
    cout << ans << endl;
    return 0;
}
