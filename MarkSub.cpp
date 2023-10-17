#include<iostream>
using namespace std;
int main(){

cout<<"provide number of students and their marks"<<endl;
int ns, sub;
cin>>ns>>sub;
int marks[ns][sub];
for(int i=0; i<ns; i++){
    cout<<"enter marks for student "<<i+1<<endl;
    int total=0;
    for(int j=0; j<sub; j++){
        cin>>marks[i][j];
        total+=marks[i][j];
    }
    cout<<"total marks of student "<<i+1<<" = "<<total<<endl;
}
for(int j=0; j<sub; j++){
int avg=0;
for(int i=0; i<ns; i++){
    avg+=marks[i][j];
}
cout<<"average in subject "<<j+1<<" = "<<(float)avg/ns<<endl;
}
return 0;
}