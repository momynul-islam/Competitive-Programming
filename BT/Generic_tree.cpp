#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Node{
public:
	T data;
	vector<Node*> child;
	Node(T data){
		this->data = data;
	}
	~Node(){
		for(int i=0; i<child.size(); i++){
			delete child[i];
		}
	}
};

void printTreeRec(Node<int>* root){
	if(root == NULL){
		cout << "Tree is Empty" << endl;
		return;
	}
	cout << root->data << ":";
	for(int i=0; i<root->child.size(); i++){
		cout << root->child[i]->data << " ";
	}
	cout << endl;

	for(int i=0; i<root->child.size(); i++){
		printTree(root->child[i]);
	}
}

void printTree(Node<int> *root){
	queue<Node<int>*> q;
	q.push(root);

	while(!q.empty()){
		Node<int> *f = q.front();
		q.pop();

		cout << f->data << " : ";
		for(int i=0; i<f->child.size(); i++){
			q.push(f->child[i]);
			cout << f->child[i]->data << " ";
		}
		cout << endl;
	}
}

Node<int>* takeInputRec(){
	int rootdata;
	cout << "Enter root data : ";
	cin >> rootdata;

	Node<int> *root = new Node<int>(rootdata);
	int n;
	cout << "How many children of Node " << rootdata << ":";
	cin >> n;

	for(int i=1; i<=n; i++){
		Node<int>* children = takeInputRec();
		root->child.push_back(children);
	}

	return root;
}

Node<int>* takeInput(){
	int rootdata;
	cout << "Enter root data : " << endl;
	cin >> rootdata;

	Node<int>* root = new Node<int>(rootdata);
	queue<Node<int>*> q;
	q.push(root);

	while(!q.empty()){
		Node<int> *f = q.front();
		q.pop();

		cout << "Enter no. of children of " << f->data << " : ";
		int n;
		cin >> n;

		for(int i=1; i<=n; i++){
			int childdata;
			cout << "Enter the " << i << "th child of node " << f->data << " : ";
			cin >> childdata;
			Node<int> *children = new Node<int>(childdata);
			q.push(children);
			f->child.push_back(children);
		}
	}
	return root;
}

int countNodes(Node<int> *root){
	if(root == NULL)
		return 0;
	int ans = 1;
	for(int i=0; i<root->child.size(); i++){
		ans += countNodes(root->child[i]);
	}

	return ans;
}

int height(Node<int> *root){
	if(root == NULL)
		return 0;
	int mx=0;
	for(int i=0; i<root->child.size(); i++){
		//mx = max(mx,height(root->child[i]));
		int childHeight = height(root->child[i]);
		if(childHeight > mx)
			mx = childHeight;
	}

	return mx+1;
}

void printAllNodesAtLevelK(Node<int> *root,int k){
	if(root == NULL)
		return;
	if(k == 0){
		cout << root->data << endl;
		return;
	}

	for(int i=0; i<root->child.size(); i++){
		printAllNodesAtLevelK(root->child[i],k-1);
	}
}

int countLeafNodes(Node<int> *root){
	if(root->child.size()==0)
		return 1;
	int ans=0;
	for(int i=0; i<root->child.size(); i++){
		ans+=countLeafNodes(root->child[i]);
	}
	return ans;
}

void preOrder(Node<int> *root){
	if(root == NULL)
		return;
	cout << root->data << " ";
	for(int i=0; i<root->child.size(); i++){
		preOrder(root->child[i]);
	}
}

void postOrder(Node<int> *root){
	if(root == NULL)
		return;
	for(int i=0; i<root->child.size(); i++){
		postOrder(root->child[i]);
	}
	cout << root->data << " ";
}

void deleteTree(Node<int> *root){
	if(root == NULL)
		return;
	for(int i=0; i<root->child.size(); i++){
		deleteTree(root->child[i]);
	}
	delete root;
}

int main(){

	Node<int> *root = takeInput();
	printTree(root);
	cout << countNodes(root) << endl;

	return 0;
}