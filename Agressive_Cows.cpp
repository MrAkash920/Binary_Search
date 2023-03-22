#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool canPlaceCows(vector <int> &stalls, int n, int k, int minDist){
    int cowPlaced =1;
    int lastPos =stalls[0];
    for(int i=0;i<n;i++){
        if(stalls[i]- lastPos>=minDist){
            cowPlaced++;
            lastPos=stalls[i];
        }
        if(cowPlaced==k){
            return true;
        }
    }
    return false;
}
int findMinMaxPos(vector <int> &stalls, int n, int k){
    sort(stalls.begin(),stalls.end());
    int s=1;
    int e=stalls[n-1]-stalls[0];
    int ans = -1;
    while(s<=e){
        int mid =s+(e-s)/2;
        if(canPlaceCows(stalls,n,k,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid= s+(e-s)/2;
    }
    return ans;
}
int main(){
    vector <int> stalls;
    int n;
    cin>>n;
    int k;
    cin>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        stalls.push_back(x);
    }
    cout<<findMinMaxPos(stalls,n,k)<<endl;
    return 0;
}