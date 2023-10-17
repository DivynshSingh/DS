#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1,-1,23,3,-42,4,-77,-5,3,7,5,3,-45};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    int i=0, j=k-1;
    while(j<n){
        int mid=i;
        while(mid>=i && mid<=j){
            if(arr[mid]<0){cout<<arr[mid]<<' ';break;}
            else mid++;
        }
        i++, j++;
    }
return 0;
}