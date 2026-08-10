#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter your number of buckets : "<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter your colour coad(0,1,2) : "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int low=0;
    int mid=0;
    int high=n-1;

    while (mid<=high)
    {
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
