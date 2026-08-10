#include<iostream>
using namespace std;

int main()
{
    int arr[50];
    int n,i;
    int counts[50];


    cout<<"Enter the number of Books";
    cin>>n;

    for(i=0;i<n;i++){
    cout<<"Enter the Book ID "<<i+1<<endl;
    cin>>arr[i];
}

for(i=0;i<n;i++){
    cout<<"how many time book number "<<i+1<<" is borrowed "<<endl;
    cin>>counts[i];
}

for(i=0;i<n;i++){
    if(counts[i]>1){
        cout<<"The book which is borrowed more than once are "<<arr[i]<<endl;
    }
}


}