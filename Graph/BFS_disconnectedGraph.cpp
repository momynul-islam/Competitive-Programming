#include <bits/stdc++.h>

using namespace std;

void printBFS(vector<vector<int>> g,vector<bool> &visited,int s,int n){
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()){
        int cv = q.front();
        q.pop();
        cout << cv << endl;

        for(int i=0; i<n; i++){
            if(g[cv][i]==1 && visited[i]==false){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(vector<vector<int>> g){
    int n = g.size();
    vector<bool> visited(n,false);
    for(int i=0; i<n; i++){
        if(!visited[i])
            printBFS(g,visited,i,n);
    }
}

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

    cout << "BFS : " << endl;
    BFS(g);

    return 0;
}



