#include <iostream>
#include <vector>
using namespace std;
int findPeakIndexMountain (vector <int> &arr){
    int start = 0;
    int end = arr.size()-1;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(arr[mid]< arr[mid+1]){
            start= mid+1;
        }
        else if(arr[mid]< arr[mid-1]){
            end= mid-1;
        }
        else {
            return mid;
        }
    }
    return start;
}
int main(){
    vector <int> arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<"The peak index is : "<<findPeakIndexMountain<<endl;
    return 0;
}