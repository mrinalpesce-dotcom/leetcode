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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==nullptr || head->next==nullptr){
            return head;
        }

        vector<int> ans;

        ListNode* temp=head;
        

        while(temp!=nullptr){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        int n=ans.size();
         k=k%n;
            rotate(ans.begin(),ans.end()-k ,ans.end());

        
       temp=head;
       int i=0;
       while(temp!=nullptr){
        temp->val=ans[i++];
        temp=temp->next;
       }
       return head;



    
    }
};