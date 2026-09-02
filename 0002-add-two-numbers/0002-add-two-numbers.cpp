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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int headVal = l1->val + l2->val;
        ListNode* head = new ListNode(headVal%10);
        ListNode* mover = head;
        ListNode* temp1 = l1->next;
        ListNode* temp2 = l2->next;
        int carry = headVal >=10 ? 1 : 0;

        while(temp1 != NULL && temp2 != NULL){
            int value = carry + temp1->val + temp2->val;
            ListNode* newNode = new ListNode(value%10);
            carry = value/10;
            mover->next = newNode;
            mover = newNode;
            if(temp1) temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;
        }
        while(temp1 != NULL){
            int value = carry + temp1->val;
            ListNode* newNode = new ListNode(value%10);
            carry = value/10;
            mover->next = newNode;
            mover = newNode;
            if(temp1) temp1 = temp1->next;
        }
        while(temp2 != NULL){
            int value = carry + temp2->val;
            ListNode* newNode = new ListNode(value%10);
            carry = value/10;
            mover->next = newNode;
            mover = newNode;
            if(temp2) temp2 = temp2->next;
        }
        if(carry) {
            ListNode* temp = new ListNode(1);
            mover->next = temp;
            mover = temp;
        }

        return head;
    } 
};