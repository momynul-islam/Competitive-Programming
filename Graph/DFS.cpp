#include <bits/stdc++.h>

using namespace std;

void printDFS(vector<vector<int>> g,int s,vector<bool> &visited){
    cout << s << endl;
    visited[s] = true;
    int n = g.size();

    for(int i=0; i<n; i++){
        if(g[s][i]==1 && visited[i]==false)
            printDFS(g,i,visited);
    }
}

void DFS(vector<vector<int>> g,int s){
    int n = g.size();
    vector<bool> visited(n,false);

    printDFS(g,s,visited);
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
    DFS(g,0);

    return 0;
}

