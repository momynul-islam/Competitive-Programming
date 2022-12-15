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

void printLevelK(node* root,int k){
    if(root == NULL) return;
    if(k == 0){
        cout << root->data << " ";
        return;
    }
    printLevelK(root->left,k-1);
    printLevelK(root->right,k-1);
}

// input -> 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
int main(){
    node* root = buildTree();
    printLevelK(root,3);
    return 0;
}
