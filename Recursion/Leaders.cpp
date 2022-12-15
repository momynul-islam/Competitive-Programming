#include <bits/stdc++.h>

using namespace std;

int countSteps(int n){
    if(n < 0)
        return 0;
    if(n == 0 || n == 1)
        return 1;
    return countSteps(n-1) + countSteps(n-2) + countSteps(n-3);
}

int main(){

    int n;
    cin >> n;

    cout << countSteps(n) << endl;

    return 0;
}
