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

node* sortedArrayToMinHeightBST(int arr[],int s,int e,node* root){
    if(s > e) return NULL;

    int mid = (s+e)/2;
    int root_data = arr[mid];
    root = insertBST(root,root_data);

    root->left = sortedArrayToMinHeightBST(arr,s,mid-1,root->left);
    root->right = sortedArrayToMinHeightBST(arr,mid+1,e,root->right);

    return root;
}

int main(){
    node *root = NULL;
    int arr[] = {1,2,3,4,5,6,7};

    root = sortedArrayToMinHeightBST(arr,0,6,root);
    inorder(root);

    return 0;
}
