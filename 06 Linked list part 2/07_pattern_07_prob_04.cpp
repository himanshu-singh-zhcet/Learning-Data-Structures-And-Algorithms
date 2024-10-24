class Solution {
public:
    ListNode* swapPairshelper(ListNode* head){
        // basecase
        if(head==NULL or head->next == NULL){
            return head;
        }
        // recursive case 
        ListNode* second_node = head->next;
        head->next = swapPairshelper(second_node->next);
        second_node->next = head;   //reversing the linkedlist between first and second node 
        return second_node;


    }
    ListNode* swapPairs(ListNode* head) {
        return swapPairshelper(head);
    }
};