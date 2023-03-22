#include<iostream>
using namespace std;
int mySqrt(int x){
    int s=0;
    int e=x;
    int mid = s+(e-s)/2;
    int ans= -1;
    while(s<=e){
        int square = mid*mid;
        if(square==x){
            return mid;
        }
        else if(square>x){
            e= mid-1;
        }
        else{
            ans=mid;
            s=mid+1;
        }
        mid =s+(e-s)/2;
    }
    return ans;
}

int main(){
    int x;
    cin>>x;
    cout<<"Square root of"<<x<<"is: "<<mySqrt(x)<<endl;
}