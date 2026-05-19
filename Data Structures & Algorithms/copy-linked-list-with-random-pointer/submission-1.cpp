/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> ele_index;
        Node* curr = head;
        while(curr!= nullptr){
            ele_index[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr= head;
        while(curr!= nullptr){
            ele_index[curr]->next = ele_index[curr->next];
            ele_index[curr]->random = ele_index[curr->random];
            curr = curr->next;
        }
        return ele_index[head];
    }
};
