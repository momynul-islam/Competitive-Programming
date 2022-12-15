#include <bits/stdc++.h>

using namespace std;

void makeSet(int N, int parent[]){
    for(int i=1;i<=N;i++){
        parent[i] = i;
    }
}

int find(int i, int parent[]){
    while(parent[i] != i){
        i = parent[i];
    }
    return i;
}

void union1(int x,int y,int parent[]){
    int a = find(x,parent);
    int b = find(y,parent);
    parent[b] = a;
}

int main(){

    return 0;
}
