#include<iostream>
using namespace std;

void heapify(int arr[], int size, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest]) largest = left;
    if (right < size && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size){
    for(int i = size / 2 - 1; i >= 0; i--) heapify(arr, size, i);

    for(int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]); //swap is inbuilt
        heapify(arr, i, 0);
    }
}

void show(int arr[], int size){
for(int i=0; i<size; i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
}
int main(){
int arr[]={12,11,10,9,3,4,5,6,7,8,-0};
int size=sizeof(arr)/sizeof(arr[0]);
show(arr, size);
heapSort(arr, size);
show(arr, size);
return 0;
}