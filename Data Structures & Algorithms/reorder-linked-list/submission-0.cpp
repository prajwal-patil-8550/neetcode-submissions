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
    void reorderList(ListNode* head) {
        //first clear the edge cases of 1 node and 2 node
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return;
        }
        // 1. find mid by slow fast pointer method
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* curr=slow->next;   // this would be the last node of the right side
        slow->next=NULL; // split the left side list of nodes by pointing last node of left to  to NULL
        // 2. reverse the right list of nodes
        ListNode* prev=NULL;
        ListNode* temp=curr->next;
    
        while(curr != NULL){
            curr->next=prev;
            prev=curr;
            curr=temp;
            temp=temp->next;
        }
        //our prev ptr would be the head of right list of nodes after reversing
        ListNode* left=head;
        ListNode* right=prev;
        ListNode* left_temp=left->next;
        ListNode* right_temp=right->next;
        while(right!=NULL){
            left->next=right;
            right->next=left_temp;
            left=left_temp;
            right=right_temp;
            left_temp=left->next;
            right_temp=right->next;
        }
        
    }
};
