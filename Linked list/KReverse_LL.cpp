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

node* KReverseLL(node* head,int k){
	if(head == NULL){
		return head;
	}

	node* curr = head;
	node* prev = NULL;
	node* temp = NULL;
	int cnt = 1;

	while(curr != NULL && cnt <= k){
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
		cnt++;
	}

	if(temp)
		head->next = KReverseLL(temp,k);

	return prev;
}

int main(){

	node* head=NULL;

	insertAtBegin(head,5);
	insertAtBegin(head,4);
	insertAtBegin(head,2);
	insertAtBegin(head,1);
	insertInMiddle(head,3,3);
	insertInMiddle(head,6,6);

	printLL(head);

	head = KReverseLL(head,3);
	printLL(head);
	
	return 0;
}