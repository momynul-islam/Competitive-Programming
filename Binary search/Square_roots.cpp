#include <bits/stdc++.h>

using namespace std;

double square_root(int n,int p){
    int s=0;
    int e=n;
    double ans;

    while(s<=e){
        int mid = s + (e-s)/2;
        if(mid*mid == n)
            return ans;
        else if(mid*mid < n){
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }

    double inc = 0.1;
    for(int place=1; place<=p; place++){
        while(ans*ans <= n){
            ans += inc;
        }

        ans -= inc;
        inc = inc/10.0;
    }

    return ans;
}

int main(){
    int n,p;
    cin >> n >> p;

    cout << square_root(n,p) << endl;

    return 0;
}
