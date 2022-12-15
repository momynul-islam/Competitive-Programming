#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,s,temp;
    cin >> n >> s;
    vector<int> v;
    for(int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }
    bool ans = false;
/*    //naive approach
    for(int x=0; x<n; x++){
        for(int y=x+1; y<n; y++){
            for(int z=y+1; z<n; z++){
                if(v[x] + v[y] + v[z] == s){
                    cout << v[x] << " " << v[y] << " " << v[z] << endl;
                    ans = true;
                }
            }
        }
    }
    if(!ans)
        cout << "No such triplets" << endl;
*/
/*    //using set data structure / help of pairsum problem / output not ordering
    set<int> arr;
    for(int i=0; i<n; i++){
        int rsum = s - v[i];
        for(int j = i+1; j<n; j++){
            int sum = rsum - v[j];
            if(arr.count(sum)){
                cout << v[i] << " " << sum << " " << v[j] << endl;
                ans = true;
            }
            arr.insert(v[j]);
        }
        arr.clear();
    }
    if(!ans)
        cout << "No such triplets" << endl;
*/
    //two pointer approach
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++){
        int rsum = s - v[i];
        int x=i+1, y=v.size()-1;
        while(x < y){
            if(v[x] + v[y] == rsum){
                cout << v[i] << " " << v[x] << " " << v[y] << endl;
                x++;
                y--;
                ans = true;
            }
            else if(v[x] + v[y] > rsum)
                y--;
            else
                x++;
        }
    }
    if(!ans)
        cout << "No such triplets" << endl;

    return 0;
}
