#include <bits/stdc++.h>

using namespace std;

class Point{
public:
    int x,y;
    Point(int a,int b){
        x=a;
        y=b;
    }
};

class Compare{
public:
    bool operator()(Point A,Point B){
        if(A.x == B.x) return A.y < B.y;
        return A.x < B.x;
    }
};

int count_rectangles(vector<Point> points){
    set<Point,Compare> s;
    for(auto p:points) s.insert(p);

    int ans = 0;
    for(auto it=s.begin(); it!=prev(s.end()); it++){
        for(auto jt=next(it); jt!=s.end(); jt++){
            Point p1 = *it;
            Point p2 = *jt;

            if(p1.x==p2.x || p1.y==p2.y) continue;

            Point p3(p1.x,p2.y);
            Point p4(p2.x,p1.y);

            if(s.find(p3)!=s.end() && s.find(p4)!=s.end()) ans++;
        }
    }
    return ans/2;
}

int main(){
    int n;
    cin >> n;

    int x,y;
    vector<Point> points;

    for(int i=0; i<n; i++){
        cin >> x >> y;
        Point p(x,y);
        points.push_back(p);
    }

    cout << count_rectangles(points) << endl;

    return 0;
}
