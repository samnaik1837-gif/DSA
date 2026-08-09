#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter your array size : "<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter your array elements : "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
/*
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }   
*/
for(int i=1;i<n;i++){
    int k=arr[i];
    int j;
    for(j=i-1;j>=0;j--){
        if(arr[j]>k){
            arr[j+1]=arr[j];
        }
        else{
            break;
        }
    } 
    arr[j+1]=k;
} 
/*
    for(int i=0;i<n;i++){
        int minimum = i;
        for(int j=i+1;j<n;j++){
                if(arr[j]<arr[minimum])
                minimum = j;
            }
            swap(arr[i],arr[minimum]);
        } 
*/
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
