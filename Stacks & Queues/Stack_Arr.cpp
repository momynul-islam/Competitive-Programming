#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Stack{
	T *arr;
	int nextIndex;
	int capacity;
public:
	Stack(){
		capacity = 4;
		arr = new T[capacity];
		nextIndex = 0;
	}
	bool isEmpty(){
		return nextIndex == 0;
	}
	void push(T data){
		if(nextIndex == capacity){
			T *newArr = new T[capacity*2];
			for(int i=0; i<capacity; i++){
				newArr[i] = arr[i];
			}
			delete []arr;
			arr = newArr;
			capacity *= 2;
		}
		arr[nextIndex] = data;
		nextIndex++;
	}
	void pop(){
		if(isEmpty()){
			cout << "Stack Underflow" << endl;
			return;
		}
		nextIndex--;
	}
	T top(){
		if(isEmpty()){
			cout << "Stack is Empty" << endl;
			return 0;
		}
		return arr[nextIndex-1];
	}
	int size(){
		return nextIndex;
	}
};

int main(){

	Stack<char> s;
	for (int i=100; i<=110; ++i)
			s.push(i);	
	while(!s.isEmpty()){
		cout << s.top() << endl;
		s.pop();
	}
	cout << s.size() << endl;

	return 0;
}