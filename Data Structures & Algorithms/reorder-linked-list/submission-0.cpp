/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* middleElement(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!= nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast-> next-> next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* Next;
        ListNode* curr = head;
        while(curr!= nullptr){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* head2 = reverseList(middleElement(head));
        ListNode* curr1 = head;
        ListNode* curr2 = head2;
        while(curr1 != nullptr && curr2 != nullptr && curr1 != curr2 && curr1->next != curr2){
            ListNode* next1 = curr1->next;
            ListNode* next2 = curr2->next;

            curr1->next = curr2;
            curr2->next = next1;
            curr2 = next2;
            curr1 = next1;
            
        }
    }
};
