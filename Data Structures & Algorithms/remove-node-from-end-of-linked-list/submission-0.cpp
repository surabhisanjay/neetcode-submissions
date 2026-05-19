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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* curr = head;
        while(curr != nullptr){
            length++;
            curr = curr->next;
        }
        int num = length - n;
        int i = 1;
        ListNode* prev = nullptr;
        curr = head;
        if(n == length){
            return head->next;
        }
        while(i < num){
            curr = curr->next;
            i++;
        }
        curr->next = curr->next->next;
        return head;
    }
};
