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

int findClosestInBST(node* root,int target){
    int closest;
    int diff = INT_MAX;
    node* temp = root;

    while(temp != NULL){
        int current_diff = abs(temp->data - target);

        if(current_diff == 0) return temp->data;
        if(current_diff < diff){
            diff = current_diff;
            closest = temp->data;
        }

        if(temp->data < target) temp = temp->right;
        else temp = temp->left;
    }
    return closest;
}

int main(){
    node *root = NULL;
    int arr[] = {8,3,10,1,6,14,4,7,13};

    for(auto x:arr){
        root = insertBST(root,x);
    }

    cout << findClosestInBST(root,20) << endl;

    return 0;
}

