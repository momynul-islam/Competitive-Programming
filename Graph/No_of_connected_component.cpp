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
    int n = g.size(),cnt = 0;
    vector<bool> visited(n,false);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            printBFS(g,visited,i,n);
            cnt++;
        }
    }
    cout << "No. of connected component is -> " << cnt << endl;
}

void printDFS(vector<vector<int>> g,int s,vector<bool> &visited){
    cout << s << endl;
    visited[s] = true;
    int n = g.size();

    for(int i=0; i<n; i++){
        if(g[s][i]==1 && visited[i]==false)
            printDFS(g,i,visited);
    }
}

void DFS(vector<vector<int>> g){
    int n = g.size(),cnt = 0;
    vector<bool> visited(n,false);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            printDFS(g,i,visited);
            cnt++;
        }
    }
    cout << "No. of connected component is -> " << cnt << endl;
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

    cout << "DFS : " << endl;
    DFS(g);
    cout << "BFS : " << endl;
    BFS(g);

    return 0;
}



