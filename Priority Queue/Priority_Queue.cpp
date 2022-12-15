#include <bits/stdc++.h>

using namespace std;

class PriorityQueue{
    vector<int> pq;
public:
    PriorityQueue(){}

    bool isEmpty(){
        return pq.size()==0;
    }

    int getSize(){
        return pq.size();
    }

    int getMin(){
        if(isEmpty()) return 0;
        return pq[0];
    }

    void insert(int value){
        pq.push_back(value);
        int ci = pq.size()-1;

        while(ci>0){
            int pi = (ci-1)/2;
            if(pq[ci] < pq[pi]){
                swap(pq[ci],pq[pi]);
                ci = pi;
            }
            else
                break;
        }
    }

    int removeMin(){
        if(isEmpty()) return 0;

        int ans=pq[0];
        swap(pq[0],pq[pq.size()-1]);
        pq.pop_back();
        int pi = 0;
        int lci = (2*pi)+1;
        int rci = (2*pi)+2;

        while(lci < pq.size() || rci < pq.size()){
            int ci = (pq[lci] < pq[rci]) ? lci : rci;
            if(lci >= pq.size()) ci = rci;
            if(rci >= pq.size()) ci = lci;
            if(pq[pi]>pq[ci])
                swap(pq[pi],pq[ci]);
            else
                break;
            pi = ci;
            lci = (2*pi)+1;
            rci = (2*pi)+2;
        }

        return ans;
    }

    void printPQ(){
        for(int i=0; i<pq.size(); i++)
            cout << pq[i] << " ";
        cout << endl;
    }
};


int main(){

    PriorityQueue p;
    p.insert(10);
    p.insert(5);
    p.insert(8);
    p.insert(1);
    p.insert(4);

    p.printPQ();

    while(!p.isEmpty()){
        cout << p.removeMin() << " ";
    }

    return 0;
}
