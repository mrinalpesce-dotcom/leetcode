class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // create dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        // move fast n steps ahead
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }
        
        // if fast is NULL → delete head
        if(fast == nullptr){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        
        // move both pointers
        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        
        // delete node
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        
        return dummy->next;
    }
};