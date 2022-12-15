#include <bits/stdc++.h>

using namespace std;

template<typename V>
class mapNode{
public:
    string key;
    V value;
    mapNode* next;

    mapNode(string key,V value){
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
    ~mapNode(){
        delete next;
    }
};

template<typename V>
class myMap{
    mapNode<V>* *buckets;
    int count;
    int bucketSize;

    int getBucketIndex(string key){
        int hashcode=0,base=1,p=37;

        for(int i=key.size()-1; i>=0; i--){
            hashcode = key[i]*base;
            base = base*p;
            hashcode = hashcode%bucketSize;
            base = base%bucketSize;
        }

        return hashcode%bucketSize;
    }

    void rehash(){
        mapNode<V>* *temp = buckets;
        int oldBucketSize = bucketSize;
        bucketSize *= 2;
        count = 0;

        buckets = new mapNode<V>*[bucketSize];
        for(int i=0; i<bucketSize; i++)
            buckets[i] = NULL;

        for(int i=0; i<oldBucketSize; i++){
            mapNode<V>* head = temp[i];
            while(head!=NULL){
                string key = head->key;
                V value = head->value;
                insert(key,value);
                head = head->next;
            }
        }

        for(int i=0; i<oldBucketSize; i++)
            delete temp[i];
        delete []temp;
    }

public:

    myMap(){
        count = 0;
        bucketSize = 5;
        buckets = new mapNode<V>* [bucketSize];
        for(int i=0; i<bucketSize; i++)
            buckets[i] = NULL;
    }

    int size(){
        return count;
    }

    void insert(string key,V value){
        int bucketIndex = getBucketIndex(key);
        mapNode<V>* head = buckets[bucketIndex];

        while(head!=NULL){
            if(head->key == key){
                head->value = value;
                return;
            }
            head = head->next;
        }

        mapNode<V>* node = new mapNode<V>(key,value);
        node->next = buckets[bucketIndex];
        buckets[bucketIndex] = node;
        count++;

        double loadFactor = (double)count/bucketSize;
        if(loadFactor > 0.7)
            rehash();
    }

    V getValue(string key){
        int bucketIndex = getBucketIndex(key);
        mapNode<V>* head = buckets[bucketIndex];

        while(head!=NULL){
            if(head->key == key)
                return head->value;
            head = head->next;
        }
        return 0;
    }

    V remove(string key){
        int bucketIndex = getBucketIndex(key);
        mapNode<V>* head = buckets[bucketIndex];
        mapNode<V>* prev = NULL;

        while(head!=NULL){
            if(head->key == key){
                if(prev==NULL)
                    buckets[bucketIndex] = head->next;
                else
                    prev->next = head->next;

                V value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }

            prev = head;
            head = head->next;
        }
        return 0;
    }

    double getLoadFactor(){
        return (double)count/bucketSize;
    }

};

int main(){
    myMap<int> mp;
    for(int i=0; i<10; i++){
        char ch = i+'0';
        string key = "abc";
        key += ch;
        int value = i+1;
        mp.insert(key,value);
        cout << mp.getLoadFactor() << endl;
    }

    cout << mp.size() << endl;

    mp.remove("abc6");
    mp.remove("abc3");
    for(int i=0; i<10; i++){
        string key="abc";
        key += (char)('0'+i);
        cout << key << " " << mp.getValue(key) << endl;
    }
    cout << mp.size() << endl;

    return 0;
}
