#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};
class Queue {
private:
    Node* front,* rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }
    bool isEmpty() {
        return front == nullptr;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot peek." << endl;
            return -1;
        }
        return front->data;
    }
};
int main() {
    
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Front element of queue: " << queue.peek() << endl;
    queue.dequeue();
    cout << "Front element after dequeueing: " << queue.peek() << endl;

    return 0;
}
