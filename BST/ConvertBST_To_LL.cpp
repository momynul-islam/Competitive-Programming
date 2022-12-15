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

class Pair{
public:
    node *head;
    node *tail;
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

Pair convertToLL(node* root){
    if(root == NULL){
        Pair ans;
        ans.head = ans.tail = NULL;
        return ans;
    }
    if(root->left == NULL && root->right == NULL){
        Pair ans;
        ans.head = ans.tail = root;
        return ans;
    }
    else if(root->left != NULL && root->right == NULL){
        Pair p = convertToLL(root->left);
        p.tail->right = root;
        Pair ans;
        ans.head = p.head;
        ans.tail = root;
        return ans;
    }
    else if(root->left == NULL && root->right != NULL){
        Pair p = convertToLL(root->right);
        root->right = p.head;
        Pair ans;
        ans.head = root;
        ans.tail = p.tail;
        return ans;
    }
    else{
        Pair ll = convertToLL(root->left);
        Pair rl = convertToLL(root->right);

        ll.tail->right = root;
        root->right = rl.head;

        Pair ans;
        ans.head = ll.head;
        ans.tail = rl.tail;
        return ans;
    }
}

int main(){
    node *root = NULL;
    int arr[] = {8,3,10,1,6,14,4,7,13};

    for(auto x:arr){
        root = insertBST(root,x);
    }

    Pair ans = convertToLL(root);
    node *Head = ans.head;
    while(Head != NULL){
        cout << Head->data << " ";
        Head = Head->right;
    }
    cout << endl;

    return 0;
}
