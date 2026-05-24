class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head == nullptr || k == 1){
            return head;
        }

        vector<int> ans;

        ListNode* temp = head;

        while(temp != nullptr){
            ans.push_back(temp->val);
            temp = temp->next;
        }

        int n = ans.size();

        for(int i = 0; i + k <= n; i += k){
            reverse(ans.begin() + i,
                    ans.begin() + i + k);
        }

        temp = head;
        int idx = 0;

        while(temp != nullptr){
            temp->val = ans[idx++];
            temp = temp->next;
        }

        return head;
    }
};