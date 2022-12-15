#include <bits/stdc++.h>

using namespace std;

class Car{
public:
    string id;
    int x,y;
    Car(string id,int x,int y){
        this->id = id;
        this->x = x;
        this->y = y;
    }
    int dist() const{
        return x*x + y*y;
    }
};

class CarCompare{
public:
    bool operator()(Car A,Car B){
        return A.dist() < B.dist();
    }
};

void printNearestCars(vector<Car> cars,int k){
    priority_queue<Car,vector<Car>,CarCompare> max_heap(cars.begin(),cars.begin()+k);

    for(int i=k; i<cars.size(); i++){
        if(cars[i].dist() < max_heap.top().dist()){
            max_heap.pop();
            max_heap.push(cars[i]);
        }
    }

    vector<Car> output;
    while(!max_heap.empty()){
        output.push_back(max_heap.top());
        max_heap.pop();
    }

    reverse(output.begin(),output.end());
    for(auto x:output) cout << x.id << endl;
}

int main(){
    int n,k;
    cin >> n >> k;

    string id;
    int x,y;

    vector<Car> cars;
    for(int i=0; i<n; i++){
        cin >> id >> x >> y;
        Car car(id,x,y);
        cars.push_back(car);
    }

    printNearestCars(cars,k);

    return 0;
}
