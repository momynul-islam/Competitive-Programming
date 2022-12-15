#include <bits/stdc++.h>

using namespace std;

template <typename T>
class BTNode{
public:
	T data;
	BTNode *left;
	BTNode *right;
	BTNode(T ele){
		this->data = ele;
		this->left = NULL;
		this->right = NULL;
	}
	~BTNode(){
		delete left;
		delete right;
	}
};

class BST{
    BTNode<int> *root;

    void inorder(BTNode<int> *node){
        if(node == NULL)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void printBT(BTNode<int> *root){
        if(root == NULL)
            return;
        cout << root->data << " : ";
        if(root->left != NULL)
            cout << root->left->data << " ";
        if(root->right != NULL)
            cout << root->right->data << " ";
        cout << endl;

        printBT(root->left);
        printBT(root->right);
    }

    bool searchNode(BTNode<int> *node,int key){
        if(node == NULL) return false;

        if(node->data == key) return true;

        return searchNode(node->left,key) || searchNode(node->right,key);
    }

    BTNode<int>* insertData(BTNode<int> *node,int data){
        if(node == NULL){
            BTNode<int> *n = new BTNode<int>(data);
            return n;
        }
        if(node->data < data)
            node->right = insertData(node->right,data);
        else
            node->left = insertData(node->left,data);

        return node;
    }

    BTNode<int>* deleteData(BTNode<int> *node,int data){
        if(node == NULL) return NULL;

        if(data>node->data) node->right = deleteData(node->right,data);
        else if(data<node->data) node->left = deleteData(node->left,data);
        else{
            if(node->left==NULL && node->right==NULL){
                delete node;
                return NULL;
            }
            else if(node->right==NULL){
                BTNode<int> *n = node->left;
                node->left = NULL;
                delete node;
                return n;
            }
            else if(node->left==NULL){
                BTNode<int> *n = node->right;
                node->right = NULL;
                delete node;
                return n;
            }
            else{
                BTNode<int> *minNode = node->right;
                while(minNode->left!=NULL){minNode = minNode->left;}
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteData(node->right,rightMin);
            }
        }
        return node;
    }

public:
    BST(){
        root = NULL;
    }
    ~BST(){
        delete root;
    }
    void insertData(int data){
        root = insertData(root,data);
    }
    void deleteData(int data){
        root = deleteData(root,data);
    }
    bool searchData(int data){
        return searchNode(root,data);
    }
    void printBST(){
        printBT(root);
    }
};

int main(){
    BST b;
    b.insertData(10);
    b.insertData(5);
    b.insertData(20);
    b.insertData(7);
    b.insertData(3);
    b.insertData(15);

    b.printBST();
    b.deleteData(10);
    cout << endl;
    b.printBST();
    b.deleteData(5);
    cout << endl;
    b.printBST();
    return 0;
}
