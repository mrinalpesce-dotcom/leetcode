/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        // Edge case
        if(head == NULL || head->next == NULL)
            return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        // 🟢 Phase 1: Detect if cycle exists
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;          // 1 step
            fast = fast->next->next;    // 2 steps

            if(slow == fast){           // Cycle detected
                
                // 🔴 Phase 2: Find start of cycle
                ListNode* ptr = head;
                while(ptr != slow){
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;  // Start of cycle
            }
        }

        // No cycle present
        return NULL;
    }
};