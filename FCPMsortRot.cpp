#include<iostream>
using namespace std;

int floor(int arr[], int size, int x) {
    int floorValue = -1;

    for(int i = 0; i < size; i++) {
        if(arr[i] <= x && arr[i] > floorValue){
            floorValue = arr[i];
        }
    }
    return floorValue;
}

int ceil(int arr[], int size, int x) {
    int ceilValue=INT_MAX;
    for(int i = 0; i < size; i++){
        if(arr[i] >= x && arr[i] < ceilValue){
            ceilValue=arr[i];
        }
    }
    return ceilValue;
}

int peak(int arr[], int size){
    for(int i=0; i<size-1; i++){
        if(arr[i]>arr[i+1])return i;
    }
    return -1;
}

int main(){
int arr[]={10, 12, 16, 19, 3, 4, 6, 8};
int size=sizeof(arr)/sizeof(arr[0]);
int x;

cout<<"find floor of: ";
cin>>x;
cout<<floor(arr, size, x)<<endl;

cout<<"find ceil of: ";
cin>>x;
cout<<ceil(arr, size, x)<<endl;

cout << "the maximum element is: "<<arr[peak(arr, size)]<<endl; //there is the only one peak, which would be the max element of array
    
cout << "the minimum element is: "<<arr[peak(arr, size)+1]<<endl;
return 0;
}
