#include<iostream>
#include<string>
bool palindrome(std::string check){
int j=check.size()-1, i=0;
while(i<=j){
    if(check[i]!=check[j])return false;
    else {i++; j--;}
}
return true;
}
int main(){
std::string word;
std::cin>>word;
std::cout<<palindrome(word);
return 0;
}