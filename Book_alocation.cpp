#include <iostream>
#include <vector>
using namespace std;
bool isPossible(vector <int> &arr, int n,int m, int mid){
    int student = 1;
    int pageSum = 0;
    for(int i=0;i<n;i++){
        if(pageSum+arr[i]<=mid){
            pageSum+=arr[i];
        }
        else{
            student++;
            if(student>m || arr[i]>mid){
                return false;
            }
            pageSum+=arr[i];
        }
    }
    return true;
}
int bookAlocatin(vector <int> &arr, int n, int m){
    int s=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int e =sum;
    int ans =-1;
    int mid = s+(e-s)/2;
    while(s<=e){
        if(isPossible(arr,n,m,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int main(){
    vector <int> arr;
    int n;
    cin>>n;
    int m;
    cin>>m;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<bookAlocatin(arr,n,m)<<endl;
    return 0;
}