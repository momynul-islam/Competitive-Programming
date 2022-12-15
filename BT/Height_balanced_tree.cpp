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

int height(node* root){
    if(root == NULL) return 0;

    int h1 = height(root->left);
    int h2 = height(root->right);

    return 1 + max(h1,h2);
}

bool isBalancedHeight(node *root){
    if(root == NULL) return true;

    int LH = height(root->left);
    int RH = height(root->right);

    bool ans;
    if(abs(LH-RH)<=1) ans=true;
    else ans=false;

    bool LS = isBalancedHeight(root->left);
    bool RS = isBalancedHeight(root->right);

    cout << root->data << " " << LH << " " << RH << endl;

    return ans && LS && RS;

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

// input -> 1 2 4 -1 -1 5 7 8 -1 -1 -1 -1 3 -1 6 9 -1 -1 -1
int main(){
    node* root = buildTree();
    PrintLevelOrder_OR_BFS(root);
    cout << isBalancedHeight(root) << endl;

    return 0;
}
