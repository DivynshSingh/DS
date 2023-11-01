#include <iostream>
#include <stack>
using namespace std;
class ListNode {
public:
    int value;
    ListNode* next;

    ListNode(int val) : value(val), next(nullptr) {}
};

bool isPalindrome(ListNode* head) {
 if (!head || !head->next) {
     return true;
 }

 std::stack<int> first_half;
 ListNode* slow = head;
 ListNode* fast = head;

 while (fast && fast->next) {
     first_half.push(slow->value);
     slow = slow->next;
     fast = fast->next->next;
 }

 if (fast) {
     slow = slow->next;
 }

 while (slow) {
     if (slow->value != first_half.top()) {
         return false;
     }
     slow = slow->next;
     first_half.pop();
 }
 return true;
}

int main() {
 ListNode* head = new ListNode(1);
 head->next = new ListNode(2);
 head->next->next = new ListNode(3);
 head->next->next->next = new ListNode(2);
 head->next->next->next->next = new ListNode(1);

 bool result = isPalindrome(head);
 if (result) {
     cout << "Linked list is a palindrome" << endl;
 } else {
     cout << "Linked list is not a palindrome" << endl;
 }

 while (head) {
     ListNode* temp = head;
     head = head->next;
     delete temp;
 }

 return 0;
}
