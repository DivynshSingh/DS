#include<iostream>
using namespace std;
void swap(int &a, int &b){
    int c=b;
    b=a;
    a=c;
}
void bubblesort(int arr[], int size){
bool unsorted=1;
while(unsorted){
unsorted=0;
for(int i=0; i<size-1; i++){
    if(arr[i]>arr[i+1]){
        swap(arr[i], arr[i+1]);
        unsorted=1;
        }
}
}
}
void show(int arr[], int size){
for(int i=0; i<size; i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
}
int main(){
int arr[]={14,15,1,5,4,6,37,3,4,7,4,8};
int size=sizeof(arr)/sizeof(arr[0]);
show(arr, size);
bubblesort(arr, size);
show(arr, size);
return 0;
}