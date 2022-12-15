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

void PrintLevelOrder_OR_BFS(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* n = q.front();
        q.pop();
        if(n==NULL){
            cout << endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);
            cout << n->data << " ";
        }
    }
}

// input -> 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
int main(){
    node* root = buildTree();
    PrintLevelOrder_OR_BFS(root);

    return 0;
}

