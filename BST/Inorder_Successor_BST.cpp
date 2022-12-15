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

node* inorderSuccessor(node* root,node* target){
    if(target->right != NULL){
        node* temp = target->right;
        while(temp->left != NULL){
            temp = temp->left;
        }
        return temp;
    }

    node* temp = root;
    node* succ = NULL;
    while(temp != NULL){
        if(temp->data > target->data){
            succ = temp;
            temp = temp->left;
        }
        else if(temp->data < target->data) temp = temp->right;
        else break;
    }
    return succ;
}

int main(){
    node *root = NULL;
    int arr[] = {8,3,10,1,6,14,4,7,13};

    for(auto x:arr){
        root = insertBST(root,x);
    }

    inorder(root);
    cout << endl;

    node* target = root->left->right;
    node* ans = inorderSuccessor(root,target);
    cout << ans->data << endl;

    return 0;
}

