#include <bits/stdc++.h>

using namespace std;

int main(){
    //declaration and input
    int n,temp,large,water=0;
    cin >> n;
    vector<int> v,l,r(n,0);
    for(int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }
    //left max vector
    large = INT_MIN;
    for(int i=0; i<n; i++){
        if(v[i] > large)
            large = v[i];
        l.push_back(large);
    }
    //right max vector
    large = INT_MIN;
    for(int i=n-1; i>=0; i--){
        if(v[i] > large)
            large = v[i];
        r[i] = large;
    }
    //logic
    for(int i=0; i<n; i++)
        water += min(l[i],r[i]) - v[i];
    cout << water << endl;

    return 0;
}
