#include<iostream>
using namespace std;
void InsAtBeg(int arr[], int data, int size, int &len){
if(size==len)arr[0]=data;
else if(size>len){
    for(int i=len-1; i>0; i--){
        arr[i]=arr[i-1];
}
    arr[0]=data;
len++;
}
}
void DelAtBeg(int arr[], int &len){
for(int i=0; i<len-1; i++){
    arr[i]=arr[i+1];
}
len--;
}
void show(int arr[] ,int size){
for(int i=0; i<size; i++){
    std::cout<<arr[i]<<" ";
}
cout<<endl;
}
int main(){
int arr[]={1,2,4,5,6,7,8};
const int size=sizeof(arr)/sizeof(arr[0]);
int len=size;
InsAtBeg(arr, 86, size, len);
show(arr, len);
DelAtBeg(arr, len);
show(arr, len);
InsAtBeg(arr, 1, size, len);
show(arr, len);
return 0;
}