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
    bool hasCycle(ListNode* head) {
        if(head == nullptr) return false;
        ListNode* fastPointer = head;
        if(fastPointer->next == nullptr) return false;
        else {fastPointer = fastPointer->next;}
        ListNode* slowPointer = head;

        while(fastPointer != slowPointer)
        {
            if(fastPointer->next != nullptr)fastPointer = fastPointer->next;
            else {return false;}
            if(fastPointer->next != nullptr)fastPointer = fastPointer->next;
            else {return false;}
            slowPointer = slowPointer->next;
        }
        return true;
    }
};
