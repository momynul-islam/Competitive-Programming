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

node* insertBST(node* root,int val){
    if(root == NULL){
        return new node(val);
    }
    else if(val < root->data){
        root->left = insertBST(root->left,val);
    }else{
        root->right = insertBST(root->right,val);
    }
    return root;
}

void inorder(node *node){
        if(node == NULL)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
}

bool searchNode(node* n,int key){
    if(n == NULL) return false;
    if(n->data == key) return true;
    return searchNode(n->left,key) || searchNode(n->right,key);
}

int main(){
    node *root = NULL;
    int arr[] = {8,3,10,1,6,14,4,7,13};

    for(auto x:arr){
        root = insertBST(root,x);
    }
    inorder(root);

    cout << "\n" << searchNode(root,1) << endl;

    return 0;
}
