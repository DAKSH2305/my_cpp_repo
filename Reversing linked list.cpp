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

// Approach - 1 iterative 

class Solution {
   
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*forward=NULL;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;

        }
        return prev;
    }


// Approach 2 Recursive approach

class Solution {
    ListNode* reversing(ListNode*&head){
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* shortnode=reversing(head->next);
        head->next->next=head;
        head->next=NULL;
        return shortnode;

    }
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode*curr=head;
        return reversing(head);
    }
   
};
