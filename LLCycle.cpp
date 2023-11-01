#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

bool hasCycle(Node* head) {
    Node* slow = head, * fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true; // cycle exists
        }
    }
    return false; // cycle not found
}

void removeCycle(Node* head) {
    Node* slow = head, * fast = head;
    Node* prev = nullptr;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    if (!fast || !fast->next) {
        return; // cycle not found
    }
    slow = head;
    while (slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = nullptr; // cycle removed
}
void show(Node* head){
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third; // makes a cycle
    // show(head);
    if (hasCycle(head)) {
        cout << "Linked list has a cycle." <<endl;
        removeCycle(head);
        cout << "Cycle removed." <<endl;
    } else {
        cout << "Linked list has no cycle." << endl;
    }
    show(head);

    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}
