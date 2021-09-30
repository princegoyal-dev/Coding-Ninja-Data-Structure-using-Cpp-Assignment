#include <bits/stdc++.h>

using namespace std;

void mergeSorted(int *arr, int si, int midIndex, int ei) {
    // cout << "si : " << si << " ei : " << ei << endl;
    int tempSi = si;
    int tempMidIndex = midIndex + 1;
    int *newArr = new int[ei + 1];
    int k = si;
    while(tempSi <= midIndex && tempMidIndex <= ei) {
        if(arr[tempSi] <= arr[tempMidIndex]) {
            newArr[k++] = arr[tempSi];
            tempSi++;
        } else {
            newArr[k++] = arr[tempMidIndex];
            tempMidIndex++;
        }
    }
    if(tempSi != midIndex + 1) {
        while(tempSi <= midIndex) {
            newArr[k++] = arr[tempSi];
            tempSi++;
        }
    }
    if(tempMidIndex != (ei + 1)) {
        while(tempMidIndex <= ei) {
            newArr[k++] = arr[tempMidIndex];
            tempMidIndex++;
        }
    }
    for(int i = si; i <= ei; i++) {
        arr[i] = newArr[i];
    }
}

void mergeSort(int *arr, int si, int ei) {
    if (si >= ei) {
        return;
    }
    // cout << "mergeSort called " << endl;
    int midIndex = (si + ei) / 2;
    mergeSort(arr, si, midIndex);
    mergeSort(arr, midIndex + 1, ei);
    mergeSorted(arr, si, midIndex, ei);
}

int main() {
    int size;
    cin >> size;

    int *arr = new int[size];

    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // mergeSort(arr, 0, size - 1);

    // for(int i = 0; i < size; i++) {
    //     cout << arr[i] << " ";
    // }
    // int midIndex = (size - 1) / 2;

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i = 0; i < size; i++) {
        int currElement = arr[i];
        // cout << "currElement : " << currElement << endl;
        if(maxHeap.empty()) {
            // cout << "maxheap empty pushing element" << endl;
            maxHeap.push(currElement);

        } else {
            if(currElement < maxHeap.top()) {
                // cout << "current element < maxHeap top : " << maxHeap.top() << endl;
                maxHeap.push(currElement) ;
            } else {
                // cout << "current element > maxHeaptop : " << maxHeap.top() << endl;
                minHeap.push(currElement);
            }
        }
        int sizeDiff = abs((int)maxHeap.size() - (int)minHeap.size());
        // cout << "sizeDiff : " << sizeDiff << endl;
        if(sizeDiff > 1) {
            // cout << "greater diff" << endl;
            if(maxHeap.size() > minHeap.size()) {
                int element = maxHeap.top();
                maxHeap.pop();
                minHeap.push(element);
            } else {
                int element = minHeap.top();
                minHeap.pop();
                maxHeap.push(element);
            }
            // cout << "minheap top : " << minHeap.top() << endl;
            // cout << "maxheap top : " << maxHeap.top() << endl;
        }
        if(maxHeap.size() == minHeap.size()) {
            cout << (maxHeap.top() + minHeap.top()) / 2 << " ";
            // cout << "both have equal no of elements" << endl;

        } else if(maxHeap.size() - minHeap.size() == 1) {
            cout << maxHeap.top() << " ";
            // cout << "Maxheap has odd elements";

        } else {
            cout << minHeap.top() << " ";
        }
    }

    return 0;
}