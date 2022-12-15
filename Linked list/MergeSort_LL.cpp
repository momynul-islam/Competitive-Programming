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

node* middleLL(node* head){
	node* slow=head;
	node* fast=head;

	while(fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

node* mergeSortLL(node* head){
	if(head == NULL || head->next == NULL)
		return head;

	node* mid = middleLL(head);
	node* a = head;
	node* b = mid->next;
	mid->next = NULL;

	a = mergeSortLL(a);
	b = mergeSortLL(b);

	return mergeLL(a,b);
}

int main(){
	node* head=NULL;

	insertAtBegin(head,1);
	insertAtBegin(head,2);
	insertAtBegin(head,3);
	insertAtBegin(head,4);
	insertAtBegin(head,5);

	printLL(head);

	head = mergeSortLL(head);
	printLL(head);
	printLL(head);

	return 0;
}