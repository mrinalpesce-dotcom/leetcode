class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0)
            return head;

        // Step 1: find length
        ListNode* temp = head;
        int n = 1;
        while(temp->next != NULL){
            temp = temp->next;
            n++;
        }

        // Step 2: make circular list
        temp->next = head;

        // Step 3: reduce k
        k = k % n;
        int steps = n - k;

        // Step 4: find new tail
        ListNode* newTail = head;
        for(int i = 1; i < steps; i++)
            newTail = newTail->next;

        // Step 5: break circle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};