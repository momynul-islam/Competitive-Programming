#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,temp,cnt=0,j=0;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }
    for(int i=0; i<n; i++){
        if( i != 0 && v[i] < v[i+1] && v[i] < v[i-1]){
            j++;
            if(j > cnt)
                cnt = j;
            j=1;
        }
        else if((v[i] > v[i-1]) || (v[i] < v[i-1]) || (v[i] < v[i+1]))
            j++;
    }
    cout << cnt << endl;
    return 0;
}
