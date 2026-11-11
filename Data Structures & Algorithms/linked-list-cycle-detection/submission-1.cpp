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
        // unordered_map<ListNode*, int>mp;
        // ListNode* temp=head;

        // while(temp != NULL){
        //     if(mp.find(temp) != mp.end()){
        //         //if same node mil jaaye toh loop exists
        //         return true;
        //     }
        //     mp[temp]=1;
        //     temp=temp->next;
        // }
        // return false;

         /*tortoise and hare algo*/
        ListNode* slow=head;//will move by 1 step
        ListNode* fast=head;// will move by 2 steps
        //always check if fast itself is null or not cuz if we check fast->next is null or not      before checking fast itself is null or not it will cause runtime error
        while(fast!=NULL /*in EVEN node condition*/ && fast->next!=NULL/*in ODD node condition*/ ){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                return true;
            }
        }
        return false;
    }
};
