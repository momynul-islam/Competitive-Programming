#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Node{
public:
	T data;
	Node *next;
	Node(T data){
		this->data = data;
		next = NULL;
	}
};

template <typename T>
class Stack{
	Node<T> *head;
	int size;
public:
	Stack(){
		head = NULL;
		size = 0;
	}
	int getSize(){
		return size;
	}
	bool isEmpty(){
		return head == NULL;
	}
	void push(T data){
		if(head == NULL){
			Node<T> *newNode = new Node<T>(data);
			head = newNode;
			size++;
		}else{
			Node<T> *newNode = new Node<T>(data);
			newNode->next = head;
			head = newNode;
			size++;
		}
	}
	void pop(){
		if(isEmpty()){
			cout << "Stack Underflow" << endl;
			return;
		}
		Node<T> *temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
		size--;
	}
	T top(){
		if(isEmpty()){
			cout << "Stack is Empty" << endl;
			return 0;
		}
		return head->data; 
	}
};

int main(){

	Stack<char> s;
	for (int i=100; i<=120; ++i)
			s.push(i);	
	while(!s.isEmpty()){
		cout << s.top() << endl;
		s.pop();
	}
	cout << s.getSize() << endl;

	return 0;
}