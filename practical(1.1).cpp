#include<iostream>
using namespace std;

int main(){
   
    int n,r,arr[58];


    cout<<"enter the number of bakery item: ";
    cin>>n;


    for(int i=0;i<n;i++){
        cout<<"enter the bakery items: ";3
        cin>>arr[i];
        
    }
    cout<<"enter the number of rotation: ";
    cin>>r;

    r=r%n;

    for(int j=0;j<r;j++)
    {
        int first=arr[0];

        for(int i=0;i<n-1;i++){
            arr[i]=arr[i+1];
        }
        arr[n-1]=first;
    }
    cout<<"Items after trotation: ";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;


}