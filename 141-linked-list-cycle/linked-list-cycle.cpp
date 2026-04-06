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
    bool hasCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr){
            return false;
        }


    ListNode* lower=head;
    ListNode* upper=head;
    while(upper!=nullptr && upper->next!=nullptr){
    lower=lower->next;
    upper=upper->next->next;
    if(lower== upper)
        return true;
    }
    return false;
        
    }
    
};