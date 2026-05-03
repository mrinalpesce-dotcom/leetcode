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

    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        // vector use to stored the vale of linkedlist
        vector<int> arr;

         // temp use to point the vector 
        ListNode* temp=head;


        while(temp!=nullptr){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        sort(arr.begin(),arr.end());

        temp = head;
        for( int i=0;i<arr.size();i++){
            temp->val=arr[i];
            temp=temp->next;
        }
        return head;

    }
};