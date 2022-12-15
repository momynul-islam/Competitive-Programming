#include <bits/stdc++.h>

using namespace std;

void KSortedArray(int *input,int n,int k){
    priority_queue<int> pq;

    for(int i=0; i<k; i++) pq.push(input[i]);

    int s=0;
    for(int i=k; i<n; i++){
        input[s++] = pq.top();
        pq.pop();
        pq.push(input[i]);
    }

    while(!pq.empty()){
        input[s++] = pq.top();
        pq.pop();
    }
}

int main(){

    int input[] = {10,12,7,5,9};
    KSortedArray(input,5,3);

    for(int i=0; i<5; i++) cout << input[i] << " ";
    cout << endl;

    return 0;
}
