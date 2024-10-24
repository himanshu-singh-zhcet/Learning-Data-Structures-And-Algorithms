class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL or head->next == NULL or head->next->next==NULL){
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!= NULL and fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* curr = slow->next;
        ListNode* prev = slow;
        slow->next= NULL;
        while(curr){
            ListNode* next = curr->next;
            curr->next=prev;
            prev= curr;
            curr=next;
        }
    ListNode* head1 = head;  // LINKEDLIST FOR FIRST HALF
    ListNode* head2 = prev;  // LINKEDLIST FOR SECOND HALF
    while(head1 != head2){
        ListNode* temp = head1->next; 
        head1->next = head2;
        head1 = head2;
        head2 = temp;
    }

    }
    
};