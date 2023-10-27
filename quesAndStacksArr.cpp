#include <iostream>
using namespace std;
// struct Node{int data;Node *link;public:Node(int value) : data(value), link(nullptr) {}};
// class stack{Node *top;public:stack() : top(nullptr) {}void push(int value){Node *temp = new Node(value);temp->link = top;top = temp;cout << temp->data << " is added on top of stack" << endl;}void pop(void){Node *topop = top;top = top->link;delete topop;}bool isEmpty() { return top == nullptr; }void peek(){if (top != nullptr)cout << top->data << endl;else cout << "empty" << endl;}};
// class queue{Node *head;Node *tail;public:queue() : tail(nullptr), head(nullptr) {}void enque(int value){Node *temp = new Node(value);if(!head){head=tail=temp;}else{tail->link = temp;tail = temp;}}void deque(){if(head==nullptr){cerr<<"queue is empty";}  Node *todel = head; head=head->link; delete todel;} bool isEmpty(){return tail==nullptr;} void peek(){if(head==nullptr){cout<<"que empty"<<endl;return; }else cout<<head->data<<endl;}};
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
        top--;
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
class queue{
    int q[SIZE];
    int head, tail;
    public:
    queue() : head(0), tail(-1){}
    void enque(int value){
        q[++tail]=value;
    }
    void deque(){
        if(head<=tail)
        head++;
        else cout<<"empty queue"<<endl;
    }
    void peek(){
        if(head<=tail and head!=-1)
        cout<<q[head]<<endl;
        else cout<<"Queue empty!"<<endl;
    }
    bool isEmpty(){
        return tail==0;
    }
};
int main()
{
    stack kit;
    cout << kit.isEmpty() << endl;
    kit.push(3);
    kit.push(2);
    kit.push(1);
    kit.peek();
    kit.pop();
    kit.peek();
    kit.pop();
    kit.peek();
    kit.pop();
    kit.pop();
    kit.peek();
    kit.push(24);
    kit.peek();
    
    queue tik;
    tik.peek();
    tik.enque(1);
    tik.enque(3);
    tik.enque(5);
    tik.peek();
    tik.deque();
    tik.peek();
    tik.deque();
    tik.peek();
    tik.deque();
    tik.peek();
    tik.deque();
    tik.deque();
    return 0;
}
