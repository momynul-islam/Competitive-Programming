#include <bits/stdc++.h>

using namespace std;

class node{
public:
	int data;
	node* next;
	node(int data){
		this->data = data;
		this->next = NULL;
	}
};

void insertAtBegin(node* &head,int data){
	if(head == NULL){
		head = new node(data);
		return;
	}
	node* n = new node(data);
	n->next = head;
	head = n;
}

void insertInMiddle(node* &head,int data,int i){
	if(i==0){
		insertAtBegin(head,data);
		return;
	}

	node* curr = head;
	
	for(int jump=1; jump<=i-2; jump++)
		curr = curr->next;

	node* temp = curr->next;

	node* n = new node(data);
	n->next = curr->next;
	curr->next = n;

	//delete temp;
}

void printLL(node* head){
	while(head != NULL){
		cout << head->data << "-->";
		head = head->next;
	}
	cout << "NULL" << endl;
}

node* mergeLL(node* a,node* b){
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;

	node* finalHead = NULL;

	if(a->data < b->data){
		finalHead = a;
		a = a->next;
	}else{
		finalHead = b;
		b = b->next;
	}

	node* p = finalHead;

	while(a && b){
		if(a->data < b->data){
			p->next = a;
			a = a->next;
		}else{
			p->next = b;
			b = b->next;
		}
		p = p->next;
	}

	if(a)
		p->next = a;
	else
		p->next = b;

	return finalHead;
}

node* recMergeLL(node* a,node* b){
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;

	node* head = NULL;

	if(a->data < b->data){
		head = a;
		head->next = recMergeLL(a->next,b);
	}else{
		head = b;
		head->next = recMergeLL(a,b->next);
	}

	return head;
}

int main(){
	node* a=NULL;
	node* b=NULL;

	insertAtBegin(a,8);
	insertAtBegin(a,5);
	insertAtBegin(a,2);
	insertAtBegin(a,1);

	cout << "a-->";
	printLL(a);

	insertAtBegin(b,7);
	insertAtBegin(b,6);
	insertAtBegin(b,4);
	insertAtBegin(b,3);

	cout << "b-->";
	printLL(b);

	node* head = recMergeLL(a,b);
	cout << "head-->";
	printLL(head);
	
	return 0;
}