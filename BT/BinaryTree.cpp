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

BTNode<int>* takeInput(){
	int rootdata;
	cin >> rootdata;

	if(rootdata == -1)
		return NULL;
	BTNode<int> *root = new BTNode<int>(rootdata);
	root->left = takeInput();
	root->right = takeInput();

	return root;
}

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

int countNodes(BTNode<int> *root){
	if(root == NULL)
		return 0;
	return countNodes(root->left) + countNodes(root->right) + 1;
}

void inorder(BTNode<int> *root){
	if(root == NULL)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void preorder(BTNode<int> *root){
	if(root == NULL)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(BTNode<int> *root){
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

int maxDepthOrHeight(BTNode<int> *root){
	if(root == NULL) return 0;
	return max(maxDepthOrHeight(root->left),maxDepthOrHeight(root->right))+1;
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

bool searchNode(BTNode<int> *root,int key){
	if(root == NULL) return false;

	if(root->data == key) return true;

	return searchNode(root->left,key) || searchNode(root->right,key);
}

void minValue(BTNode<int> *root,int &ans){
	if(root == NULL) return;
	ans = min(ans,root->data);
	minValue(root->left,ans);
	minValue(root->right,ans);
}

void maxValue(BTNode<int> *root,int &ans){
	if(root == NULL) return;
	ans = max(ans,root->data);
	maxValue(root->left,ans);
	maxValue(root->right,ans);
}

int countLeafNodes(BTNode<int> *root){
	if(root == NULL) return 0;
	if(root->left == NULL && root->right == NULL) return 1;

	return countLeafNodes(root->left) + countLeafNodes(root->right);
}

bool getPath(BTNode<int> *root,int val,vector<int> &v){
	if(root == NULL) return false;

	v.push_back(root->data);
	if(root->data == val) return true;

	bool left = getPath(root->left,val,v);
	bool right = getPath(root->right,val,v);

	if(left || right) return true;
	v.pop_back();
	return false;
}

int main(){

	BTNode<int> *root = takeInputLevelWise();
	cout << endl;
	printBTLevelWise(root);
	cout << countNodes(root) << endl;
	//tree traversal
	cout << "inorder : ";
	inorder(root);
	cout << endl;
	cout << "preorder : ";
	preorder(root);
	cout << endl;
	cout << "postorder : ";
	postorder(root);
	cout << endl;

	cout << "maxDepthOrHeight : " << maxDepthOrHeight(root) << endl;

	return 0;
}
