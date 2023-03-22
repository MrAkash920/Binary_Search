#include <iostream>
#include <vector>
using namespace std;
int findPivot(vector <int> &arr){
    int s = 0;
    int e = arr.size()-1;
    int mid = s+(e-s)/2;
    while(s<=e){
        if(arr[mid]>=arr[0]){
            s= mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
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
    cout<<"Pivot element in this array is: "<<findPivot<<endl;
    return 0;
}