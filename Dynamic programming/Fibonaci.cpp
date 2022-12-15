#include <bits/stdc++.h>

using namespace std;

//recursion
int fib(int n){
    if(n==0 || n==1)
        return n;
    return fib(n-1)+fib(n-2);
}

//bottom up dp/iterative
int fib2(int n){
    int prev2 = 0;
    int prev1 = 1;
    int fib = 0;

    if(n==0 || n==1) return n;

    for(int i=2; i<=n; i++){
        fib = prev1 + prev2;
        prev2 = prev1;
        prev1 = fib;
    }
    return fib;
}

//top down dp/memorization
int fib3(int n,int *arr){
    if(n==0 || n==1) return n;

    if(arr[n] != 0) return arr[n];
    int output = fib3(n-1,arr)+fib3(n-2,arr);
    arr[n] = output;
    return output;
}

int main(){
    int n;
    cin >> n;

    int *arr = new int[n+1];
    for(int i=0; i<=n; i++) arr[i] = 0;

    cout << fib2(n) << endl;
    cout << fib3(n,arr) << endl;
    cout << fib(n) << endl;

    return 0;
}
