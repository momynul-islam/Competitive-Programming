#include <bits/stdc++.h>

using namespace std;

bool canPlaceBirds(vector<int> v,int b,int n,int mid){
    int location = v[0];
    b--;

    for(int i=1; i<n; i++){
        int curlocation = v[i];
        if(curlocation - location >= mid){
            b--;
            location = curlocation;
        }
        if(b == 0)
            return true;
    }

    return false;
}

int angry_birds(vector<int> v,int b,int n){
    int s=0;
    int e=v[n-1] - v[0];
    int ans = 0;

    while(s<=e){
        int mid = s + (e-s)/2;

        bool canPlace = canPlaceBirds(v,b,n,mid);

        if(canPlace){
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }

    return ans;
}

int main(){

    int n,b;
    cin >> n >> b;

    vector<int> nest = {1,2,4,8,9};
    sort(nest.begin(),nest.end());

    cout << angry_birds(nest,b,n) << endl;

    return 0;
}
