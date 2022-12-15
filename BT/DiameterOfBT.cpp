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

node* levelOrderBuild(){
    int d;
    cin >> d;

    node* root = new node(d);
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* n = q.front();
        q.pop();

        int c1,c2;
        cin >> c1 >> c2;

        if(c1 != -1){
            n->left = new node(c1);
            q.push(n->left);
        }
        if(c2 != -1){
            n->right = new node(c2);
            q.push(n->right);
        }
    }
    return root;
}

int maxDepthOrHeight(node* root){
	if(root == NULL) return 0;
	return max(maxDepthOrHeight(root->left),maxDepthOrHeight(root->right))+1;
}

int diameterBT(node* root){
    if(root == NULL) return 0;

    int d = maxDepthOrHeight(root->left) + maxDepthOrHeight(root->right);
    int d1 = diameterBT(root->left);
    int d2 = diameterBT(root->right);

    return max(d,max(d1,d2));
}

// input -> 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
int main(){
    node* root = levelOrderBuild();
    cout << diameterBT(root) << endl;

    return 0;
}
