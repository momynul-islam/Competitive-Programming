#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Queue{
	T *arr;
	int size;
	int nextIndex;
	int firstIndex;
	int capacity;
public:
	Queue(){
		arr = new T[5];
		capacity = 5;
		size = 0;
		nextIndex = 0;
		firstIndex = -1;
	}
	int getSize(){
		return size;
	}
	bool isEmpty(){
		return size == 0;
	}
	T getFront(){
		if(isEmpty()){
			cout << "Queue is Empty" << endl;
			return 0;
		}
		return arr[firstIndex];
	}
	void push(T ele){
		if(size == capacity){
			T *newArr = new T[capacity*2];
			int j=0;
			for(int i=firstIndex; i<capacity; i++)
				newArr[j++] = arr[i];
			for(int i=0; i<firstIndex; i++)
				newArr[j++] = arr[i];
			nextIndex = j;
			firstIndex = 0;
			capacity = 2*capacity;
			delete []arr;
			arr = newArr;
		}
		arr[nextIndex] = ele;
		nextIndex = (nextIndex+1)%capacity;
		if(firstIndex == -1)
			firstIndex = 0;
		size++;
	}
	void pop(){
		if(isEmpty()){
			cout << "Queue is Empty" << endl;
			return;
		}
		firstIndex = (firstIndex+1)%capacity;
		size--;
		if(size == 0){
			nextIndex = 0;
			firstIndex = -1;
		}
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