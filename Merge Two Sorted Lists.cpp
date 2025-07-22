// Merge Two Sorted Lists

/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
*/

class Solution{
// min heap solution 
    public:
        bool operator()(ListNode* a, ListNode* b){
            return a->val>b->val;
        }
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            vector<ListNode*> v;
            v.push_back(list1);
            v.push_back(list2);
            priority_queue<ListNode*,vector<ListNode*>,Solution> pq;
            int k=v.size();
            if(k==0){
                return NULL;
            }
            for(int i=0;i<k;i++){
                if(v[i]!=NULL){
                    pq.push(v[i]);
                }
            }
            ListNode*head=NULL;
            ListNode*tail=NULL;
            while(pq.size()>0){
                ListNode* top=pq.top();
                pq.pop();
                if(top->next!=NULL){
                    pq.push(top->next);
                }
                if(head==NULL){
                    head=top;
                    tail=top;
                }
              

            
                else{
                    tail->next=top;
                    tail=top;
                    
                }
            }
            return head;

        }
};

/*
merge sort approach
class Solution {
  
    ListNode* merging(ListNode*list1,ListNode*list2){
        ListNode*prev=list1;
        ListNode* temp=list2;
       
        
        
 
        
        ListNode*curr=prev->next;
        while(curr!=NULL&&temp!=NULL){
            if(temp->val<=curr->val && temp->val>=prev->val){
                
                prev->next=temp;
                ListNode* next2 = temp->next;
                temp->next=curr;
                prev=temp;
                temp=next2;
            }
            else{
                prev=curr;
                curr=curr->next;
                if(curr==NULL){
                    prev->next=temp;
                    return list1;
                }
            }   

        }
        return list1;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*prev=list1;
        ListNode* temp=list2;
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        if(list1->val>=list2->val){
           
            return (merging(list2,list1));

        }
        
        
        return merging(list1,list2);
        
 
    }
}; 
*/
