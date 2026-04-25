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
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;

        unordered_map<Node*,Node*>m;
        Node*p=head;
        while(p){
            Node* newNode=new Node(p->val);
            m[p]=newNode;
            p=p->next;
        }

        p=head;
        while(p){
            m[p]->next= m[p->next];
            m[p]->random=m[p->random];

            p=p->next;
        }

        return m[head];
    }
};
