#include <bits/stdc++.h>

using namespace std;

int main(){
/*    //naive solution
    int n,s,temp;
    cin >> n >> s;
    vector<int> v;
    for(int i=1; i<=n; i++){
        cin >> temp;
        v.push_back(temp);
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(v[i] + v[j] == s)
                cout << "[" << v[i] << "," << v[j] << "]" << endl;
        }
    }
    cout << "No such pari" << endl;
*/
/*  //two pointer approach
    int n,s,temp;
    cin >> n >> s;
    vector<int> v;
    for(int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    int i=0,j=v.size()-1;
    bool ans = false;
    while(i<j){
        if(v[i] + v[j] == s){
            cout << v[i] << " " << v[j] << endl;
            i++,j--;
            ans = true;
        }
        else if(v[i] + v[j] > s)
            j--;
        else
            i++;
    }
    if(!ans)
        cout << "No such pair" << endl;
*/
    // using set data structure
    int n,s,temp,ans;
    bool b = false;
    cin >> n >> s;
    set<int> num;
    for(int i=0; i<n; i++){
        cin >> temp;
        ans = s - temp;
        if(num.count(ans)){     //if(num.find(ans) != num.end())
            cout << temp << " " << ans << endl;
            b = true;
        }
        num.insert(temp);
    }
    if(!b)
        cout << "No such pair" << endl;
    return 0;
}
