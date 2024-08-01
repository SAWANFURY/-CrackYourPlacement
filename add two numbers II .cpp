class Solution {
public:
    ListNode * rev(ListNode * head){
        ListNode * prev = NULL;
        ListNode * curr = head;
        ListNode * forward = NULL;
        while(curr!=NULL){
            forward = curr->next;
            curr->next = prev;
            prev=curr;  
            curr = forward;
        }
        return prev; 
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       l1= rev(l1);
       l2= rev(l2);
        ListNode * dummy = new ListNode(0);
        ListNode * current = dummy;
         int carry = 0;
         while(l1!=NULL || l2!=NULL || carry!=0){
            int sum = carry;
            if(l1!=NULL){
                sum += l1->val;
                l1 = l1 ->next;
            }
            if(l2!=NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum/10;
            current->next = new ListNode(sum%10);
            current = current->next;
         }
         return rev(dummy->next);
    }
};