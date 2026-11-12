/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    void copyNodesInBetween(Node *head){
        Node *temp=head;
        while(temp!=NULL){
            Node *newNode = new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next; 
        }
    }

    void connectRandomPointer(Node *head){
        Node *temp=head;
        while(temp!=NULL){
            
            if(temp->random != NULL){
                temp->next->random=temp->random->next;
                temp=temp->next->next;
            }else{
                temp->next->random=NULL;
                temp=temp->next->next;
            }
        }
    }
    Node *connectNextPointer(Node *head){
        Node *temp=head;
        Node* dNode = new Node(-1);
        Node *res=dNode;
        while(temp!=NULL){
            res->next=temp->next;
            temp->next=temp->next->next;
            res=res->next;
            temp=temp->next;
        }
        return dNode->next;
    }
    Node* copyRandomList(Node* head) {
        copyNodesInBetween(head);
        connectRandomPointer(head);
        Node *nodeToReturn = connectNextPointer(head);
        return nodeToReturn;
    }
};
