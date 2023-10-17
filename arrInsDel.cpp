#include<iostream>
using namespace std;
void operate(int arr[], int &size, int ins, int del, int data){
if(ins==-1){
    for(int i=del; i<size-1; i++){
        arr[i]=arr[i+1];
    }
    size--;
    return;
}
else if(del==-1){
    cout<<"insertion not possible"<<endl;
    return;
}
else{
    if(ins==del){
        arr[del]=data;
    }
    else if(ins > del){
        for(int i=del; i<ins; i++){
            arr[i]=arr[i+1];
        }
        arr[ins]=data;
    }
    else if(ins < del){
        for(int i=del; i>ins; i--){
            arr[i]=arr[i-1];
        }
        arr[ins]=data;
    }
    return;
}
}

void show(int arr[]){
    for(int i=0; i<10; i++){
        cout <<arr[i]<<" ";
    }
}
int main(){
int arr[10]={0,1,2,3,4,5,6,7,8,9};
show(arr);
int size=10;
int ins, del;
cout<<"enter positions for insertin, deletion and data, if operation is not to be performed enter -1"<<endl;
int data;
cin>>ins>>del>>data;
operate(arr, size, ins-1, del-1, data);
show(arr);
return 0;
}