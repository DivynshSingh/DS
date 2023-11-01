#include<iostream>
using namespace std;
void insertionSort(int arr[], int size){
for (int i = 1; i < size; i++) {
 int key = arr[i];
 int j = i - 1;
 
 while (j >= 0 && arr[j] > key) {
     arr[j + 1] = arr[j];
     j--;
 }
 
 arr[j + 1] = key;
}
}
void show(int arr[], int size){
for(int i=0; i<size; i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
}
int main(){
int arr[]={9,8,7,6,5,18,4,3,2,1};
int size=sizeof(arr)/sizeof(arr[0]);
show(arr, size);
insertionSort(arr, size);
show(arr, size);
return 0;
}