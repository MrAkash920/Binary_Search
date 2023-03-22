#include<iostream>
#include<vector>
using namespace std;

int findPivot(vector<int>& arr, int n) {
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s <= e) {
        if (arr[mid] >= arr[0]) {
            s = mid + 1;
        }
        else {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int binarySearch(vector<int>& arr, int s, int e, int key) {
    int start=s;
    int end=e;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (key > arr[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return -1;
}

int findPosition(vector<int>& arr, int key) {
    int pivot = findPivot(arr);
    int n = arr.size();
    if (key >= arr[pivot] && key <= arr[n - 1]) {
        return binarySearch(arr, pivot, n - 1, key);
    }
    else {
        return binarySearch(arr, 0, pivot - 1, key);
    }
}

int main(){
    vector <int> arr ;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int key;
    cin>>key;
    cout<<findPosition(arr, key)<<endl;
    return 0;
}
