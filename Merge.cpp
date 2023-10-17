#include <iostream>

struct Node {
    int data;
    Node* next;
};

void insert(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr || head->data >= value) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

Node* mergeListsSorted(Node* list1, Node* list2) {
    Node* mergedList = nullptr;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data < list2->data) {
            insert(mergedList, list1->data);
            list1 = list1->next;
        } else {
            insert(mergedList, list2->data);
            list2 = list2->next;
        }
    }

    while (list1 != nullptr) {
        insert(mergedList, list1->data);
        list1 = list1->next;
    }

    while (list2 != nullptr) {
        insert(mergedList, list2->data);
        list2 = list2->next;
    }

    return mergedList;
}

void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    insert(list1, 1);
    insert(list1, 3);
    insert(list1, 5);

    insert(list2, 2);
    insert(list2, 4);
    insert(list2, 6);

    Node* mergedList = mergeListsSorted(list1, list2);

    displayList(mergedList);

    return 0;
}