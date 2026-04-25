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
        ListNode*p=head;
        for(int i=0;i<n;i++){
            if(p) p=p->next;
            else return head;
        }

        //Remove first Node
        if(p==NULL){
            ListNode* start=head->next;
            head->next=NULL;
            delete head;
            return start;
        }

        ListNode* prevNodeToBeDeleted=head;
        while(p->next!=NULL){
            prevNodeToBeDeleted=prevNodeToBeDeleted->next;
            p=p->next;
        }

        ListNode* nodeToBeDeleted=prevNodeToBeDeleted->next;
        prevNodeToBeDeleted->next = nodeToBeDeleted->next;
        nodeToBeDeleted->next=NULL;
        delete nodeToBeDeleted;

        return head;

    }
};
