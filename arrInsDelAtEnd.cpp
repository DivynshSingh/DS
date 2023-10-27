#include<iostream>
using namespace std;
void InsAtEnd(int arr[], int newData, int size){
arr[size-1]=newData;
}
void DelAtEnd(int arr[], int &size){
size--;
}
void show(int arr[] ,int size){
for(int i=0; i<size; i++){
    std::cout<<arr[i]<<" ";
}
cout<<endl;
}
int main(){
int array[4]={1,24,6,4};
int size=sizeof(array)/sizeof(array[0]);
InsAtEnd(array, 5, size);
show(array, size);
DelAtEnd(array, size);
show(array, size);
return 0;
}