#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

Node* findMergePoint(Node* list1, Node* list2) {
    int len1 = 0, len2 = 0;
    Node* temp1 = list1, * temp2 = list2;
    while (temp1) { len1++; temp1 = temp1->next; }
    while (temp2) { len2++; temp2 = temp2->next; }
    temp1 = list1;
    temp2 = list2;
    if (len1 > len2)
        for (int i = 0; i < len1 - len2; i++) temp1 = temp1->next;
    else
        for (int i = 0; i < len2 - len1; i++) temp2 = temp2->next;
    while (temp1 && temp2) {
        if (temp1 == temp2) return temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return nullptr;
}
void append(Node* head, int value){
    Node*it=head;
    while(it->next!=nullptr){
        it=it->next;
    }
    it->next=new Node(value);
}
void show(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main(){
Node* head1 = new Node(1);
Node* head2 = new Node(2);

Node* sharedNode1 = new Node(3);

append(head1, 5);
append(head1, 6);
append(head1, 7);

append(head2, 8);
append(head2, 9);

show(head1);
show(head2);
head1->next->next->next = sharedNode1;
head2->next = sharedNode1;
show(head1);
show(head2);
Node* mergePoint = findMergePoint(head1, head2);

if (mergePoint) {
cout << "Merge point data: " << mergePoint->data <<endl;
} else {
cout << "Linked lists do not merge." <<endl;
}

delete head1;
delete head2;

return 0;
}