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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp=head;
        for(int i=0; i<n; i++){
            temp=temp->next;
        }
        ListNode* fast=temp;
        ListNode* slow=head;

        if(fast==NULL){
            //edge case where n=length of node list
            ListNode *delNode=head;
            head=head->next;
            delNode->next=NULL;
            delete delNode;
            return head;
        }

        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        
        ListNode *delNode=slow->next;
        slow->next=delNode->next;
        delNode->next=NULL;
        delete delNode;
        return head;
    }
};
