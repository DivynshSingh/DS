#include <iostream>
using namespace std;
int partition_array(int input[], int start, int end) {
    int pivot=input[start];
    int count=0;
    for (int i=start+1; i<=end; i++) {
        if (input[i]<=pivot) {
            count++;
        }
    }
    int pivot_index=start + count;
    int temp=input[start];
    input[start]=input[pivot_index];
    input[pivot_index]=temp;
    int i = start, j=end;
    while (i<=pivot_index && j>=pivot_index) {
        while (i<=pivot_index && input[i]<=pivot) {
            i++;
        }
        while (j>=pivot_index && input[j]>pivot) {
            j--;
        }
        if (i<pivot_index && j>pivot_index) {
            temp=input[i];
            input[i]=input[j];
            input[j]=temp;
            i++;
            j--;
        }
    }
    return pivot_index;
}
void quick_sort(int input[], int start, int end) {
    if(start>=end){
        return;
    }
    int pivot_index = partition_array(input, start, end);
    quick_sort(input, start, pivot_index - 1);
    quick_sort(input, pivot_index + 1, end);
}
void show(int arr[], int size){
for(int i=0; i<size; i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
}
int main() {
    int arr[] = {0,9,8,7,6,5,4,3,786,2,1,42};
    int size = sizeof(arr)/sizeof(arr[0]);
    show(arr,size);
    quick_sort(arr, 0, size - 1);
    show(arr,size);
return 0;
}
