#include <bits/stdc++.h>

using namespace std;

int lowerBound(vector<int> v, int key){
    int s=0,e=v.size()-1,ans=0,mid;

    while(s<=e){
        mid = s + (e-s)/2;
        if(v[mid] == key){
            ans = mid;
            e = mid - 1;
        }
        else if(v[mid] > key)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return ans;
}

int upperBound(vector<int> v, int key){
    int s=0,e=v.size()-1,ans=0,mid;

    while(s<=e){
        mid = s + (e-s)/2;
        if(v[mid] == key){
            ans = mid;
            s = mid + 1;
        }
        else if(v[mid] > key)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return ans;
}

int main(){

    vector<int> v = {1,1,1,2,2,2,3,3,3,4,4,5,6,7};

    int fast_occurance,last_occurance,key;
    cin >> key;

    fast_occurance = lowerBound(v,key);
    last_occurance = upperBound(v,key);

    cout << last_occurance-fast_occurance+1 << endl;
    cout << upper_bound(v.begin(),v.end(),key) - lower_bound(v.begin(),v.end(),key) << endl;

    return 0;
}
