#include<iostream>
using namespace std;
int min(int arr[], int size, int position){
int min=position;
    for(int i=position; i<size; i++){
        if(arr[i] < arr[min])min=i;
    }
return min;
}
void swap(int &a, int &b){
    int c=b;
    b=a;
    a=c;
}
void show(int arr[], int size){
for(int i=0; i<size; i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
}
void selectionsort(int arr[], int size){
for(int i=0; i<size-1; i++){
    int toReplace=min(arr, size, i+1);
    if(arr[i]>arr[toReplace])swap(arr[i], arr[toReplace]);
}
}
int main(){
int arr[]={9,8,7,6,10,5,4,3,2,1};
int size=sizeof(arr)/sizeof(arr[0]);
show(arr,size);
selectionsort(arr, size);
show(arr,size);
return 0;
}