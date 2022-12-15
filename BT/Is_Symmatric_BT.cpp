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

BTNode<int>* takeInputLevelWise(){
	int rootdata;
	cin >> rootdata;

	BTNode<int> *root = new BTNode<int>(rootdata);
	queue<BTNode<int>*> q;
	q.push(root);

	while(!q.empty()){
		BTNode<int> *f = q.front();
		q.pop();

		int leftchild,rightchild;
		cin >> leftchild;
		if(leftchild != -1){
			BTNode<int> *child = new BTNode<int>(leftchild);
			f->left = child;
			q.push(child);
		}
		else
			f->left = NULL;
		cin >> rightchild;
		if(rightchild != -1){
			BTNode<int> *child = new BTNode<int>(rightchild);
			f->right = child;
			q.push(child);
		}
		else
			f->right = NULL;
	}

	return root;
}

void printBTLevelWise(BTNode<int> *root){
	if(root == NULL)
		return;
	queue<BTNode<int>*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		BTNode<int> *f = q.front();
		q.pop();

		if(f == NULL){
			cout << endl;
			if(!q.empty())
				q.push(NULL);
		}else{
			cout << f->data << " ";
			if(f->left)
				q.push(f->left);
			if(f->right)
				q.push(f->right);
		}
	}
	return;
}

bool helper(BTNode<int> *l,BTNode<int> *r){
	if(l==NULL && r!=NULL) return false;
	if(l!=NULL && l==NULL) return false;
	if(l==NULL && r==NULL) return true;
	if(l->data != r->data) return false;

	return helper(l->left,r->right) && helper(l->right,r->left);
}

bool isSymmetric(BTNode<int> *root){
	if(root == NULL) return true;

	return helper(root->left,root->right);
}

int main(){
    return 0;
}




