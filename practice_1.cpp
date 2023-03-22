#include<iostream>
using namespace std;
int searchInsertposition ( int arr[], int n, int k){
    int s=0;
    int e=n-1;
    int mid = s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==k){    
            return mid ;
        }
        if(k>arr[mid]){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid = s+(e-s)/2;
    }
    return mid;
}
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int index = searchInsertposition(arr, n, k) ;
    cout<<"Index is:"<<index<<endl;
}