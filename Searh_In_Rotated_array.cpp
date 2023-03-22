#include<iostream>
#include<vector>
using namespace std;
int findPosition (vector <int> &arr, int k){
    int start = 0;
    int end = arr.size()-1;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(arr[mid]==k){
            return mid;
        }
        if (arr[start]<=arr[mid]){
            if(k>=arr[start] && k<arr[mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        else{
            if(k<=arr[end] && k>arr[mid]){
                start= mid+1;
            }
            else{
                end= mid-1;
            }
        }
    }
    return -1;
}
int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the target element to search: ";
    cin >> k;
    int result = findPosition(arr, k);
    if (result == -1) {
        cout << "Target element not found in the array." << endl;
    } else {
        cout << "Target element found at index " << result << "." << endl;
    }
    return 0;
}
