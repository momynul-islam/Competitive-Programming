#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,temp;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }
/*  //using sort function
    vector<int> arr(v.begin(),v.end());
    int left,right;
    sort(arr.begin(),arr.end());
    for(int i=0; i<n; i++){
        if(v[i] != arr[i]){
            left = i;
            break;
        }
    }
    for(int i=n-1; i>=0; i--){
        if(v[i] != arr[i]){
            right = i;
            break;
        }
    }
    cout << left << " " << right << endl;
*/
    int left_index = -1, right_index = -1;
    for(int i=1; i<n; i++){
        if(v[i] < v[i-1] && left_index == -1){
            left_index = i-1;
            swap(v[i],v[i-1]);
        }
        else if(v[i] < v[i-1]){
            right_index = i;
            swap(v[i],v[i-1]);
        }
    }
    cout << left_index << " " << right_index << endl;
    return 0;
}
