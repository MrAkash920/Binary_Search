#include<iostream>
#include<vector>
using namespace std;
bool isPossible(vector<int>& arr, int n, int k, int mid) {
    int painterCount = 1;
    int unitSum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > mid) {
            return false;
        }
        if (unitSum + arr[i] <= mid) {
            unitSum += arr[i];
        } else {
            painterCount++;
            if (painterCount > k) {
                return false;
            }
            unitSum = arr[i];
        }
    }
    return true;
}

int painterPartition(vector <int> &arr, int n, int k){
    int s=0;
    int sum =0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int e=sum;
    int ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(isPossible(arr,n,k,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}
int main(){
    vector <int> arr;
    int n;
    cin>>n;
    int k;
    cin>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<painterPartition(arr,n,k)<<endl;
    return 0;
}