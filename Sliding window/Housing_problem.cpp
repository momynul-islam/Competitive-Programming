#include <bits/stdc++.h>

using namespace std;

int main(){

    int arr[] = {1,3,2,1,4,1,3,2,1,1};
    int k=0 , n = sizeof(arr)/sizeof(arr[0]);

    cin >> k;

    int i=0, j=0, cs=0, mn=INT_MAX, mi=0, mj=0;

    while(i<=j){
        if(cs == k){
            //cout << i << " " << j-1 << endl;
            if((j-1-i) < mn){
                mn = j-1-i;
                mi = i;
                mj = j-1;
            }
            cs += arr[j++];
        }
        else if(cs < k && j<n)
            cs += arr[j++];
        else
            cs -= arr[i++];
    }

    cout << mi << " " << mj << endl;

    return 0;
}
