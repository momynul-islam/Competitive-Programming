#include <bits/stdc++.h>

using namespace std;

int countSubset(int arr[],int n,int i,int sum){
    if(i == n){
        if(sum == 0)
            return 1;
        else
            return 0;
    }

    int inc = countSubset(arr,n,i+1,sum-arr[i]);
    int exc = countSubset(arr,n,i+1,sum);

    return inc + exc;
}

int main(){

    int arr[] = {1,2,3,4,5};

    cout << countSubset(arr,5,0,6) << endl;

    return 0;
}
