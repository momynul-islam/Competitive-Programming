#include<bits/stdc++.h>

using namespace std;

void Min_Pair(vector<int> a,vector<int> b){
    int diff=INT_MAX,p1,p2;

    sort(b.begin(),b.end());

    for(auto x : a){
        auto lb = lower_bound(b.begin(),b.end(),x) - b.begin();

        if(lb>=1 && x-b[lb-1] < diff){
            diff = x-b[lb-1];
            p1 = x;
            p2 = b[lb-1];
        }
        if(lb != b.size() && b[lb]-x < diff){
            diff = b[lb]-x;
            p1 = b[lb];
            p2 = x;
        }
    }

    cout << p1 << " " << p2 << endl;
}

void min_pair(vector<int> a,vector<int> b){
    int ans=INT_MAX,dif1,dif2,s,e;
    sort(b.begin(),b.end());

    for(int i=0; i<a.size(); i++){
        auto lb = lower_bound(b.begin(),b.end(),a[i]) - b.begin();
        if(lb >= 1){
            dif1 = abs(a[i] - b[lb-1]);
            dif2 = abs(a[i] - b[lb]);
            if(dif1<dif2 && dif1<ans){
                s = a[i];
                e = b[lb-1];
                ans = dif1;
            }
            else if(dif2<dif1 && dif2<ans){
                s = a[i];
                e = b[lb];
                ans = dif2;
            }
        }
        else{
            dif1 = abs(a[i] - b[lb]);
            if(dif1<ans){
                s = a[i];
                e = b[lb];
                ans = dif1;
            }
        }
    }

    cout << s << " " << e << endl;

}

int main(){

    vector<int> a={-1,5,10,20,3};
    vector<int> b={26,134,135,15,17};

    Min_Pair(a,b);

    return 0;
}
