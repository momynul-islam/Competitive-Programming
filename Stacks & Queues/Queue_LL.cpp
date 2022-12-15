#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Node{
public:
	T data;
	Node<T> *next;
	Node(T ele){
		data = ele;
		next = NULL;
	}
};

template <typename T>
class Queue{
	Node<T> *head;
	Node<T> *tail;
	int size;
public:
	Queue(){
		head = NULL;
		tail = NULL;
		size = 0;
	}
	bool isEmpty(){
		return size == 0;
	}
	int getSize(){
		return size;
	}
	void push(T ele){
		if(head == NULL){
			Node<T> *n = new Node<T>(ele);
			head = tail = n;
		}else{
			Node<T> *n = new Node<T>(ele);
			tail->next = n;
			tail = n;
		}
		size++;
	}
	void pop(){
		if(isEmpty()){
			cout << "Queue is Empty" << endl;
			return;
		}
		Node<T> *temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
		size--;
	}
	T getFront(){
		if(isEmpty()){
			cout << "Queue is Empty" << endl;
			return 0;
		}
		return head->data;
	}
};

int main(){

	Queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.push(60);
	q.push(80);
	
	cout << q.getFront() << endl;
	q.pop();
	q.pop();
	q.pop();
	cout << q.getFront() << endl;
	cout << q.getSize() << endl;
	q.push(60);
	q.push(70);
	cout << q.getSize() << endl;
	cout << q.isEmpty() << endl;

	while(!q.isEmpty()){
		cout << q.getFront() << endl;
		q.pop();
	}
	q.pop();
	cout << q.getFront() << endl;
	
	return 0;
}