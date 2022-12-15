#include <bits/stdc++.h>

using namespace std;

int main(){
    priority_queue<int> leftheap;
    priority_queue<int,vector<int>,greater<int>> rightheap;

    int d;
    cin >> d;
    leftheap.push(d);
    double med = d;
    cout << med << " ";

    cin >> d;
    while(d != -1){
        if(leftheap.size() > rightheap.size()){
            if(d < med){
                rightheap.push(leftheap.top());
                leftheap.pop();
                leftheap.push(d);
            }
            else{
                rightheap.push(d);
            }
            cout << (leftheap.top() + rightheap.top())/2.0 << " ";
        }
        else if(leftheap.size() == rightheap.size()){
            if(d < med){
                leftheap.push(d);
                cout << leftheap.top() << " ";
            }else{
                rightheap.push(d);
                cout << rightheap.top() << " ";
            }
        }else{
            if(d < med){
                leftheap.push(d);
            }
            else{
                leftheap.push(rightheap.top());
                rightheap.pop();
                rightheap.push(d);
            }
            cout << (leftheap.top() + rightheap.top())/2.0 << " ";
        }
        cin >> d;
    }

    return 0;
}
