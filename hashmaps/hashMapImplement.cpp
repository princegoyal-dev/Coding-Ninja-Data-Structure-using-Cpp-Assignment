#include <bits/stdc++.h>

using namespace std;

template <typename T>
class MapNode {
    public :
        string key;
        T value;
        MapNode *next;

        MapNode (string key, T value) {
            this -> key = key;
            this -> value = value;
            next = NULL;
        }
        ~MapNode() {
            if(next != NULL) {
                delete next;
            }
        }
};

template <typename T>
class OurMap {
    MapNode<T> **buckets;
    int count;
    int numBuckets;
    
    public:
        OurMap() {
            count = 0;
            numBuckets = 5;
            buckets = new MapNode<T>*[numBuckets];
            for(int i = 0; i < numBuckets; i++) {
                buckets[i] = NULL;
            }
        }
        ~OurMap() {
            for(int i = 0; i < numBuckets; i++) {
                delete buckets[i];
            }
            delete [] buckets;
        }

        int size() {
            return count;
        }

    private:
        int getBucketIndex(string key) {
            int hashCode = 0;
            int currentCoeff = 1;
            for(int i = key.length() - 1; i >= 0; i--) {
                hashCode += key[i] * currentCoeff;
                hashCode = hashCode % numBuckets;
                currentCoeff *= 37;
                currentCoeff = currentCoeff % numBuckets;
            }
            return hashCode % numBuckets;
        }
    
    private:

        void rehash() {
            MapNode<T> **temp = buckets;
            buckets = new MapNode<T> * [numBuckets * 2];
            for(int i = 0; i < 2 * numBuckets; i++) {
                buckets[i] = NULL;
            }
            int oldBucketCount = numBuckets;
            numBuckets *= 2;
            count = 0;
            for(int i = 0; i < oldBucketCount; i++) {
                MapNode<T> *head = temp[i];
                while(head != NULL) {
                    string key = head -> key;
                    T value = head -> value;
                    insert(key, value);
                    head = head -> next;
                }
            }
            for(int i = 0; i < oldBucketCount; i++) {
                MapNode<T> *head = temp[i];
                delete head;
            }
            delete [] temp;
        }

    public :
        double getLoadFactor() {
            return (1.0 * count) / numBuckets;
        }

        void insert(string key, T value) {
            int bucketIndex = getBucketIndex(key);
            MapNode<T> *head = buckets[bucketIndex];
            while(head != NULL) {
                if(head -> key == key) {
                    head -> value = value;
                    return;
                }
                head = head -> next;
            }
            head = buckets[bucketIndex];
            MapNode<T> *node = new MapNode<T>(key, value);
            node -> next = head;
            buckets[bucketIndex] = node;
            count++;
            double loadFactor = (1.0 * count) / numBuckets;
            if(loadFactor > 0.7) {
                rehash();
            }
        }

        T getValue(string key) {
            int bucketIndex = getBucketIndex(key);
            MapNode<T> *head = buckets[bucketIndex];
            while(head != NULL) {
                if(head -> key == key) {
                    return head -> value;
                }
                head = head -> next;
            }
            return INT_MIN;
        }

        T remove(string key) {
            int bucketIndex = getBucketIndex(key);
            MapNode<T> *head = buckets[bucketIndex];
            MapNode<T> *prev = NULL;
            while(head != NULL) {
                if(head -> key == key) {
                    if(prev == NULL) {
                        buckets[bucketIndex] = head -> next;
                    } else {
                        prev -> next = head -> next;
                    }
                    T value = head -> value;
                    head -> next = NULL;
                    delete head;
                    count--;
                    return value;
                }
                prev = head;
                head = head -> next;
            }
            return INT_MIN;
        }

};

int main() {
    OurMap<int> myMap;
    myMap.insert("abc", 1);
    cout << myMap.getLoadFactor();
    cout << endl;

    myMap.insert("def", 2);
    cout << myMap.getLoadFactor();
    cout << endl;
    
    myMap.insert("ghi", 3);
    cout << myMap.getLoadFactor();
    cout << endl;
    
    myMap.insert("jkl", 4);
    cout << myMap.getLoadFactor();
    cout << endl;
    
    myMap.insert("cba", 5);
    cout << myMap.getLoadFactor();
    cout << endl;
    
    myMap.insert("fed", 6);
    cout << myMap.getLoadFactor();
    cout << endl;
    
    myMap.insert("klj", 7);
    cout << myMap.getLoadFactor();
    cout << endl;
    
    myMap.insert("ihg", 8);
    cout << myMap.getLoadFactor();
    cout << endl;
    

    cout << "size : " << myMap.size() << endl;

    cout << myMap.getValue("bcd") << endl;
    cout << myMap.getValue("abc") << endl;

    cout << myMap.remove("bcd") << endl;
    cout << myMap.remove("abc") << endl;
    cout << myMap.remove("def") << endl;

    cout << "size : " << myMap.size() << endl;

    

    return 0;
}