//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
//Binary Search approach
#include<iostream>
using namespace std;
int firstOccurence(int arr[], int size, int target){
    int start = 0;
    int end = size-1;
    int ans = -1;
    int mid = start+(end-start)/2;
    while(start<=end){
        if(arr[mid]==target){
            ans = mid;
            end = mid-1;
        }
        else if(target<= arr[mid]){
            end = mid-1;
        }
        else {
            start= mid+1;
        }
        mid = start+(end-start); 
    }
    return ans;
}
int lastOccurence(int arr[], int size, int target){
    int start = 0;
    int end = size-1;
    int ans = -1;
    int mid = start+(end-start)/2;
    while(start<=end){
        if(arr[mid]==target){
            ans = mid;
            start = mid+1;
        }
        else if(target<= arr[mid]){
            end = mid-1;
        }
        else {
            start= mid+1;
        }
        mid = start+(end-start); 
    }
    return ans;
}
int main(){
    int a[7] = {2, 4, 7, 7, 7, 12, 14};
    cout<<"First occurnce of 7 at index: "<<firstOccurence(a,7,7)<<endl;
    cout<<"Last occurnce of 7 at index: "<<lastOccurence(a,7,7)<<endl;
}
