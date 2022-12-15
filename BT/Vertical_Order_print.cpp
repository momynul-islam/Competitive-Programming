
#include <bits/stdc++.h>

using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildTree(){
    int d;
    cin >> d;

    if(d == -1) return NULL;

    node* n = new node(d);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}

void traverseTree(node* root,int d,map<int,vector<int>> &m){
    if(root == NULL) return;

    m[d].push_back(root->data);

    traverseTree(root->left,d-1,m);
    traverseTree(root->right,d+1,m);
}

void verticalOrderPrint(node* root){
    map<int,vector<int>> m;
    int d = 0;

    traverseTree(root,d,m);

    for(auto p:m){
        int key = p.first;
        cout << key << " -> ";
        vector<int> v = p.second;
        for(auto x:v) cout << x << " ";
        cout << endl;
    }
}

// input -> 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
int main(){
    node* root = buildTree();
    verticalOrderPrint(root);
    return 0;
}
