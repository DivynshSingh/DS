#include <iostream>
using namespace std;
// struct Node{int dat *tail;public:queue() : tail(nullptr), head(nullptr) {}void enque(int value){Node *temp = new Node(value);if(!head){head=tail=temp;}else{tail->link = temp;tail = temp;}}void deque(){if(head==nullptr){cerr<<"queue is empty";}  Node *todel = head; head=head->link; delete todel;} bool isEmpty(){return tail==nullptr;} void peek(){if(head==nullptr){cout<<"que empty"<<endl;return; }else cout<<head->data<<endl;}};
#define SIZE 100
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
        {head++;
        cout<<"dequed!"<<endl;
        }
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
    queue tik;
    cout<<"element at beginning: ";tik.peek();
    tik.enque(1);
    tik.enque(3);
    tik.enque(5);
    cout<<"element at beginning: ";tik.peek();
    tik.deque();
    cout<<"element at beginning: ";tik.peek();
    tik.deque();
    cout<<"element at beginning: ";tik.peek();
    tik.deque();
    cout<<"element at beginning: ";tik.peek();
    tik.deque();
    tik.deque();
    return 0;
}
