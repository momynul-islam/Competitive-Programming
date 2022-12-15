#include <bits/stdc++.h>

using namespace std;

void max_subarray_ele(int a[],int k,int n){
	deque<int> d(k);
	int i=0;
	for(i=0; i<k; i++){
		while(!d.empty() && a[i]>=a[d.back()]){
			d.pop_back();
		}
		d.push_back(i);
	}

	for(;i<=n; i++){
		cout << a[d.front()] << endl;
		while(!d.empty() && d.front()<=i-k){
			d.pop_front();
		}
		while(!d.empty() && a[i]>a[d.back()]){
			d.pop_back();
		}
		d.push_back(i);
	}

}

int main(){

	int arr[] = {1,2,3,1,4,5,2,3,6};	
	int k = 3;
	max_subarray_ele(arr,k,9);

	return 0;
}