#include <iostream>
using namespace std;
int linearSearch(int arr[], int size, int target){
    for(int i = 0; i < size; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[]={1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size=sizeof(arr) / sizeof(arr[0]);
    int target;
    cout<<"Enter element to find :";
    cin>>target;
    int result=linearSearch(arr, size, target);

    if (result != -1){
        cout << "Element found at index " << result << std::endl;
    }
    else{
        cout << "Element not found" << std::endl;
    }
    return 0;
}
