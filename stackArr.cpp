#include <iostream>
using namespace std;
#define SIZE 100
class stack{
    int stk[SIZE];
    int top;
    public:
    stack() : top(-1){}
    void push(int value){
        if(top<SIZE){
        stk[++top]=value;}
        else cout<<"stack full!"<<endl;
    }
    void pop(){
        if(top>=0)
        {top--;
        cout<<"element popped! "<<endl;}
        else cout<<"stack empty!"<<endl;
    }
    bool isEmpty(){
        return top==-1;
    }
    void peek(){
        if(top>=0)
        cout<<stk[top]<<endl;
        else cout<<"empty stack"<<endl;
    }
};
int main()
{
    stack kit;
    cout << kit.isEmpty() << endl;
    kit.push(3);
    kit.push(2);
    kit.push(1);
    cout<<"element on top: ";kit.peek();
    kit.pop();
    cout<<"element on top: ";kit.peek();
    kit.pop();
    cout<<"element on top: ";kit.peek();
    kit.pop();
    kit.pop();
    cout<<"element on top: ";kit.peek();
    kit.push(24);
    cout<<"element on top: ";kit.peek();
return 0;
}